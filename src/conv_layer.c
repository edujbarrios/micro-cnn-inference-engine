#include "conv_layer.h"
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Create a convolution layer with specified parameters
ConvLayer create_conv_layer(int input_channels, int output_channels, int kernel_size) {
    ConvLayer layer;
    layer.input_channels = input_channels;
    layer.output_channels = output_channels;
    layer.kernel_size = kernel_size;
    memset(layer.weights, 1, sizeof(layer.weights));  // Default to 1
    memset(layer.biases, 0, sizeof(layer.biases));    // Default to 0
    return layer;
}

// Fill convolution layer weights and biases with fixed values
void fill_conv_layer(ConvLayer* layer) {
    memset(layer->weights, 1, sizeof(layer->weights));
    memset(layer->biases, 0, sizeof(layer->biases));
}

// Perform 2D convolution operation over an input tensor using given layer parameters
void conv2d(const Tensor* input_tensor, Tensor* output_tensor, const ConvLayer* layer) {
    for (int output_channel = 0; output_channel < layer->output_channels; output_channel++) {
        for (int output_row = 0; output_row < input_tensor->height - layer->kernel_size + 1; output_row++) {
            for (int output_col = 0; output_col < input_tensor->width - layer->kernel_size + 1; output_col++) {
                int sum = layer->biases[output_channel];
                for (int input_channel = 0; input_channel < layer->input_channels; input_channel++) {
                    for (int kernel_row = 0; kernel_row < layer->kernel_size; kernel_row++) {
                        for (int kernel_col = 0; kernel_col < layer->kernel_size; kernel_col++) {
                            sum += input_tensor->data[input_channel][output_row + kernel_row][output_col + kernel_col] *
                                   layer->weights[output_channel][input_channel][kernel_row][kernel_col];
                        }
                    }
                }
                output_tensor->data[output_channel][output_row][output_col] = MAX(0, sum / ACTIVATION_SCALE);
            }
        }
    }
    output_tensor->channels = layer->output_channels;
    output_tensor->width = input_tensor->width - layer->kernel_size + 1;
    output_tensor->height = input_tensor->height - layer->kernel_size + 1;
}
