# Micro CNN Inference Engine

## Overview

This project demonstrates a minimalistic yet scalable convolutional neural network (CNN) inference engine implemented in pure C. It is structured for clarity and modularity, making it suitable for educational use, embedded systems prototyping, and as a foundation for custom AI inference engines.

## Project Structure

```
include/
    config.h
    tensor.h
    conv_layer.h
src/
    main.c
    tensor.c
    conv_layer.c
Makefile
README.md
```

## Features

- Pure C implementation
- Modular design with clear separation between headers and source files
- Single-layer convolution operation with configurable parameters
- Static memory allocation (no dynamic memory usage)
- Easy integration and extension for AI engineering demonstrations

## Building and Running

### Requirements
- GCC or compatible C compiler
- Make utility

### Commands

1. Compile:
   ```bash
   make
   ```

2. Execute:
   ```bash
   ./micro_cnn
   ```

3. Clean build artifacts:
   ```bash
   make clean
   ```

## Configuration

Edit `include/config.h` to customize:
- Tensor dimensions
- Kernel size
- Number of input and output channels
- Activation scaling factor


## Purpose and Use Cases

- Prototype for embedded AI projects where full frameworks like TensorFlow Lite are too heavy

## Author 

Eduardo J. Barrios [https://edujbarrios.com](https://edujbarrios.com)


