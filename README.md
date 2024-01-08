# Image Convolution Program

This C++ program performs image convolution, allowing you to apply various filters and operations on an image using a kernel. The program generates a random image and a random kernel (if required) and applies convolution to produce a resultant image.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Image Convolution Program is a C++ application designed for image processing. It uses convolution to modify the original image based on a specified kernel, enabling operations such as blurring, sharpening, and edge detection.

## Features

- Random generation of an image and a kernel.
- Convolution operation with dynamic array handling.
- Print functions for displaying arrays.
- Simple and easy-to-understand C++ code.

## Usage

1. **Compile the program:**

    ```bash
    g++ main.cpp -o image_convolution
    ```

2. **Run the executable:**

    ```bash
    ./image_convolution
    ```

## Functions

### `fill_img`

Fills the image array with random numbers between 0 and 255.

### `fill_kernel`

Fills the kernel array with random numbers between -10 and 10.

### `padding`

Pads the image array to prepare it for convolution.

### `convolution`

Performs the convolution operation on the padded image using the kernel.

### `print`

Prints a 2D array dynamically.

## Contributing

Contributions are welcome! If you have any ideas, improvements, or bug fixes, feel free to open an issue or create a pull request.

## License

This project is licensed under the [GNU v3 GPL License](LICENSE).

---

*Note: Further effort is required to enhance the program, and any contributions toward improvement are highly appreciated.*
