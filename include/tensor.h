#ifndef TENSOR_H
#define TENSOR_H

#include <stdint.h>
#include "config.h"

typedef struct {
    int width;
    int height;
    int channels;
    int8_t data[MAX_CHANNELS][MAX_HEIGHT][MAX_WIDTH];
} Tensor;

Tensor create_tensor(int width, int height, int channels);
void fill_tensor(Tensor* tensor, int8_t value);
void print_tensor(const Tensor* tensor);

#endif
