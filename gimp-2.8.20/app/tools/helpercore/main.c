/*
 * main.c
 *
 *  Created on: 2019 Jan 5
 *      Author: isaiah
 */

#include <stdio.h>
#include "FillTalkBox.h"


int main(int argc, char **argv) {
	const char *s;
	int x;
	int y;

	if(argv[1]!= NULL && argv[2]!= NULL && argv[3]!= NULL){
        s = argv[1];
	x = atoi(argv[2]);
	y = atoi(argv[3]);

        std::string str(s);
	FillTalkBox a(s);
	a.talk_box_detect(x, y);

	return 0;
        }


	//printf(" you have enger %s", s);

	//FillTalkBox a(s);


	//default
	FillTalkBox a("file:///home/isaiah/gimp-helper-2019/gimp-2.8.20/app/tools/helpercore/OnePiece-2.jpg");
	a.talk_box_detect(10, 10);

	//printf("Success!\n");

	return 0;
}
//file:///home/isaiah/gimp-helper-2019/gimp-2.8.20/app/tools/helpercore/OnePiece-2.jpg
///home/isaiah/gimp-helper-2019/gimp-2.8.20/app/tools/helpercore

