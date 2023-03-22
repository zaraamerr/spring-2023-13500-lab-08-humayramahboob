#pragma once
#include "imageio.h"

void invert(int image[MAX_H][MAX_W], int &h, int &w);
void invert_half(int image[MAX_H][MAX_W], int &h, int &w);
void box(int image[MAX_H][MAX_W], int &h, int &w);
void frame(int image[MAX_H][MAX_W], int &h, int &w);
void scale(int image[MAX_H][MAX_W], int &h, int &w);
void pixelate(int image[MAX_H][MAX_W], int &h, int &w);