#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {

public:
	Array() : _arr(NULL), _len(0) {}
	Array(unsigned int n) : _arr(new T[n]), _len(n) {}
	Array(const Array<T> &src) : _len(src._len) {
		if (src._len) {
			_arr = new T[src._len];
			for (size_t i = 0; i < _len; i++)
				_arr[i] = src._arr[i];
		} else
			_arr = NULL;
	}

	Array &operator=(const Array<T> &rhs) {
		if (this != &rhs) {
			delete[] _arr;
			_arr = new T[rhs._len];
			_len = rhs._len;
			for (size_t i = 0; i < _len; i++)
				_arr[i] = rhs._arr[i];
		}
		return *this;
	}

	T	&operator[](size_t i) {
		if (i >= _len || !_arr)
			throw OutOfArrayException();
		return _arr[i];
	}

	size_t	size() const {
		return _len;
	}

	class OutOfArrayException : public std::exception {
		virtual const char *what() const throw() {
			return "Array index out of bounds";
		}
	};

private:
	T 		*_arr;
	size_t	_len;
};

template <typename T>
std::ostream &operator<<(std::ostream &oStream, Array<T> &src) {
	oStream << "[ ";
	for (size_t i = 0; i < src.size(); i++)
		oStream << src[i] << " ";
	oStream << "]";
	return oStream;
};

#endif