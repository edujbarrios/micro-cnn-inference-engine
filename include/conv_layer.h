#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "tensor.h"
#include "config.h"

typedef struct {
    int input_channels;
    int output_channels;
    int kernel_size;
    int8_t weights[MAX_OUTPUT_CHANNELS][MAX_CHANNELS][KERNEL_SIZE][KERNEL_SIZE];
    int8_t biases[MAX_OUTPUT_CHANNELS];
} ConvLayer;

ConvLayer create_conv_layer(int input_channels, int output_channels, int kernel_size);
void fill_conv_layer(ConvLayer* layer);
void conv2d(const Tensor* input_tensor, Tensor* output_tensor, const ConvLayer* layer);

#endif
