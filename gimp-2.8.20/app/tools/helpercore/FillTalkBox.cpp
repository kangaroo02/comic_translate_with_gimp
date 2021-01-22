/*
 * FillTalkBox.cpp

 *
 *
 *  Created on: 2018 M08 24
 *      Author: Isaiah Yang
 */


#include "FillTalkBox.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "Find_path.cpp"


Point FillTalkBox::activated_point = Point(-1, -1); //for mouse's usage
Vec3b FillTalkBox::cover = Vec3b(255, 0, 0); //the default color is blue, and it will be changed automatically
uchar FillTalkBox::fillValue = 70;

string Get_bounded_box_coordinate(Mat src);

FillTalkBox::FillTalkBox(string input) {
	
	//changes name from Ctype to C++type
	findAndReplaceAll(input, "%20", " ");
	findAndReplaceAll(input, "file://", "");
	
	//Load the image
	original = imread(input);

	//Check if everything was fine
	if (!original.data) {
		exit(1);
	}
	//Show original image
	//imshow("【Original】", original);

}

int FillTalkBox::talk_box_detect(int x, int y) {

	//mouse
	setMouseCallback("【Original】", onMouse, NULL);
	activated_point.x = x;
	activated_point.y = y;

	while (true) {
		//do nothing when mouse doesn't down
		if (activated_point.x == -1 && activated_point.y == -1) {
			//imshow("【Original】", original);
		}


		if(x>original.cols or x<0 or y>original.rows or y<0){
			activated_point.x = -1;
			activated_point.y = -1;
			return -1;
		}


		//doing jobs
		if (activated_point.x != -1 && activated_point.y != -1) {
			//stpe 0. find the cover color
			detect_cover(activated_point.x, activated_point.y);

			//step 1. floodfill
			Mat floodfill_mask = cih_floodfill(original);

			//step 2. extract
			Mat extraction = chi_extract(floodfill_mask);

			//step 3. inverse floodfill
			Mat inverse_floodfill_mask = chi_inverse_floodfill(extraction);

			//step 4. extract again
			Mat inverse_extraction = chi_inverse_extract(inverse_floodfill_mask);

			//step 5. remove the border
			Mat removed_border_mask = chi_remove_3border(inverse_extraction);

			//step 6. add the mask to the original one
			//Mat covered_output = chi_mask_cover(original, removed_border_mask);


			//step 6-2. set transparentcy
			Mat transparent_mask = chi_transparent_maker(removed_border_mask);

			//step 6-3. save the talkbox
			Mat talkbox = chi_extract_word(original, transparent_mask);
			//These are useful but shouldn't be here
			/*
			//step 2-2. findContours;
			Mat contour_Img(floodfill_mask.rows, floodfill_mask.cols, CV_8UC3);
			Canny(extraction, extraction, 100, 200);
			vector<vector<Point>> contours;
			vector<Vec4i> hierarchy;
			findContours(extraction, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
			//draw contours
			for (int i = 0; i < contours.size(); i++) {
			drawContours(contour_Img, contours, i, cover, 1, 8, hierarchy);
			}
			imshow("【edge】", contour_Img);




			Mat extraction(floodfill_mask.rows, floodfill_mask.cols, CV_8UC3);
			int widthLimit = floodfill_mask.channels() * floodfill_mask.cols;
			for (int height = 0; height < floodfill_mask.rows; height++) {
			uchar *data_in = floodfill_mask.ptr<uchar>(height);
			Vec3b *data_out = extraction.ptr<Vec3b>(height);
			for (int width = 0; width < widthLimit; width++) {
			if (data_in[width] == fillValue) {
			data_out[width][0] = cover[0];
			data_out[width][1] = cover[1];
			data_out[width][2] = cover[2];
			}
			}
			}
			imshow("【extraction】", extraction);
			*/


			activated_point.x = -1;
			activated_point.y = -1;
			break;

		}

		//I don't know why but it change from "cvWaitKey" to "cv::waitKey"
		if (cv::waitKey(33) == 27) {
			break;
		}

	}

	return 0;
}



//mouse
void FillTalkBox::onMouse(int Event, int x, int y, int flags, void* param) {

	if (Event == EVENT_LBUTTONDOWN) {
		activated_point.x = x;
		activated_point.y = y;
	}
}

void FillTalkBox::detect_cover(int x, int y) {
	cover = original.at<Vec3b>(y, x);
	//std::cout << "b " << (int)original.at<Vec3b>(y, x)[0] << "g " << (int)original.at<Vec3b>(y, x)[1] << "r " << (int)original.at<Vec3b>(y, x)[2];
	//cover = Vec3b((int)original.at<Vec3b>(y, x)[0], (int)original.at<Vec3b>(y, x)[1], (int)original.at<Vec3b>(y, x)[2]);
	//std::cout << (int)cover[0] << (int)cover[1] << (int)cover[2];
}



//step 1. floodfill
Mat FillTalkBox::cih_floodfill(Mat input) {

	Mat floodfill_mask;
	Canny(input, floodfill_mask, 100, 200);
	copyMakeBorder(floodfill_mask, floodfill_mask, 1, 1, 1, 1, BORDER_REPLICATE); //bigger than the original one 1 unit

	floodFill(input, floodfill_mask, activated_point, cover, 0, Scalar(20, 20, 20), Scalar(20, 20, 20), 4 | FLOODFILL_MASK_ONLY | (fillValue << 8));
	//imshow("【mask】", floodfill_mask);
	return floodfill_mask;
}


//step 2. extract
Mat FillTalkBox::chi_extract(Mat input) {
	Mat extraction(input.rows, input.cols, CV_8U);
	int widthLimit = input.channels() * input.cols;
	for (int height = 0; height < input.rows; height++) {
		uchar *data_in = input.ptr<uchar>(height);
		uchar *data_out = extraction.ptr<uchar>(height);
		for (int width = 0; width < widthLimit; width++) {
			if (data_in[width] == fillValue) {
				data_out[width] = fillValue;
			}
			else{
				data_out[width] = fillValue + 50;
			}
		}
	}

	//imshow("【extraction】", extraction);
	return extraction;
}

//step 3. inverse floodfill
Mat FillTalkBox::chi_inverse_floodfill(Mat input) {
	Mat inverse_floodfill_mask;
	copyMakeBorder(input, input, 1, 1, 1, 1, BORDER_REPLICATE);//bigger than the original one 2 units, to spare the point (0,0) from floodfill
	Canny(input, inverse_floodfill_mask, 80, 200);
	copyMakeBorder(inverse_floodfill_mask, inverse_floodfill_mask, 1, 1, 1, 1, BORDER_REPLICATE);  //bigger than the original one 3 units
	floodFill(input, inverse_floodfill_mask, Point(0, 0), cover, 0, Scalar(20, 20, 20), Scalar(20, 20, 20), 4 | FLOODFILL_MASK_ONLY | (fillValue << 8)); //for point(0,0) is out of range anyway.
	//imshow("【inverse floodfill】", inverse_floodfill_mask);
	return inverse_floodfill_mask;
}

//step 4. extract again

Mat FillTalkBox::chi_inverse_extract(Mat input) {
	Mat inverse_extraction(input.rows, input.cols, CV_8UC3);
	int widthLimit = input.channels() * input.cols;
	for (int height = 0; height < input.rows; height++) {
		uchar *data_in = input.ptr<uchar>(height);
		Vec3b *data_out = inverse_extraction.ptr<Vec3b>(height);
		for (int width = 0; width < widthLimit; width++) {
			if (data_in[width] != fillValue) {
				data_out[width] = cover;
			}
			else{
				data_out[width][0] = cover[0] + 50;
				data_out[width][1] = cover[1] + 50;
				data_out[width][2] = cover[2] + 50;
			}

		}
	}
	int erosion_size = 5;
	Mat element = getStructuringElement( MORPH_RECT,
                                     Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                     Point( erosion_size, erosion_size ) );

	erode(inverse_extraction, inverse_extraction, element);

	// imshow("【inverse extraction】", inverse_extraction);
	// waitKey(3000);
	return inverse_extraction;
}




//step 5. remove the border
Mat FillTalkBox::chi_remove_3border(Mat input) {
	Mat removed_border;
	input(Rect(3, 3, input.cols - 6, input.rows - 6)).copyTo(removed_border);
	//imshow("【removed border】", removed_border);
	return removed_border;
	}


//step 6. add the mask to the original one
Mat FillTalkBox::chi_mask_cover(Mat original, Mat input) {
	Mat covered_output;
	original.copyTo(covered_output);

	for (int i = 0; i < input.rows; i++) {
		for (int j = 0; j < input.cols; j++) {

			if (input.at<Vec3b>(i, j) == cover) {
				covered_output.at<Vec3b>(i, j) = cover;

				//covered_output.at<Vec3b>(i, j)[0] = (int)cover[0];
				//covered_output.at<Vec3b>(i, j)[1] = (int)cover[1];
				//covered_output.at<Vec3b>(i, j)[2] = (int)cover[2];
			}
		}
	}


	/*
	int widthLimit = covered_output.channels() * covered_output.cols;
	for (int height = 0; height < covered_output.rows; height++) {
		Vec3b *data_in = input.ptr<Vec3b>(height);
		Vec3b *data_out = covered_output.ptr<Vec3b>(height);
		for (int width = 0; width < widthLimit; width++) {
			if (data_in[width] == Vec3b(0, 0, 0)) {
				data_out[width] = cover;
			}
		}
	}
	*/
	//imshow("【covered_output】", covered_output);
	return covered_output;
}

//step 6.2
Mat FillTalkBox::chi_transparent_maker(Mat input)
{
    cv::Mat input_bgra;
//    cv::Mat input_gray;
	cv::cvtColor(input, input_bgra, CV_BGR2BGRA);
//	cv::cvtColor(input, input_gray, CV_BGR2GRAY);
    // find all white pixel and set alpha value to zero:
    for (int y = 0; y < input.rows; ++y)
    for (int x = 0; x < input.cols; ++x)
    {
        cv::Vec4b & pixel = input_bgra.at<cv::Vec4b>(y, x);
	if (input.at<Vec3b>(y, x) != cover) {
			pixel[3] = 0;
			}
    }

    string path = get_current_dir();
	imwrite(path + "/app/tools/helpercore/temp/transparent_mask.png", input_bgra);
	
	string coordinate = Get_bounded_box_coordinate(input);
	
	std::ofstream outfile(path + "/app/tools/helpercore/temp/bounded_box_coordinate.txt");
	outfile << coordinate <<std::endl;
	outfile.close();

	return input_bgra;

}
//step 6-3. save the talkbox
Mat FillTalkBox::chi_extract_word(Mat original, Mat transparent_mask){
	Mat extract_word, original_bgra;
    cv::cvtColor(transparent_mask, extract_word, CV_BGR2BGRA);
    cv::cvtColor(original, original_bgra, CV_BGR2BGRA);
	
    // imshow("transparent_mask", transparent_mask);
    // imshow("original", original);
    // waitKey(2000);

	for (int i = 0; i < transparent_mask.rows; i++) {
		for (int j = 0; j < transparent_mask.cols; j++) {

			if (transparent_mask.at<Vec4b>(i, j)[3] != 0) {
				extract_word.at<Vec4b>(i, j) = original_bgra.at<Vec4b>(i, j);

				//covered_output.at<Vec3b>(i, j)[0] = (int)cover[0];
				//covered_output.at<Vec3b>(i, j)[1] = (int)cover[1];
				//covered_output.at<Vec3b>(i, j)[2] = (int)cover[2];
			}
			else{
				extract_word.at<Vec4b>(i, j)[0] = 255;
				extract_word.at<Vec4b>(i, j)[1] = 255;
				extract_word.at<Vec4b>(i, j)[2] = 255;
				extract_word.at<Vec4b>(i, j)[3] = 255;
			}
		}
	}
	string path = get_current_dir();
	imwrite(path + "/app/tools/helpercore/temp/talkbox.jpg", extract_word);
	// cout << path + "/app/tools/helpercore/temp/talkbox.jpg" << endl;
	return extract_word;
}


void FillTalkBox::findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + replaceStr.size());
	}
}




string Get_bounded_box_coordinate(Mat src) {
		Mat contourImg = Mat::zeros(src.size(), src.type());
		Mat src_gray;
		cvtColor(src, src_gray, CV_BGR2GRAY);
		
	//	imshow("stc2gray", src_gray);
		Mat edge;
		Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
		dilate(src_gray, src_gray, kernel);
		Canny(src_gray, edge, 50, 150, 3);

		vector < vector<Point> > contours;
		vector < Vec4i > hierarchy;
		findContours(edge, contours, hierarchy, CV_RETR_EXTERNAL,
				CV_CHAIN_APPROX_SIMPLE);

		for (int i = 0; i < (int) contours.size(); i++) {
			Scalar color = Scalar(125, 125, 255);
			drawContours(contourImg, contours, i, color, 0, 8, hierarchy);
		}
		//imshow("contours in checking ", contourImg);
		//cout << "contours size " << contours.size() << endl;
		
		if(contours.size()!=1){
			cout << "contours size is " << contours.size() << endl;
			cout << "return fail" << endl;
			return "fail";
		}
		//找出長方形（長、寬）
		Mat drawing_rect = contourImg.clone();
	//	cout << "countour size of checking = " << contours.size() << endl;
		for (int i = 0; i < contours.size(); i++) {
	//		RotatedRect minRect = minAreaRect(Mat(contours[i]));
			Rect minRect = boundingRect(Mat(contours[i]));
			
			Point rect_points[4];
			rect_points[0] = Point(minRect.x, minRect.y);
			rect_points[1] = Point(minRect.x + minRect.width, minRect.y);
			rect_points[3] = Point(minRect.x, minRect.y + minRect.height);
			rect_points[2] = Point(minRect.x + minRect.width, minRect.y + minRect.height);
			
	//		minRect.points(rect_points);
			for (int j = 0; j < 4; j++)
				line(drawing_rect, rect_points[j], rect_points[(j + 1) % 4],
						Scalar(255), 2);
		}
		//imshow("minRectangle", drawing_rect);
		
		Rect minRect = boundingRect(Mat(contours[0]));
		stringstream ss;
		ss << minRect.x << ',' << minRect.y << ',' << minRect.width << ',' << minRect.height;
		string str = ss.str();
		//cout << str << endl;

		return str;
}
