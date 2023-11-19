#include "BitcoinExchange.hpp"


int check_valide_date(std::string date)
{
	std::size_t pos1 = date.find("-");
	if (pos1 == std::string::npos)
		return (1);
	std::cout << "date raw: "<< date << " pos: " << pos1 << std::endl;
	std::string year = date.substr(0, pos1);
	for (std::size_t i = 0; i < year.size(); i++)
	{
		if (i >= 4)
			return (10);
		if (!std::isdigit(year[i]))
			return (3);
	}
	int value;
	std::stringstream ss;
	ss << year;
	ss >> value;
	ss.clear();
	if (value < 2009 || value > 2023)
		return (4);
	std::size_t pos2 = date.substr(pos1 + 1).find("-");
	if (pos2 == std::string::npos)
		return (5);
	std::string month = date.substr(pos1 + 1, pos2);
	for (std::size_t i = 0; i < month.size(); i++)
	{
		if (i >= 2)
			return (11);
		if (!std::isdigit(month[i]))
			return (6);
	}
	ss << month;
	ss >> value;
	ss.clear();
	std::cout << "month raw: " << month << " pos2: " << pos2  << " value: " << value << std::endl;

	if (value < 1 || value > 12)
		return (7);
	std::string day = date.substr(pos1 + pos2 + 2);
	std::cout << "day raw: " << day << " pos2: " << pos2  << " value: " << value << std::endl;

	for (std::size_t i = 0; i < day.size(); i++)
	{
		if (i >= 2)
			return (12);
		if (!std::isdigit(day[i]))
			return (8);
	}
	ss << day;
	ss >> value;
	ss.clear();
	if (value < 1 || value > 31)
		return (9);
	if (date.size() != 10)
		return (10);
	return (0);
}

int check_valide_number(std::string value)
{
	std::size_t i = 0;
	if (value[i] == '-')
		i++;
	while(std::isdigit(value[i]) && i < value.size())
		i++;
	if (value[i] == '.')
		i++;
	while(std::isdigit(value[i]) && i < value.size())
		i++;
	std::cout << "i=" << i << " value=" << value << std::endl;
	if (!value[i])
		return (0);
	else
		return (1);
}

int CSV_processing(std::map<std::string, float> &csv, char **argv)
{
	std::ifstream dataFile(argv[1]);
	std::string line;
	std::getline(dataFile, line);
	std::getline(dataFile, line);
	// while (std::getline(dataFile, line))
	// {
		std::size_t pos = line.find(",");
		if (pos == std::string::npos)
			return (1);
		std::cout << line.substr(pos + 1) << std::endl;
		if (line.substr(pos + 1).find(",") != std::string::npos)
			return (2);
		std::stringstream ss;
		ss << line.substr(pos + 1);
		float value;
		ss >> value;
		ss.clear();

		int check;
		if ((check = check_valide_number(line.substr(pos + 1))) != 0)
			std::cout << "VALUE return: " << check << std::endl;
		if ((check = check_valide_date(line.substr(0, pos))) != 0)
			std::cout << "DATE return: " << check << std::endl;
		csv[line.substr(0, pos)] = value;
		std::cout << "1st test: " << csv.begin()->first << " " << csv.begin()->second << std::endl;
		
	// }
	return (0);
}

int main(int argc, char **argv)
{
	std::map<std::string, float> csv;

	if (argc != 2)
		return (1);
	CSV_processing(csv, argv);

}