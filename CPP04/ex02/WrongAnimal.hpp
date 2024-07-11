#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"

class WrongAnimal {
protected:
	std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	~WrongAnimal();
	WrongAnimal(const WrongAnimal&);
	WrongAnimal& operator=( const WrongAnimal& rhs );

	void	makeSound() const;
	std::string		getType() const; 
};

#endif