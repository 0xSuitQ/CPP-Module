#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <sys/time.h>

class Base {
public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate();
void identify(Base* p);
void identify(Base& p);

#endif