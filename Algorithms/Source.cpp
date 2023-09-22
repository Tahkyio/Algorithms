#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "Functions.h"
//#include <chrono.h>



int main()
{
	int n = 0; int** matrix=nullptr;
	std::cout << "How big is the matrix?\nn="; std::cin >> n;
	matrix = generateDynMatrix(matrix, n);
	fillDynMatrix(matrix, n);

	printDynMatrix(matrix, n);


	clearDynMatrix(matrix,n);
	_getch();
	return 0;
}