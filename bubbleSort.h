#pragma once
#include "stdafx.h"
#include <iostream>


using namespace std;

template <typename T>
void swapElements(T& element1, T& element2)
{
	T temp = element1;
	element1 = element2;
	element2 = temp;
}


template <typename T>
void bubbleSort(T* arr, size_t size)
{

	bool swapFlag = true;
	for (size_t i = 0; i < size - 1 && swapFlag; i++)
	{
		swapFlag = false;
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swapElements(arr[j], arr[j + 1]);
				swapFlag = true;
			}
		}
	}
}
