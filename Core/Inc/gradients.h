/*
 * gradients.h
 *
 *  Created on: Dec 29, 2020
 *      Author: timurko
 */

#ifndef INC_GRADIENTS_H_
#define INC_GRADIENTS_H_

#include "stdlib.h"

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
#define gradientsNum 9
gradient gradients[gradientsNum] = {
		{
				/**
				 * Instagram
				 */
				{0,   228, 202, 83},
				{67,  226, 93,  14},
				{128,  198,  20, 83},
				{192,  125,  23, 177},
				{255,   44,  55, 198}

		},{
				/**
				 * bhw2_39
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_39.png.index.html
				 */
				{0, 40, 220, 226},
				{33, 143, 93, 213},
				{66, 143, 93, 213},
				{122, 255, 255, 128},
				{150, 244, 137, 58},
				{201, 153, 68, 105},
				{255, 88, 19, 137}
		},{
				/**
				 * PINK -> CYAN -> WHITE
				 * bhw1 06
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_06.png.index.html
				 */
				{0, 225, 19, 194},
				{160, 19, 225, 223},
				{219, 210, 242, 227},
				{255, 255, 255, 255}
		},{
				/**
				 * YELLOW -> PINK
				 * bhw1 06
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_01.png.index.html
				 */
				{0, 244, 168, 48},
				{117, 230, 78, 92},
				{255, 173, 54, 228},
		},{
				/**
				 * GREEN -> BLUE -> VIOLET
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_05.png.index.html
				 */
				{0, 5, 239, 137},
				{255, 158, 35, 221}
		},{
				/**
				 * RED-YELLOW-BLUE
				 * Sunset_Real
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Sunset_Real.png.index.html
				 */
				{0, 191, 0, 0},
				{22, 223, 85, 0},
				{51, 255, 170, 0},
				{85, 217, 85, 89},
				{135, 178, 0, 178},
				{198, 89, 0, 195},
				{255, 0, 0, 212}
		},{
				/**
				 * bhw1_26
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_26.png.index.html
				 */
				{0, 183, 26, 234},
				{35, 255, 255, 255},
				{73, 183, 26, 234},
				{107, 76, 200, 236},
				{130, 255, 255, 255},
				{153, 76, 200, 236},
				{170, 108, 215, 188},
				{198, 140, 230, 140},
				{207, 198, 243, 198},
				{219, 255, 255, 255},
				{231, 198, 243, 198},
				{252, 140, 230, 140},
				{255, 140, 230, 140}
		},{
				/**
				 * BLUE-VIOLET-YELLOW-PINK
				 * bhw2_39
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_39.png.index.html
				 */
				{0, 40, 220, 226},
				{33, 143, 93, 213},
				{66, 143, 93, 213},
				{122, 255, 255, 128},
				{150, 244, 137, 58},
				{201, 153, 68, 105},
				{255, 88, 19, 137}
		},{
				/**
				 * bhw1_sunset1
				 * url: http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_sunset1.png.index.html
				 */
				{0, 117, 82, 102},
				{38, 194, 96, 93},
				{71, 242, 132, 109},
				{145, 228, 199, 193},
				{178, 170, 192, 233},
				{255, 51, 88, 159}
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
