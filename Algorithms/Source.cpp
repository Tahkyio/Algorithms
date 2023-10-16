#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <chrono>
#include "Functions.h"


void findMinPath(int** matrix, const int n, const int start, int* minPath) //осталось сделать нахождение maxPath??
{
	int* array_P=nullptr;
	array_P = new int[n];
	int i, j, needed_i=0, needed_j=0, cost=-1;
	while (true)
	{
		int tmp = 0;
		needed_i = -1;
		//printArray(array_P, n);
		if (cost < 0)
		{
			cost = calculatePathCost(matrix, minPath, n);
			copyArray(minPath, array_P, n, n);
		}
		else
		{ 
			tmp = calculatePathCost(matrix, array_P, n);
			if (tmp < cost)
			{
				copyArray(array_P, minPath, n, n);
				cost = min(cost, tmp);
			}
		}

		for (i = 1; i < n - 1; i++)
		{
			if (array_P[i] < array_P[i + 1])
				needed_i = i;
		}
		if (needed_i == -1 || start < minPath[0])
			break;
		else
		{
			for (j = needed_i + 1; j < n; j++)
				if (array_P[needed_i] < array_P[j])
					needed_j = j;


			tmp = array_P[needed_i];
			array_P[needed_i] = array_P[needed_j];
			array_P[needed_j] = tmp;

			if (needed_i != n - 2)
				for (j = needed_i + 1, i = n - 1; j < i; j++, i--)
				{
					tmp = array_P[j];
					array_P[j] = array_P[i];
					array_P[i] = tmp;
				}
		}
	}
	//std::cout << "array_P: ";  printArray(array_P, n);
	//std::cout << "minPath: "; printArray(minPath, n);
	delete[] array_P;
}

int main()
{
	int n = 0, start = 1, cost=INT_MAX;
	int* array_P = nullptr;
	int** matrix = nullptr;
	/////////////////////////////////////////////////////////////////
	std::cout << "How many cities are there?\n";
	do { 
		std::cout << "n=";  std::cin >> n;
		if (n < 0) std::cout << "The amount of cities can't be negative\n";
		else if (n >= 0 && n <= 1) std::cout << "Add more cities! There's nothing to calculate\n";
	} while (n <= 1);
	std::cout << "What is the starting point? From 1 to n\n";

	do {											  //Проверка на дурака
		std::cout << "start="; std::cin >> start;
		if (start > n) std::cout << "There are only " << n << " cities!\n";
		else if(start<=0) std::cout << "You can't choose this starting point\n";
	} while (start > n || start<=0);
	std::cout << "\n";

	///////////////////////////////////////////////////////////////////

	matrix = generateDynMatrix(matrix, n);

	fillDynMatrix(matrix, n);
	for (int i = 0; i < n; i++)
		matrix[i][i] = 0;
	printDynMatrix(matrix, n); std::cout << "\n";

	auto begin = std::chrono::steady_clock::now();
	int i =0,j= 0;
	array_P = new int[n];					 //НЕ ЗАБУДЬ ОЧИСТИТЬ!! 
	array_P[0] = start;
	for (i = 1, j = 1; i < n; i++, j++)
	{	
		if (i == start)
			array_P[i] = ++j;
		else
			array_P[i] = j;
	}

	findMinPath(matrix, n, start, array_P);
	std::cout << "MinCost Path: ";
	printArray(array_P, n);
	cost = calculatePathCost(matrix, array_P, n);

	auto end = std::chrono::steady_clock::now();
	delete[] array_P;

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

	std::cout<< "Minimal total cost: " << cost <<"\n";
	std::cout << "Calculation time: " << elapsed_ms.count() << " ms\n";

	
	/////////////////////////////////////////////////////////////////
	clearDynMatrix(matrix,n);
	return 0;
}