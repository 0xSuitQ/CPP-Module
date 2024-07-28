#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &arr, int i) {
	typename T::iterator it = std::find(arr.begin(), arr.end(), i);
	if (it != arr.end() && *it == i)
		return it;
	throw std::exception();
}

#endif