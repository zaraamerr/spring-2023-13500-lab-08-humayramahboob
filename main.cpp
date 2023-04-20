/* 
Author: Humayra Mahboob
Date: 3/22/2023
Course: CS-135
Assignment: LAB 8
Instructor: Michael Zamansky
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include "funcs.h"
#include "imageio.h"

int main() {
	int img[MAX_H][MAX_W];
	int h = 0;
	int w = 0;
	std::string input("inImage.pgm");
	readImage(input,img,h,w);
	// Task A
	invert(img,h,w);
	//Task B
	invert_half(img,h,w);
	//Task C
	box(img,h,w);
	//Task D
	frame(img,h,w);
	//Task E
	scale(img,h,w);
	//Task F
	pixelate(img,h,w);
	return 0;
}

