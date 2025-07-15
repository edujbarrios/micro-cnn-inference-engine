#include "tensor.h"
#include <string.h>
#include <stdio.h>

// Create a tensor with specified dimensions, initialized to 0
Tensor create_tensor(int width, int height, int channels) {
    Tensor tensor;
    tensor.width = width;
    tensor.height = height;
    tensor.channels = channels;
    memset(tensor.data, 0, sizeof(tensor.data));
    return tensor;
}

// Fill an existing tensor with a constant value
void fill_tensor(Tensor* tensor, int8_t value) {
    for (int channel = 0; channel < tensor->channels; channel++) {
        for (int row = 0; row < tensor->height; row++) {
            for (int col = 0; col < tensor->width; col++) {
                tensor->data[channel][row][col] = value;
            }
        }
    }
}

// Print all values in a tensor in a structured format
void print_tensor(const Tensor* tensor) {
    for (int channel = 0; channel < tensor->channels; channel++) {
        printf("Channel %d:\n", channel);
        for (int row = 0; row < tensor->height; row++) {
            for (int col = 0; col < tensor->width; col++) {
                printf("%4d ", tensor->data[channel][row][col]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
