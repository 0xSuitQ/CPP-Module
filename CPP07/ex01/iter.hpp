#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *arr, size_t len, void (*f)(const T &)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

void to_upper(const char &c) {
    std::cout << static_cast<char>(std::toupper(c));
}

#endif