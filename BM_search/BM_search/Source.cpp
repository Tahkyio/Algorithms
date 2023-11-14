#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using std::vector;
using std::string;

void printTable(int* arr)
{
	for (int i = 0; i < 256; i++)
		std::cout <<char(i)<< ' ' << arr[i] << '\n';
	std::cout << '\n';
}
void printIntVector(vector<int> vect)
{
	for (int i = 0; i < vect.size(); i++)
		std::cout << vect[i]<< ' ';
	std::cout << '\n';
}

void formTable(string word, int* tab)
{
	for (int i = 0; i < 256; i++)
		tab[i] = word.length()-1;
	for (unsigned int i = 0; i < word.length(); i++)
		tab[word[i]] = word.length() - i-1;
}
//this is text
//text
// первый несовпавший символ - s - в слове не встречается - сдвигаем на 4
//this is text
//    text
//снова на 4
//this is text
//        text
//хоба совпало

int BM_Search(string text, string word, int* table)
{
	formTable(word, table);
	for (int unsigned i = word.length() - 1; i < text.length(); i++)
	{
		bool wordFound = true;
		int i_copy = i;
		for (int word_i = word.length() - 1; word_i > 0; word_i--, i_copy--)
			if (word[word_i] != text[i_copy])
			{
				i += table[word[word_i]];
				wordFound = false;
				break;
			}
		if (wordFound)
			return i_copy;
	}

	return -1;
}
void findAll_BMSearch(string text, string word, int* table, vector<int>& index)
{
	if (index.size() != 0)
		index.clear();
	formTable(word, table);
	for (int unsigned i = word.length() - 1; i < text.length(); i++)
	{
		bool wordFound = true;
		int i_copy = i;
		for (int word_i = word.length() - 1; word_i > 0; word_i--, i_copy--)
			if (word[word_i] != text[i_copy])
			{
				i += table[word[word_i]];
				wordFound = false;
				break;
			}
		if (wordFound)
			index.push_back(i_copy);
	}
}

int main()
{
	int* table;
	table = new int[256];
	vector <int> resultIndex;
	string text = "this is a text sample";
	string word1 = "text",word2 = "sample",word3 = "word";
	string testText = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
	string testWord = "tor";
	//Сделать вместо сраных файлов просто массивчики и текстом я не могу с ними работать
	//std::cout << word1.length()<<" "<< typeid(word1.length()).name();
	//std::cout << word1 << "\n";
	//formTable(word1, table);
	//printTable(table);
	std::cout << text<<'\n';
	std::cout <<word1 << " - index = "<< BM_Search(text, word1, table)<<'\n';
	std::cout << word2 << " - index = " << BM_Search(text, word2, table) << '\n';
	std::cout << word3 << " - index = " << BM_Search(text, word3, table) << '\n';
	std::cout << testText << '\n'<< testWord<<" - ";
	findAll_BMSearch(testText, testWord, table, resultIndex);
	printIntVector(resultIndex);

	delete[] table;

	return 0;
}