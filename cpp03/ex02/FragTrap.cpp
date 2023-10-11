#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_m_health = _max_health;
	this->_health_pts = _max_health;
	this->_energy_pts = _max_energy;
	this->_attack_dmg = _set_attack_dmg;
	this->_name_class = "FragTrap";
	std::cout << this->_name_class << " void constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_m_health = _max_health;
	this->_health_pts = _max_health;
	this->_energy_pts = _max_energy;
	this->_attack_dmg = _set_attack_dmg;
	this->_name_class = "FragTrap";
	std::cout << this->_name_class << " name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << this->_name_class << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name_class << " destructor called" << std::endl;
}

std::string	FragTrap::get_name_class(void) const
{
	return (this->_name_class);
}

void	FragTrap::HighFivesGuys(void)
{
	std::cout << this->_name_class << " " << this->_name;
	if (this->_health_pts <= 0)
	{
		std::cout << " is dead so... Can't request a high Five" << std::endl;
		return ;
	}
	std::cout << " is giving you a friendly high five!" << std::endl;
}

FragTrap   &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health_pts = rhs._health_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_dmg = rhs._attack_dmg;
		this->_m_health = rhs._m_health;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const FragTrap &i)
{
	out << i.get_name_class() << " " << i.get_name();
	out << " got " << i.get_health();
	out << " health points and " << i.get_energy() << " energy" << std::endl;
	return (out);
}