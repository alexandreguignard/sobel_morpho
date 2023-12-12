/*
 ============================================================================
 Name        : average_filter.c
 Author      : [Your Name]
 Version     : 1.0
 Copyright   : [Your Copyright]
 Description : Averaging filter implementation
 ============================================================================
*/

#include <stdlib.h>
#include <string.h>

#include "sobel.h"

void sobel(int width, int height, unsigned char *input, unsigned char *output) {
  int i, j;

  // Apply the filter
  for (j = 1; j < height - 1; j++) {
    for (i = 1; i < width - 1; i++) {
      // Compute the average of the neighboring pixels
      int sum = input[(j - 1) * width + i - 1] + input[(j - 1) * width + i] + input[(j - 1) * width + i + 1] +
                input[j * width + i - 1] + input[j * width + i] + input[j * width + i + 1] +
                input[(j + 1) * width + i - 1] + input[(j + 1) * width + i] + input[(j + 1) * width + i + 1];

      output[(j - 1) * width + i] = sum / 9; // Divide by the number of neighbors for average
    }
  }

  // Fill the left and right sides
  for (j = 0; j < height - 2; j++) {
    output[j * width] = 0;
    output[(j + 1) * width - 1] = 0;
  }
}

