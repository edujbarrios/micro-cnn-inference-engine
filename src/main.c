#include <stdio.h>
#include "tensor.h"
#include "conv_layer.h"
#include "config.h"

int main() {
    printf("=== Micro CNN Inference Engine ===\n\n");

    // Step 1: Create input tensor
    printf("[1] Creating input tensor with size: %dx%dx%d\n", INPUT_WIDTH, INPUT_HEIGHT, INPUT_CHANNELS);
    Tensor input_tensor = create_tensor(INPUT_WIDTH, INPUT_HEIGHT, INPUT_CHANNELS);

    // Step 2: Fill input tensor with value 1
    printf("[2] Filling input tensor with value: 1\n");
    fill_tensor(&input_tensor, 1);

    printf("Input tensor values:\n");
    print_tensor(&input_tensor);

    // Step 3: Create and initialize convolution layer
    printf("[3] Creating convolution layer: kernel size = %d, output channels = %d\n", KERNEL_SIZE, OUTPUT_CHANNELS);
    ConvLayer conv_layer = create_conv_layer(INPUT_CHANNELS, OUTPUT_CHANNELS, KERNEL_SIZE);

    printf("[4] Filling convolution layer weights and biases with fixed values:\n");
    fill_conv_layer(&conv_layer);

    printf("  - Weights: All initialized to 1\n");
    printf("  - Biases: All initialized to 0\n");

    // Step 4: Perform convolution
    printf("[5] Running convolution operation...\n");
    Tensor output_tensor;
    conv2d(&input_tensor, &output_tensor, &conv_layer);

    // Step 5: Print output tensor
    printf("[6] Convolution result (output tensor):\n");
    print_tensor(&output_tensor);

    printf("\n=== Inference Complete ===\n");
    return 0;
}
