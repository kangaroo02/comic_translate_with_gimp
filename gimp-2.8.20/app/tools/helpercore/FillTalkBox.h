/*
 * FillTalkBox.h

 *
 *  Created on: 2018 M08 24
 *      Author: Isaiah Yang
 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string.h>


using namespace std;
using namespace cv;

#ifndef FILLTALKBOX_H_
#define FILLTALKBOX_H_

class FillTalkBox {

private:
	static Point activated_point;
	static Vec3b cover;
	static uchar fillValue;
    Mat original;

public:
    FillTalkBox(string input);
    static void onMouse(int Event, int x, int y, int flags, void* param);
    void detect_cover(int x, int y);
	Mat cih_floodfill(Mat input);
	Mat chi_extract(Mat input);
	Mat chi_inverse_floodfill(Mat input);
	Mat chi_inverse_extract(Mat input);
	Mat chi_remove_3border(Mat input);
	Mat chi_mask_cover(Mat original, Mat input);
	Mat chi_transparent_maker(Mat input);
	int talk_box_detect(int x, int y);
	void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);
	Mat chi_extract_word(Mat input, Mat transparent_mask);

};



#endif /* FILLTALKBOX_H_ */
