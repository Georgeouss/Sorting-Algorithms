#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
void insertionSort(T* arr, size_t size)
{
	size_t j;
	T key;
	for (size_t i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}