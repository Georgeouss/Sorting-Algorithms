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
size_t findMinIndex(T* arr, size_t e1, size_t e2)
{
	return arr[e1] < arr[e2] ? e1 : e2;
}

template <typename T>
size_t findMaxIndex(T* arr, size_t e1, size_t e2)
{
	return arr[e1] > arr[e2] ? e1 : e2;
}

template <typename T>
int middleIndexByValue(const T* arr, size_t minIndex, size_t midIndex, size_t maxIndex)
{																					// finds maxIndex by value , the second highest
	if (arr[minIndex] <= arr[midIndex] && arr[midIndex] <= maxIndex)                // and returns the less higher (the middle one)   
	{
		return findMinIndex(arr, findMaxIndex(arr, minIndex, midIndex), maxIndex);
	}
	if (arr[midIndex] <= arr[maxIndex] && arr[maxIndex] <= midIndex)
	{
		return findMinIndex(arr, findMaxIndex(arr, minIndex, maxIndex), midIndex);
	}
	else
	{
		return findMinIndex(arr, findMaxIndex(arr, midIndex, midIndex), minIndex);
	}
}

template <typename T>
int partition(T* arr, int minIndex, int maxIndex)
{
	int index = middleIndexByValue(arr, minIndex, (maxIndex + minIndex) / 2, maxIndex);
	swapElements(arr[index], arr[maxIndex]); //puts the "middle" in the back
	T pivot = arr[maxIndex];
	int i = minIndex;  // Index of smaller element 
	for (int j = minIndex; j < maxIndex; j++)
	{
		if (arr[j] <= pivot)                     // If current element is smaller than or 									
		{										 // equal to pivot 
			swapElements(arr[i++], arr[j]);
		}
	}
	swapElements(arr[i + 1], arr[maxIndex]); // puts the pivot in the correct postion
	return i + 1;
}

template <typename T>
void quickSortHelper(T* arr, int minIndex, int maxIndex)
{
	while (minIndex < maxIndex)
	{
		int pi = partition1(arr, minIndex, maxIndex);

		if (pi - minIndex < maxIndex - pi)				// If left part is smaller, then recur for left 
		{												// part and handle right part iteratively 
			quickSortHelper(arr, minIndex, pi - 1);
			minIndex = pi + 1;
		}
		else											 // Else recur for right part				
		{
			quickSortHelper(arr, pi + 1, maxIndex);
			maxIndex = pi - 1;
		}
	}
}
template <typename T>
void quickSort(T* arr, size_t size)
{
	quickSortHelper(arr, 0, size - 1);
}