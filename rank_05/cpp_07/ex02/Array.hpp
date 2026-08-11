#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
	T*           _arr;
	unsigned int _size;

public:
	Array(void)
	{
		_arr = new T[0];
		_size = 0;
	}

	Array(unsigned int n)
	{
		_arr = new T[n]();
		_size = n;
	}

	Array(const Array& other)
	{
		_arr = new T[0];
		_size = 0;
		*this = other;
	}

	Array & operator=(const Array& other)
	{
		if(this != &other)
		{
			delete[] _arr;
			_arr = new T[other._size]();
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		}
		return *this;
	}

	~Array(void)
	{
		delete[] _arr;
	}

    T & operator[](unsigned int i)
	{
		if(i >= _size)
			throw std::exception();
		return _arr[i];
	}

    T const & operator[](unsigned int i) const
	{
		if(i >= _size)
			throw std::exception();
		return _arr[i];
	}

    unsigned int size(void) const
	{
		return _size;
	}
};

#endif