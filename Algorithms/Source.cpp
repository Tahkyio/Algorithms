#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "Functions.h"
//#include <chrono.h>

void printArray(int* array, int len)  //��� �������� ����� ����
{
	for (int i = 0; i < len; i++) std::cout << array[i] << " ";
	std::cout << "\n";
}

int main()
{
	int n = 0, cityCount = 0, start = 10000000, currentCity=0, cost = 0, minCost = 10000000, i_city=0;
	int* cityCheck = nullptr;
	int** matrix = nullptr;
	/////////////////////////////////////////////////////////////////
	std::cout << "How many cities are there?\nn="; std::cin >> n;
	std::cout << "What is the starting point? From 1 to n\n";

	do {											  //�������� �� ������
		std::cout << "start="; std::cin >> start;
		if (start > n) std::cout << "There are only " << n << " cities!\n";
		else if(start<=0) std::cout << "You can't choose this starting point\n";
	} while (start > n || start<=0);

	if (start == 0) start++;						 //� ������ ������ �� 1 �� n, � �� �� 0 ��� �����������
	currentCity = --start; 

	////////////

	cityCheck = new int[n];
	for (int i = 0; i < n; i++)
		cityCheck[i] = 0;
	cityCheck[start] = 1;							 //�� ������ ��������!!
	//printArray(cityCheck, n);
	matrix = generateDynMatrix(matrix, n);
	fill_costDynMatrix(matrix, n);
	printDynMatrix(matrix, n);

	while (cityCount<n-1)			///////����� ��������
	{
		std::cout << currentCity+1 << "->";
		minCost = 1000000000;
		for (int j = 0; j < n; j++) 
		{
			if (minCost > matrix[currentCity][j] && cityCheck[j]==0 && matrix[currentCity][j] !=0) //���� ������ ����������� ��������� �� ��������� ������ 
													//������ ������� �����, ����� �� �� ���������� � ������ �� ���� �������
			{
				minCost = matrix[currentCity][j];
				i_city = j;								//���������� �����, ���� �������� ���� ����������
			}
		}
		cost += minCost;								//���������� ����������� ��������� ���������� � �����
		cityCheck[i_city]++;							//�������, ��� � ���� ������ �� ��� ����
		cityCount++;									//������������ �� �������  PS. ��� ����� ������������ � ����������� �����? 
		currentCity = i_city;							//����� ����������� ������� ������� ����� �������, �� �� ������� ��� ��������

		
		//std::cout << currentCity <<" " << cityCount << "\n";    
		//printArray(cityCheck,n);
	}
	std::cout <<currentCity+1<< "\nMinimal total cost: " << cost <<"\n";

	/////////////////////////////////////////////////////////////////
	delete[] cityCheck; 
	clearDynMatrix(matrix,n);
	return 0;
}