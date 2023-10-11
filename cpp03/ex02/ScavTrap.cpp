#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_health_pts = _max_health;
	this->_m_health = _max_health;
	this->_energy_pts = _max_energy;
	this->_attack_dmg = _set_attack_dmg;
	this->_name_class = "ScavTrap";
	this->_guard_gate = false;
	std::cout << _name_class << " void constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guard_gate(false)
{
	this->_health_pts = _max_health;
	this->_m_health = _max_health;
	this->_energy_pts = _max_energy;
	this->_attack_dmg = _set_attack_dmg;
	this->_name_class = "ScavTrap";
	std::cout << _name_class << " name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy), _guard_gate(copy._guard_gate)
{
	std::cout << _name_class << " copy constructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << _name_class << " " << this->_name;
	if (this->_health_pts <= 0)
	{
		std::cout << " is not in this world anymore so... Can't attack " << target << std::endl;
		return ;
	}
	else if (this->_energy_pts <= 0)
	{
		std::cout << " not have enough energy so... Can't attack " << target << std::endl;
		return ;
	}
	std::cout << " attack FURIOUSLY " << target << ", causing ";
	std::cout << this->_attack_dmg << " points of damage!" << std::endl;
	this->_energy_pts--;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << _name_class << " destructor called" << std::endl;
}

std::string	ScavTrap::get_name_class(void) const
{
	return (this->_name_class);
}

void	ScavTrap::guarGate(void)
{
	std::cout << _name_class << " " << this->_name;
	if (this->_health_pts <= 0)
	{
		std::cout << " is dead so... Can't guard the gate" << std::endl;
		_guard_gate = false;
		return ;
	}
	else if (_guard_gate == false)
	{
		std::cout << " start guarding the gate" << std::endl;
		_guard_gate = true;
	}
	else if (_guard_gate == true)
	{
		std::cout << " stop guarding the gate" << std::endl;
		_guard_gate = false;
	}
	
}

ScavTrap   &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_guard_gate = rhs._guard_gate;
		this->_name = rhs._name;
		this->_health_pts = rhs._health_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_dmg = rhs._attack_dmg;
		this->_m_health = rhs._m_health;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const ScavTrap &i)
{
	out << i.get_name_class() << " " << i.get_name();
	out << " guard gate status = " << i._guard_gate;
	out << " he got " << i.get_health();
	out << " health points and " << i.get_energy() << " energy" << std::endl;
	return (out);
}