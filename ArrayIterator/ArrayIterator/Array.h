#pragma once

#include <cassert>

template<typename Array>
class ArrayIterator
{
public:

	using T = typename Array::Type;

private:

	T* pointer;

public:

	ArrayIterator(T* pointer) : pointer(pointer) {}

	T& operator*()
	{
		return *pointer;
	}

	T* operator->()
	{
		return pointer;
	}

	ArrayIterator& operator++()
	{
		pointer++;
		return *this;
	}

	ArrayIterator operator++(int)
	{
		ArrayIterator iterator = *this;
		pointer++;
		return iterator;
	}

	ArrayIterator& operator--()
	{
		pointer--;
		return *this;
	}

	ArrayIterator operator--(int)
	{
		ArrayIterator iterator = *this;
		pointer--;
		return iterator;
	}

	bool operator==(const ArrayIterator& other)
	{
		return pointer == other.pointer;
	}

	bool operator!=(const ArrayIterator& other)
	{
		return !(*this == other);
	}
};


template<typename T, size_t size>
class Array
{
private:

	T array[size];

public:

	using Type = T;
	using Iterator = ArrayIterator<Array<T, size>>;

public:

	constexpr size_t Size() const
	{
		return size;
	}

	T& operator[](size_t index)
	{
		assert(index < size);
		return array[index];
	}

	const T& operator[](size_t index) const
	{
		assert(index < size);
		return array[index];
	}

	Iterator begin()
	{
		return Iterator(array);
	}

	Iterator end()
	{
		return Iterator(array + size);
	}
};
