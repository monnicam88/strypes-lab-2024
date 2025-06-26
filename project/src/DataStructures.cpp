#include "MemoryManagement.h"

CustomizedString::CharArray CustomizedString::createCharArray(const int capacity) {
    CustomizedString::CharArray str;
	str.data = allocArrayMemory<char>(capacity);
	str.capacity = capacity;
    return str;
}

void CustomizedString::addToCharArray(CustomizedString::CharArray& str, const char value) {
	if (str.length + 1 == str.capacity)
		reallocArrayMemory<char, CustomizedString::CharArray>
		(str, str.capacity * ProjectConstants::CAPACITY_RESIZER);
	str.data[str.length++] = value;
}

void CustomizedString::deleteCharArray(CustomizedString::CharArray& str) {
	freeArrayMemory(str.data);
	str.capacity = str.length = 0;
}

void CustomizedString::removeFromCharArray(CustomizedString::CharArray& str) {
    assert(str.length > 0 && "Removing from empty CharArray.");
	str.data[--str.length] = 0;
}

void CustomizedString::printCharArray(const CustomizedString::CharArray& str) {
	for (int i = 0; i < str.length; i++)
		std::cout << str.data[i] << " ";
	std::cout << std::endl;
}

char CustomizedString::getCharArrayBack(const CustomizedString::CharArray& str) {
    assert(str.length > 0 && "CharArray is empty.");
    return str.data[str.length - 1];
}

CustomizedVector::IntArray CustomizedVector::createIntArray(const int capacity) {
	CustomizedVector::IntArray arr;
	arr.data = allocArrayMemory<int>(capacity);
	arr.capacity = capacity;
	return arr;
}

void CustomizedVector::addToIntArray(CustomizedVector::IntArray& arr, const int value) {
	if (arr.length + 1 == arr.capacity)
		reallocArrayMemory<int, CustomizedVector::IntArray>
		(arr, arr.capacity * ProjectConstants::CAPACITY_RESIZER);
	arr.data[arr.length++] = value;
}

void CustomizedVector::deleteIntArray(CustomizedVector::IntArray& arr) {
	freeArrayMemory(arr.data);
	arr.capacity = arr.length = 0;
}

void CustomizedVector::removeFromIntArray(CustomizedVector::IntArray& arr) {
	assert(arr.length > 0 && "Removing from empty IntArray.");
	arr.data[--arr.length] = 0;
}

void CustomizedVector::printIntArray(const CustomizedVector::IntArray& arr) {
	for (int i = 0; i < arr.length; i++)
		std::cout << arr.data[i] << " ";
	std::cout << std::endl;
}

int CustomizedVector::getIntArrayBack(const CustomizedVector::IntArray& arr) {
	assert(arr.length > 0 && "IntArray is empty.");
	return arr.data[arr.length - 1];
}

void CustomizedStack::addToStack(CustomizedStack::Stack& stack, const int value) {
	assert(stack.peek < ProjectConstants::MAX_STACK_SIZE && "Exceed stack capacity.");
	//stack.data[stack.peek++] = value;
	stack.data[++stack.peek] = value;
}

void CustomizedStack::deleteFromStack(CustomizedStack::Stack& stack) {
	assert(/*stack.peek > 0*/stack.peek >= 0 && "Removing from empty stack.");
	stack.data[stack.peek--] = 0;
}

int CustomizedStack::getStackTop(const CustomizedStack::Stack& stack) {
	assert(/*stack.peek > 0*/stack.peek >= 0 && "Peeking empty stack.");
	return stack.data[stack.peek];
}

int CustomizedStack::getStackSize(const CustomizedStack::Stack& stack) {
	return stack.peek + 1;
}
