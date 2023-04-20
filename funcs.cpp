#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include "funcs.h"
#include "imageio.h"

/* TASK A:
Write a new program invert.cpp that inverts all colors, 
so white shades become black, and black become white
*/
void invert(int img[MAX_H][MAX_W], int& h, int& w) {
	int inverted[MAX_H][MAX_W];
	for (int row = 0;row < h; row++) {
		for (int col = 0; col < w; col++) {
			inverted[row][col] = 255 - img[row][col]; 
		}
	}
	writeImage("taskA.pgm",inverted,h,w);
}

/* TASK B:
Write a program invert-half.cpp that inverts the colors 
only in the right half of the picture.
*/

void invert_half(int img[MAX_H][MAX_W], int& h, int& w) {
	int invert_half[MAX_H][MAX_W];
	for (int row = 0; row < h; row ++) {
		for (int col = 0; col < w; col++) {
			if (col > w/2) {
				invert_half[row][col] =  255 - img[row][col];
			}
			else {
				invert_half[row][col] = img[row][col];
			}
		}
	}
	writeImage("taskB.pgm",invert_half,h,w);
}

/* TASK C:
Write a program box.cpp that draws a white box exactly 
in the middle of the picture. The dimensions of the box 
should be 50% by 50% of the original picture’s width and height.
*/

void box(int img[MAX_H][MAX_W], int &h, int &w) {
	int box[MAX_H][MAX_W];
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (col >= w/4 && col <= (w*3)/4 && row >= h/4 && row <= (h*3)/4) {
				box[row][col] = 255;
			}
			else {
				box[row][col] = img[row][col];
			}
		}
	}
	writeImage("taskC.pgm",box,h,w);
}

/* TASK D:
Program frame.cpp. Same as the previous task, but it should 
be a frame exactly one pixel thick.
*/

void frame(int img[MAX_H][MAX_W], int &h, int &w) {
	int frame[MAX_H][MAX_W];
	for (int row = 0; row < h; row++) {
		for (int col = 0; col <w; col++) {
			if((col == (w/4) || row == (h/4) or col == (w*3)/4 || row == (h*3)/4) && (col >= w/4 && row >= h/4 && col<= (w*3)/4 && row <= (3*h)/4)) {
				frame[row][col] = 255;
			}
			else {
				frame[row][col] = img[row][col];
			}
		}
	}
	writeImage("taskD.pgm",frame,h,w);
}

/* TASK E:
Program scale.cpp. Scale the original picture to 200% of 
its size. It can be done by increasing the size of the picture 
by the factor of 2, and copying each pixel of the input as a small 
2x2 square in the output. (We don’t do any interpolation of colors 
as more advanced scaling procedures would do.)
*/

void scale(int img[MAX_H][MAX_W], int &h, int &w) {
	int scale[MAX_H][MAX_W];
	for(int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			scale[row*2][col*2] = img[row][col];
			scale[row*2+1][col*2] = img[row][col];
			scale[row*2][col*2+1] = img[row][col];
			scale[row*2+1][col*2+1] = img[row][col];
		}
	}
	writeImage("taskE.pgm",scale,h*2,w*2);
}

/* TASK F:
Program pixelate.cpp will be pixelating the input image.
*/

void pixelate(int img[MAX_H][MAX_W], int &h, int &w) {
	int pixelate[MAX_H][MAX_W];
	for (int row =0; row < h; row+=2) {
		for (int col = 0; col < w; col+=2) {
			int sum = (img[row][col] + img[row][col+1] + img[row+1][col] + img[row+1][col+1]);
			
			int avg = sum/4;
			
			pixelate[row][col] = avg;
			pixelate[row+1][col] = avg;
			pixelate[row][col+1] = avg;
			pixelate [row+1][col+1] = avg;
		}
	}
	writeImage("taskF.pgm",pixelate,h,w);
}

			