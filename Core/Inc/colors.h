/*
 * colors.h
 *
 *  Created on: Dec 28, 2020
 *      Author: timurko
 */

#ifndef INC_COLORS_H_
#define INC_COLORS_H_

/* includes */
#include <stdint.h>
#include "math.h"

// Helper defines
#define getRGB(r, g, b) ((uint32_t)(r << 16 | g << 8 | b << 0))
#define Red(c) ((uint8_t)((c >> 16) & 0xFF))
#define Green(c) ((uint8_t)((c >> 8) & 0xFF))
#define Blue(c) ((uint8_t)(c & 0xFF))

#define constrain(amt,low,high) ((amt)<=(low)?(low):((amt)>=(high)?(high):(amt)))
#define lerp(a,b,f) (a+f*(b-a))

struct RGB {
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

static uint8_t gammaTable[256];

/* functions */
void gammaInit(float gamma);
uint32_t gradientTransition(uint8_t (*gradient_a)[16][4], uint8_t (*gradient_b)[16][4], uint8_t pos, float transition);
uint32_t gradientRGB(uint8_t (*gradient)[16][4], uint8_t pos);

#endif /* INC_COLORS_H_ */
