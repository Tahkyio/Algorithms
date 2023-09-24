#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <chrono>
#include "Functions.h"



void printArray(int* array, int len)  //Для проверки нужно было
{
	for (int i = 0; i < len; i++) std::cout << array[i] << " ";
	std::cout << "\n";
}

int main()
{
	int n = 0, cityCount = 0, start = 10000000, currentCity=0, cost = 0, minCost = 10000000, i_city=0,i=0;
	bool* cityCheck = nullptr;
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
	currentCity = --start;

	///////////////////////////////////////////////////////////////////

	cityCheck = new bool[n];
	for (int i = 0; i < n; i++)						      //Массив, который можно читать как "Могу ли я поехать в этот город?"
		cityCheck[i] = true;
	cityCheck[start] = false;							 //НЕ ЗАБУДЬ ОЧИСТИТЬ!!   Утечка?? Я не понимаю что он хочет
	//printArray(cityCheck, n);

	matrix = generateDynMatrix(matrix, n);
	fillDynMatrix(matrix, n); for (i = 0; i < n; i++) matrix[i][i] = 0;
	printDynMatrix(matrix, n); std::cout << "\n";

	auto begin = std::chrono::steady_clock::now();

	while (cityCount<n-1)			///////Метод перебора
	{
		if(n<30) std::cout << currentCity+1 << "->";
		minCost = 1000000000;
		for (i = 0; i < n; i++) 
		{
			if (minCost > matrix[currentCity][i] && cityCheck[i] && matrix[currentCity][i] !=0) //ищем дорогу минимальной стоимости из НЫНЕШНЕГО города 
													//Второе условие нужно, чтобы мы не зациклилсь и прошли по всем городам
			{
				minCost = matrix[currentCity][i];
				i_city = i;								//запоминаем город, куда значение пути минимально
			}
		}
		cost += minCost;								//Подходящую минимальную стоимость прибавляем к общей
		cityCheck[i_city]=false;							//Говорим, что в этом городе мы уже были
		cityCount++;									//Продвинулись по городам  PS. Нам нужно возвращаться в изначальный город? 
		currentCity = i_city;							//Можно попробовать сделать функцию суммы массива, но не уверена что выгоднее

		
		//std::cout << currentCity <<" " << cityCount << "\n";    
		//printArray(cityCheck,n);
	}
	if (n < 30)std::cout << currentCity + 1<<"\n";
	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	
	std::cout<< "\nMinimal total cost: " << cost <<"\n";
	std::cout << "Calculation time: " << elapsed_ms.count() << " ms\n";
	/////////////////////////////////////////////////////////////////
	delete[] cityCheck; 
	clearDynMatrix(matrix,n);
	return 0;
}