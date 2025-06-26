#pragma once

#include <iostream>
#include <cassert>

#include "Constants.h"

namespace CustomizedString {
	struct CharArray {
		char* data = nullptr;
		int capacity = 0;
		int length = 0;
	};

	CharArray createCharArray(const int capacity);
	void addToCharArray(CharArray& str, const char value);
	void deleteCharArray(CharArray& str);
	void removeFromCharArray(CharArray& str);
	void printCharArray(const CharArray& str);
	char getCharArrayBack(const CharArray& str);
}

namespace CustomizedVector {
	struct IntArray {
		int* data = nullptr;
		int capacity = 0;
		int length = 0;
	};

	IntArray createIntArray(const int capacity);
	void addToIntArray(IntArray& arr, const int value);
	void deleteIntArray(IntArray& arr);
	void removeFromIntArray(IntArray& arr);
	void printIntArray(const IntArray& arr);
	int getIntArrayBack(const IntArray& arr);
}

namespace CustomizedStack {
	struct Stack {
		int data[ProjectConstants::MAX_STACK_SIZE]{};
		//int peek = 0;
		int peek = -1;
	};

	void addToStack(Stack& stack, const int value);
	void deleteFromStack(Stack& stack);
	int getStackTop(const Stack& stack);
	int getStackSize(const Stack& stack);
}
