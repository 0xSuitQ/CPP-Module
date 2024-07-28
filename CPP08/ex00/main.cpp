/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <ggiannit@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:55:06 by ggiannit          #+#    #+#             */
/*   Updated: 2023/06/19 15:43:32 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib>
#include <vector>
#include <list>

void	display(int i) {
	std::cout << i << " ";
}

int	main() {
	
	std::vector<int>	vector;
	std::list<int>		list;

	for (int i = 0; i < 10; i++) {
		vector.push_back(i);
		list.push_back(i);
	}
	for_each(vector.begin(), vector.end(), display);
	std::cout << std::endl;

	int target = 4;
	try {
		std::cout << "Target: " << target << std::endl; 
		std::vector<int>::iterator it = easyfind(vector, target);
		
		std::cout << "Target " << *it << " found" << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Target not found" << std::endl;
	}

	std::cout << std::endl;

	for_each(list.begin(), list.end(), display);
	std::cout << std::endl;
	try {
		std::cout << "Target: " << target << std::endl; 
		std::list<int>::iterator it = easyfind(list, target);

		std::cout << "Target " << *it << " found" << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Target not found" << std::endl;
	}
}

