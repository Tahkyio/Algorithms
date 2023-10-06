#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <chrono>
#include "Functions.h"




int main()
{
	int n = 0, start = 10000000, cost=0;
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

	do {											  //Ïðîâåðêà íà äóðàêà
		std::cout << "start="; std::cin >> start;
		if (start > n) std::cout << "There are only " << n << " cities!\n";
		else if(start<=0) std::cout << "You can't choose this starting point\n";
	} while (start > n || start<=0);
	std::cout << "\n";
	start--;

	///////////////////////////////////////////////////////////////////
	int i = 0;
	array_P = new int[n];					 //ÍÅ ÇÀÁÓÄÜ Î×ÈÑÒÈÒÜ!!  
	for (i = 0; i < n; i++)
		array_P[i] = i + 1;

	matrix = generateDynMatrix(matrix, n);

	fillDynMatrix(matrix, n); for (i = 0; i < n; i++) matrix[i][i] = 0;
	printDynMatrix(matrix, n); std::cout << "\n";

	//auto begin = std::chrono::steady_clock::now();
	int j = 0, k = 0, needed_i = 0, needed_j = 0;
	for (i = 0; i < calculatePermutation(n)-1; i++)
	{
		printArray(array_P, n);
		int tmp = 0;
		for (j = 1; j < n - 1 && array_P[j - 1] < array_P[j]; j++)
			needed_i = j;

		for (j = needed_i+1; j <n-1; j++)
			if(array_P[needed_i] < array_P[j]) needed_j = j;


		tmp = array_P[needed_i];
		array_P[needed_i] = array_P[needed_j];
		array_P[needed_j] = tmp;

		if (needed_i!=n-2)
		for (j = needed_i + 1, k = n - 1; j < k; j++,k--)
		{
			tmp = array_P[j];
			array_P[j] = array_P[k];
			array_P[k] = tmp;
		}
	}




	//auto end = std::chrono::steady_clock::now();

	//auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	
	std::cout<< "\nMinimal total cost: " << cost <<"\n";
	//std::cout << "Calculation time: " << elapsed_ms.count() << " ms\n";
	/////////////////////////////////////////////////////////////////
	delete[] array_P; 
	clearDynMatrix(matrix,n);
	return 0;
}