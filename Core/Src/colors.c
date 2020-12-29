/*
 * colors.c
 *
 *  Created on: Dec 28, 2020
 *      Author: timurko
 */
#include "colors.h"

void gammaInit(float gamma) {
	// precalculate the gamma lookup table
	for (int i = 0; i < 256; i++) {
		gammaTable[i] = 255 * pow((i / 256.0), gamma);
		//(uint8_t)(((float)n/LED_FRAME_SIZE)*255);
	};
}

uint32_t gradientTransition(
		uint8_t (*gradient_a)[16][4],
		uint8_t (*gradient_b)[16][4],
		uint8_t pos,
		float transition) {
	struct RGB a, b;
	uint8_t i;
	float f;

	// First gradient interation
	for (i=0; i<15; i++) {
		uint8_t from = (*gradient_a)[i][0];
		uint8_t to = (*gradient_a)[i+1][0];
		if (pos>=from && pos<to) {
			f = (float)(pos-from)/(to-from);
			a.r = (uint8_t)lerp((*gradient_a)[i][1], (*gradient_a)[i+1][1], f);
			a.g = (uint8_t)lerp((*gradient_a)[i][2], (*gradient_a)[i+1][2], f);
			a.b = (uint8_t)lerp((*gradient_a)[i][3], (*gradient_a)[i+1][3], f);
			break;
		}
	}

	// Second gradient interation
	for (i=0; i<15; i++) {
		uint8_t from = (*gradient_b)[i][0];
		uint8_t to = (*gradient_b)[i+1][0];
		if (pos>=from && pos<to) {
			f = (float)(pos-from)/(to-from);
			b.r = (uint8_t)lerp((*gradient_b)[i][1], (*gradient_b)[i+1][1], f);
			b.g = (uint8_t)lerp((*gradient_b)[i][2], (*gradient_b)[i+1][2], f);
			b.b = (uint8_t)lerp((*gradient_b)[i][3], (*gradient_b)[i+1][3], f);
			break;
		}
	}

	/*printf("RGB(float): %3.2f, %3.2f, %3.2f; RGB(int): %d, %d, %d; RGB(gamma): %d, %d, %d\n",
			lerp(a.r, b.r, transition),
			lerp(a.g, b.g, transition),
			lerp(a.b, b.b, transition),
			FLOAT_TO_INT(lerp(a.r, b.r, transition)),
			FLOAT_TO_INT(lerp(a.g, b.g, transition)),
			FLOAT_TO_INT(lerp(a.b, b.b, transition)),
			gammaTable[FLOAT_TO_INT(lerp(a.r, b.r, transition))],
			gammaTable[FLOAT_TO_INT(lerp(a.g, b.g, transition))],
			gammaTable[FLOAT_TO_INT(lerp(a.b, b.b, transition))]
	);*/

	return getRGB(
			gammaTable[(uint8_t)lerp(a.r, b.r, transition)],
			gammaTable[(uint8_t)lerp(a.g, b.g, transition)],
			gammaTable[(uint8_t)lerp(a.b, b.b, transition)]
	);
}


uint32_t gradientRGB(uint8_t (*gradient)[16][4], uint8_t pos) {
	uint32_t color = 0x000000;
	uint8_t r, g, b, i;
	float f;

	for (i=0; i<15; i++) {
		uint8_t from = (*gradient)[i][0];
		uint8_t to = (*gradient)[i+1][0];
		if (pos>=from && pos<to) {
			f = (float)(pos-from)/(to-from);
			r = gammaTable[(uint8_t) lerp((*gradient)[i][1], (*gradient)[i+1][1], f)];
			g = gammaTable[(uint8_t) lerp((*gradient)[i][2], (*gradient)[i+1][2], f)];
			b = gammaTable[(uint8_t) lerp((*gradient)[i][3], (*gradient)[i+1][3], f)];
			color = (uint32_t)(r << 16 | g << 8 | b << 0);
			//printf("Current float: %f, red: %d, green: %d, blue: %d\nHEX:  %04x\n", f, r, g, b, color);
			break;
		}
	}
	return color;
}
