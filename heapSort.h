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
void heapify(T* arr, size_t size, size_t  index)
{
	size_t largestElementByIndex = index;   //root
	size_t leftElementIndex = 2 * index + 1;  // left node
	size_t rightElementIndex = 2 * index + 2;  // right node
											   //findest the largest node
	if (leftElementIndex < size && arr[largestElementByIndex] < arr[leftElementIndex])
	{
		largestElementByIndex = leftElementIndex;
	}
	if (rightElementIndex < size && arr[largestElementByIndex] < arr[rightElementIndex])
	{
		largestElementByIndex = rightElementIndex;
	}
	if (largestElementByIndex != index)
	{
		swapElements(arr[index], arr[largestElementByIndex]);
		heapify(arr, size, largestElementByIndex);          // Recursively heapify the affected sub-tree
	}
}

template <typename T>
void heapSort(T arr[], size_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)			// Build heap (rearrange array) 
	{
		heapify(arr, size, i);
	}
	for (int i = size - 1; i >= 0; i--)           // One by one extract an element from heap 
	{
		swapElements(arr[0], arr[i]);           // Move current root (max Element) to end 
		heapify(arr, i, 0);						// call max heapify on the reduced heap (finds the i-th largest node) 
	}
}
