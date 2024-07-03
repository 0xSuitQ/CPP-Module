#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
private:
	std::string _type;
public:
	Weapon(const std::string &type);
	~Weapon(void);

	const std::string	&getType() const;
	void		setType(const std::string &newType);
};

#endif