#pragma once

#include "DataStructures.h"

template <typename T>
inline void freeArrayMemory(T*& arr) {
	delete[] arr;
	arr = nullptr;
}

template <typename T>
inline T* allocArrayMemory(const int size) {
	T* arr = new (std::nothrow) T[size]{};
	assert(arr && "Memory allocation failure.");
	return arr;
}

template <typename T, typename ArrayType>
inline void reallocArrayMemory(ArrayType& array, const int newCapacity) {
	if (array.capacity > newCapacity)
		return;

	T* newData = allocArrayMemory<T>(newCapacity);
	for (int i = 0; i < array.length; i++)
		newData[i] = array.data[i];

	freeArrayMemory(array.data);
	array.data = newData;
	array.capacity = newCapacity;
}
