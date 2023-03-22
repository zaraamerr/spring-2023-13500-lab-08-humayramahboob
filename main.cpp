/* 
Author: Humayra Mahboob
Date: 3/22/2023
Course: CS-135
Assignment: LAB 8
Instructor: Michael Zamansky
*/

#include <iostream>
#include <string>
#include "funcs.h"
#include "imageio.h"

int main() {
	int img[MAX_H][MAX_W];
	int h = 0;
	int w = 0;
	std::string input("inImage.pgm");
	readImage(input,img,h,w);
	std::cout << "--------------------------" << std::endl;
	invert(img,h,w);
	std::cout << "--------------------------" << std::endl;
	invert_half(img,h,w);
	std::cout << "--------------------------" << std::endl;
	box(img,h,w);
	std::cout << "--------------------------" << std::endl;
	frame(img,h,w);
	std::cout << "--------------------------" << std::endl;
	scale(img,h,w);
	std::cout << "--------------------------" << std::endl;
	pixelate(img,h,w);
	std::cout << "--------------------------" << std::endl;
	return 0;
}

