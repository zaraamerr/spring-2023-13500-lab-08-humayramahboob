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
	int inverted[MAX_H][MAX_W]; //declare a new 2D integer array of size MAX_H and MAX_W that'll store the inverted image
	for (int row = 0;row < h; row++) { //iterate thru each pixel
		for (int col = 0; col < w; col++) {
			inverted[row][col] = 255 - img[row][col]; //subtract 255 from the og pixel value
		}
	}
	writeImage("taskA.pgm",inverted,h,w);
}

/* TASK B:
Write a program invert-half.cpp that inverts the colors 
only in the right half of the picture.
*/

void invert_half(int img[MAX_H][MAX_W], int& h, int& w) {
	int invert_half[MAX_H][MAX_W]; //declare a new 2D integer array of size MAX_H and MAX_W that'll store the half-inverted image
	for (int row = 0; row < h; row ++) { //iterate thru each pixel
		for (int col = 0; col < w; col++) { 
			if (col > w/2) {  //checking if the column number is greater than half the width of the image
				invert_half[row][col] =  255 - img[row][col]; //if true, invert
			}
			else { //if not
				invert_half[row][col] = img[row][col]; //keep og
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
	int box[MAX_H][MAX_W]; //declare a new 2D integer array of size MAX_H and MAX_W that'll store the white box
	for (int row = 0; row < h; row++) { //iterate thru each pixel
		for (int col = 0; col < w; col++) {
			if (col >= w/4 && col <= (w*3)/4 && row >= h/4 && row <= (h*3)/4) { //if within these bounds
				box[row][col] = 255; //set pixel color to white
			}
			else { //if not
				box[row][col] = img[row][col]; //keep og color
			}
		}
	}
	writeImage("taskC.pgm",box,h,w);
}

/* TASK D:
Program frame.cpp. Same as the previous task, but it should 
be a frame exactly one pixel thick.
*/

/* ORIGINAL CODE
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
 } */

//new code: refactored the big if statement into two smaller if statements for improved readability
void frame(int img[MAX_H][MAX_W], int &h, int &w) {
    int frame[MAX_H][MAX_W]; ////declare a new 2D integer array of size MAX_H and MAX_W that'll store the frame
    for (int row = 0; row < h; row++) { //iterate thru each pixel
        for (int col = 0; col < w; col++) {
            if (col == w/4 || col == (w*3)/4 || row == h/4 || row == (h*3)/4) { // check if on frame boundary
                if (col >= w/4 && col <= (w*3)/4 && row >= h/4 && row <= (3*h)/4) { // check if inside frame
                    frame[row][col] = 255; //set pixel color to white
                }
            }
            else { 
                frame[row][col] = img[row][col];
            }
        }
    }
    writeImage("taskD.pgm", frame, h, w);
}

/* TASK E:
Program scale.cpp. Scale the original picture to 200% of 
its size. It can be done by increasing the size of the picture 
by the factor of 2, and copying each pixel of the input as a small 
2x2 square in the output. (We don’t do any interpolation of colors 
as more advanced scaling procedures would do.)
*/

void scale(int img[MAX_H][MAX_W], int &h, int &w) {
	int scale[MAX_H][MAX_W]; //declare a new 2D integer array of size MAX_H and MAX_W that'll store the scaled image
	for(int row = 0; row < h; row++) { //iterate thru each pixel
		for (int col = 0; col < w; col++) {
			//double the size
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

/* ORIGINAL CODE:
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
} */

//new code: calculate the sum of the pixel values using two nested loops to iterate over the 2x2 block of pixels
void pixelate(int img[MAX_H][MAX_W], int &h, int &w) {
    int pixelate[MAX_H][MAX_W]; //declare a new 2D integer array of size MAX_H and MAX_W that'll store the pixelated image
    for (int row = 0; row < h; row += 2) { //iterate thru every other row
        for (int col = 0; col < w; col += 2) { //iterate thru every other column
            int sum = 0;
            for (int i = row; i < row + 2; i++) { //use nested for loop to calculate sum
                for (int j = col; j < col + 2; j++) {
                    sum += img[i][j];
                }
            }
            int avg = sum / 4; //calculate avg
			//sets the pixel values in the output image to the average pixel value calculated
            //in the previous step. replacing each 2x2 block of pixels with a single pixel with the
            //average color.
            pixelate[row][col] = avg;
            pixelate[row + 1][col] = avg;
            pixelate[row][col + 1] = avg;
            pixelate[row + 1][col + 1] = avg;
        }
    }
    writeImage("taskF.pgm", pixelate, h, w);
}


			