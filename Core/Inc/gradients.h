/*
 * gradients.h
 *
 *  Created on: Dec 29, 2020
 *      Author: timurko
 */

#ifndef INC_GRADIENTS_H_
#define INC_GRADIENTS_H_

#include "stdlib.h"

#define gradientsNum 4

typedef uint8_t gradient[16][4];

gradient loading = {
		{0, 255, 0, 0},
		{85, 0, 255, 0},
		{170, 0, 0, 255},
		{255, 255, 0, 0}
};
gradient xmass = {
		{0, 255, 0, 0},
		{255, 0, 255, 0},
};

uint8_t currentGradient = 0;
uint8_t nextGradient = 0;
gradient gradients[gradientsNum] = {
		{ // pink
				{0, 244, 168, 48},
				{117, 230, 78, 92},
				{255, 173, 54, 228},
		},{ // bhw2_39
				{0, 40, 220, 226},
				{33, 143, 93, 213},
				{66, 143, 93, 213},
				{122, 255, 255, 128},
				{150, 244, 137, 58},
				{201, 153, 68, 105},
				{255, 88, 19, 137}
		},{ // bhw1_06
				{0, 225, 19, 194},
				{160, 19, 225, 223},
				{219, 210, 242, 227},
				{255, 255, 255, 255}
		},{ // bhw1_01
				{0, 255, 0, 0},
				{255, 0, 255, 0},
		}
};

typedef struct {
	gradient *item;
	size_t used;
	size_t size;
} GradList;

/**
 * https://stackoverflow.com/questions/49300051/need-a-two-dimensional-array-of-variable-size-in-a-struct
 * https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
 */

void initGradients(GradList *g, size_t initialSize) {
	g->item = malloc(initialSize * sizeof(uint8_t) * 16 * 4);
	g->used = 0;
	g->size = initialSize;
}


#endif /* INC_GRADIENTS_H_ */
