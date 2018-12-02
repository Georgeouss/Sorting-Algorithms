#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
void mergeArray(T* arr, size_t left, size_t middle, size_t right)
{
	size_t i, j;
	size_t size1 = middle - left + 1;                       // first half
	size_t size2 = right - middle;							// second half
	T* tempArr1 = new T[size1];								// creats the new array
	T* tempArr2 = new T[size2];
	for (i = 0; i < size1; i++)
		tempArr1[i] = arr[left + i];						// fills it
	for (j = 0; j < size2; j++)
		tempArr2[j] = arr[1 + j + middle];

	i = 0;
	j = 0;
	size_t index = left;
	while (i < size1 && j < size2)							//merge the the arrays in sorted one
	{
		if (tempArr1[i] > tempArr2[j])
		{
			arr[index] = tempArr2[j];
			j++;
		}
		else
		{
			arr[index] = tempArr1[i];
			i++;
		}
		index++;
	}
	while (i < size1)										// if any left
	{
		arr[index] = tempArr1[i];
		i++;
		index++;
	}
	while (j < size2)
	{
		arr[index] = tempArr2[j];
		j++;
		index++;
	}
	delete[] tempArr1;									// free the memory
	delete[] tempArr2;
}


template <typename T>
void mergeSortHelper(T arr[], size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;
		mergeSortHelper(arr, left, middle);						// for the two sides
		mergeSortHelper(arr, middle + 1, right);

		mergeArray(arr, left, middle, right);
	}
}

template <typename T>
void mergeSort(T* arr, size_t size)
{
	mergeSortHelper(arr, 0, size - 1);
}
