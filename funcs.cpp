#include <iostream>
#include <string>
#include "funcs.h"
#include "imageio.h"

/* TASK A:
Write a new program invert.cpp that inverts all colors, 
so white shades become black, and black become white
*/
void invert(int img[MAX_H][MAX_W], int& h, int& w) {
	int output[MAX_H][MAX_W];
	for (int row = 0;row < h; row++) {
		for (int col = 0; col < w; col++) {
			output[row][col] = 255 - img[row][col]; 
		}
	}
	writeImage("taskA.pgm",output,h,w);
}

/* TASK B:
Write a program invert-half.cpp that inverts the colors 
only in the right half of the picture.
*/

void invert_half(int img[MAX_H][MAX_W], int& h, int& w) {
	int output[MAX_H][MAX_W];
	for (int row = 0; row < h; row ++) {
		for (int col = 0; col < w; col++) {
			if (col > w/2) {
				output[row][col] =  255 - img[row][col];
			}
			else {
				output[row][col] = img[row][col];
			}
		}
	}
	writeImage("taskB.pgm",output,h,w);
}

/* TASK C:
Write a program box.cpp that draws a white box exactly 
in the middle of the picture. The dimensions of the box 
should be 50% by 50% of the original picture’s width and height.
*/

void box(int img[MAX_H][MAX_W], int &h, int &w) {
	int output[MAX_H][MAX_W];
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (col > w/4 && col < w - w/4 && row > h/4 && row < h - h/4) {
				output[row][col] = 255;
			}
			else {
				output[row][col] = img[row][col];
			}
		}
	}
	writeImage("taskC.pgm",output,h,w);
}

/* TASK D:
Program frame.cpp. Same as the previous task, but it should 
be a frame exactly one pixel thick.
*/

void frame(int img[MAX_H][MAX_W], int &h, int &w) {
	int output[MAX_H][MAX_W];
	for (int row = 0; row < h; row++) {
		for (int col = 0; col <w; col++) {
			output[row][col] = img[row][col];
		}
	}
	for (int col = w/4; col < w - w/4; col++) {
		output[h/4][col] = 255;
	}
	for (int col = w/4; col < w - w/4; col++) {
		output[h-h/4][col] = 255;
	}
	for (int row = h/4; row < h - h/4; row++) {
		output[row][w/4] = 255;
	}
	for (int row = h/4; row < h - h/4; row++) {
		output[row][w-w/4] = 255;
	}
	writeImage("taskD.pgm",output,h,w);
}

/* TASK E:
Program scale.cpp. Scale the original picture to 200% of 
its size. It can be done by increasing the size of the picture 
by the factor of 2, and copying each pixel of the input as a small 
2x2 square in the output. (We don’t do any interpolation of colors 
as more advanced scaling procedures would do.)
*/

void scale(int img[MAX_H][MAX_W], int &h, int &w) {
	int output[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			output[row*2][col*2] = img[row][col];
			output[row*2+1][col*2] = img[row][col];
			output[row*2][col*2+1] = img[row][col];
			output[row*2+1][col*2+1] = img[row][col];
		}
	}
	writeImage("taskE.pgm",output,h*2,w*2);
}

/* TASK F:
Program pixelate.cpp will be pixelating the input image.
*/

void pixelate(int img[MAX_H][MAX_W], int &h, int &w) {
	int output[MAX_H][MAX_W];
	for (int row =0; row < h; row+=2) {
		for (int col = 0; col < w; col+=2) {
			int sum = 0;
			sum = sum + img[row][col];
			sum = sum + img[row+1][col];
			sum = sum + img[row][col+1];
			sum = sum + img[row+1][col+1];
			
			int avg = sum/4;
			
			output[row][col] = avg;
			output[row+1][col] = avg;
			output[row][col+1] = avg;
			output [row+1][col+1] = avg;
		}
	}
	writeImage("taskF.pgm",output,h,w);
}

			