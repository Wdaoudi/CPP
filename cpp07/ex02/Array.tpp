template <typename T>
Array<T>::Array()
	: _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _size(n)
{
	if (n > 0)
		_array = new T[n]();
	else
		_array = NULL;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (_array)
			delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::Array(Array const &src)
	: _array(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfRangeException();
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
