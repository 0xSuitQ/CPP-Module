#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
private:
	Brain*	_brain;
public:
	Cat();
	~Cat();
	Cat(const Cat&);
	Cat& operator=(const Cat& rhs);

	void	makeSound() const;
};

#endif