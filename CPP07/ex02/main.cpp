/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <ggiannit@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:58:51 by ggiannit          #+#    #+#             */
/*   Updated: 2023/06/19 09:27:58 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <ctime>
#include <cstdlib>

int main() {
	int * a = new int();
	std::cout << *a << std::endl;
	delete a;

	Array<int> empty(0);
	std::cout << empty.size() << std::endl;

    Array<int> numbers(10);
    int* classic = new int[10];

	std::cout << numbers.size() << std::endl;

    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
        classic[i] = i;
    }
	std::cout << "My array: " << numbers << std::endl;
	std::cout << "Default array: [ ";
	for (size_t i = 0; i < 10; i++)
		std::cout << classic[i] << " ";
	std::cout << "]" << std::endl;

    {
        Array<int> tmp = numbers;
		std::cout << "Copy constructor test: " << tmp << std::endl;

		Array<int> assignedNumbers;
		assignedNumbers = numbers;
		std::cout << "Assignment operator: " << assignedNumbers << std::endl;
    }

    try {
        numbers[-1] = 10;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

	Array<std::string> str_array(5);
	for (int i = 0; i < 5; i++)
		str_array[i] = "str" + std::to_string(i);
	std::cout << "String array = " << str_array << std::endl;

	delete[] classic;
}