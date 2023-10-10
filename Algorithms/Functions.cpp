#include <stdio.h>
#include <iostream>

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int min(int a, int b)
{
	if (a < b) return a;
	return b;
}
int calculatePermutation(int n)
{
	int a=1;
	for (int i = 1; i <= n; i++)
		a *= i;
	return a;
}

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

void printArray(int* array, int len)  //Для проверки нужно было
{
	for (int i = 0; i < len; i++) std::cout << array[i] << " ";
	std::cout << "\n";
}