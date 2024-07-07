#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>

class Harl {

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	typedef void (Harl::*FuncPtr)(void);
	std::map<std::string, FuncPtr> functionMap;

public:
	Harl( void );
	~Harl( void );

	void complain( std::string level );

};

std::string	tolower( std::string str);

#endif