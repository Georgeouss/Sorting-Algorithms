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
void selectionSort(T* arr, const size_t size)
{
	size_t minIndex;
	for (size_t i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		swapElements<T>(arr[minIndex], arr[i]);
	}
}
