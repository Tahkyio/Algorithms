#include <stdio.h>
#include <iostream>

int** generateDynMatrix(int** matrix, int n)
{
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	return(matrix);
}

void clearDynMatrix(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void fillDynMatrix(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			 matrix[i][j] = 1+ rand()%100;
}

void printDynMatrix(int **matrix, int n)
{
	if (n <= 30)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf_s("%3d ", matrix[i][j]);
			std::cout << "\n";
		}
	else std::cout << "Matrix is too big to be shown properly, sorry!\n";
}