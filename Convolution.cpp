//Program For image convolution
// For an assignment, get image, create random kernel(if req) and then convolution.
// Further effort required

//header files
#include<iostream>
#include<iomanip>
#include<ctime>
#include<stdlib.h>
using namespace std;


//functon prototype
//each works with dynamic arrays.
void fill_img(int**, int, int);
void fill_kernel(int**, int, int);
void padding(int**, int**);
void convolution(int**, int**, int**);
void print(int**, int, int);


int main() {



	//declare image, padded, kernel and final image
	auto** img = new int* [6];
	auto** final_img = new int* [6];
	auto** pad = new int* [8];
	auto** kernel = new int* [3];

	//dynamically allocate memory for arrays
	for (int i = 0; i < 6; i++) {
		img[i] = new int[6];
		final_img[i] = new int[6];
	}
	for (int i = 0; i < 8; i++) {
		pad[i] = new int[8];
	}
	for (int i = 0; i < 3; i++) {
		kernel[i] = new int[3];
	}


	//get random image and kernel
	fill_img(img, 6, 6);
	fill_kernel(kernel, 3, 3);

	//printing image matrix
	cout << "\nOrignal image: \n\n";
	print(img, 6, 6);

	//print kernel
	cout << "\n\nKernel:\n\n";
	print(kernel, 3, 3);


	//padding of the image
	padding(pad, img);

	//printing the padded image
	cout << "\n\nPadded image: \n\n";
	print(pad, 8, 8);


	//convulating
	convolution(pad, final_img, kernel);

	//printing resultant image

	cout << "\n\nResultant image: \n\n";
	print(final_img, 6, 6);

	// Deallocate memory for img


	// Deallocate memory for final_img
	for (int i = 0; i < 6; ++i) {
		delete[] img[i];
		delete[] final_img[i];
	}
	delete[] img;
	delete[] final_img;

	//Deallocate memory for kernel
	for (int i = 0; i < 3; i++)
		delete[] kernel[i];
	delete[] kernel;

	// Deallocate memory for pad
	for (int i = 0; i < 8; ++i)
		delete[] pad[i];
	delete[] pad;


	getchar();
	return 0;
}


//FUNCTION DEFINITONS

//fill the image with random number between 0-255
void fill_img(int** arr, int row, int columns)
{
	srand(time(0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = 0;
			arr[i][j] = rand() % 256;
		}
	}
}

//fill image with random numbers from 0-10
void fill_kernel(int** arr, int row, int columns)
{
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = 0;
			arr[i][j] = rand() % 11 - 11;
		}
	}
}

//dynamically print arrays
void print(int** arr, int row, int column)
{

	for (int i = 0; i < row; i++)
	{
		cout << "|";
		for (int j = 0; j < column; j++)
		{
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << " |" << endl;
	}

}


//padding of image
void padding(int** pad, int** img)
{
	// Initialize the entire pad array to zero
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pad[i][j] = 0;
		}
	}

	// Copy the img array to the center of the pad array
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			pad[i + 1][j + 1] = img[i][j];
		}
	}
}


//function that is used for convolution
void convolution(int** pad, int** fi, int** kernel)
{
	int i, j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
		{
			fi[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					fi[i][j] += pad[i + k][j + l] * kernel[k][l];
				}
			}
		}
	}
}

