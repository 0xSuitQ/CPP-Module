/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandroso <nandroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:26:29 by nandroso          #+#    #+#             */
/*   Updated: 2024/08/02 18:26:35 by nandroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	//grade too high
	{
		try {
			Form form0("A99", 0, 5);
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n --------------------- \n\n";
	{
		try {
			Bureaucrat bob("Bob", 15);
			Form form("J33", 20, 45);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";
	// grade is not enough
	{
		try {
			Bureaucrat tim("Tim", 35);
			Form form2("AA1", 20, 45);
			std::cout << tim << std::endl;
			std::cout << form2 << std::endl;
			tim.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
