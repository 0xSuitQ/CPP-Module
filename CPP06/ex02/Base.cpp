#include "Base.hpp"

Base::~Base() {}

Base *generate() {
	struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    
	switch (currentTime.tv_usec % 3)
	{
	case 0:
		return (new A);
	
	case 1:
		return (new B);
	
	case 2:
		return (new C);
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &bc) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
		(void)b;
	}
	catch (std::exception &bc) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
		(void)c;
	}
	catch (std::exception &bc) {
		std::cout << "Error" << std::endl;
	}	
}