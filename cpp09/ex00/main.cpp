#include "BitcoinExchange.hpp"

int check_bisextile(std::string stryear, std::string strmonth, std::string strday)
{
	std::stringstream ss;
	int	year;
	ss << stryear;
	ss >> year;
	ss.clear();
	int	month;
	ss << strmonth;
	ss >> month;
	ss.clear();
	int	day;
	ss << strday;
	ss >> day;
	ss.clear();
	if ((month <= 7 && month % 2 == 1 && day > 31) || (month > 7 && month % 2 == 0 && day > 31))
		return (1);
	if ((month >= 4 && month <= 7 && month % 2 == 0 && day > 30) || (month > 7 && month % 2 == 1 && day > 30))
		return (2);
	if (year % 4 == 0 && month == 2 && day > 29)
		return (3);
	if (year % 4 != 0 && month == 2 && day > 28)
		return (4);
	return (0);
}

int check_date_string(std::string strNumber, int min, int max, std::size_t maxDigit)
{
	for (std::size_t i = 0; i < strNumber.size(); i++)
	{
		if (i >= maxDigit)
			return (1);
		if (!std::isdigit(strNumber[i]))
			return (2);
	}
	int value;
	std::stringstream ss;
	ss << strNumber;
	ss >> value;
	ss.clear();
	if (min == max)
		;
	else if (value < min || value > max)
		return (3);
	return (0);
}

int check_valide_date(std::string date)
{
	int error;
	std::size_t pos1 = date.find("-");
	if (pos1 == std::string::npos)
		return (1);
	if ((error = check_date_string(date.substr(0, pos1), 0, 0, 4)) != 0)
		return (error + 10);
	std::size_t pos2 = date.substr(pos1 + 1).find("-");
	if (pos2 == std::string::npos)
		return (2);
	if ((error = check_date_string(date.substr(pos1 + 1, pos2), 1, 12, 2)) != 0)
		return (error + 20);
	if ((error = check_date_string(date.substr(pos1 + pos2 + 2), 1, 31, 2)) != 0)
		return (error + 30);
	if (date.size() != 10)
		return (3);
	if (check_bisextile(date.substr(0, pos1), date.substr(pos1 + 1, pos2), date.substr(pos1 + pos2 + 2)) != 0)
		return (4);
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
	if (!value[i])
		return (0);
	else
		return (1);
}

int	processing_line(std::string &line, std::string &date, float &value, std::string separator)
{
	std::size_t pos = line.find(separator);
	if (pos == std::string::npos)
		return (1);
	if (line.substr(pos + separator.size()).find(separator) != std::string::npos)
		return (2);
	std::stringstream ss;
	ss << line.substr(pos + separator.size());
	ss >> value;
	ss.clear();
	int error;
	if ((error = check_valide_number(line.substr(pos + separator.size()))) != 0)
		return (error + 100);
	if ((error = check_valide_date(line.substr(0, pos))) != 0)
		return (error + 200);
	date = line.substr(0, pos);
	return (0);
}

int dataFile_processing(std::map<std::string, float> &csv)
{
	int 		count_line = 1;
	float		exchange_rate;
	std::string	date;
	int			error;
	std::string line;

	std::ifstream dataFile("data.csv");
	if (dataFile.fail())
		return (2);
	while (std::getline(dataFile, line))
	{
		if (line == "date,exchange_rate" && count_line == 1)
			;
		else if ((error = processing_line(line, date, exchange_rate, ",")) > 200)
			std::cout << BLUE "Error n°" << error << ": data.csv:" RESET " line n°" << count_line << " not a valide date" << std::endl;
		else if (error > 100)
			std::cout << BLUE "Error n°" << error << ": data.csv:" RESET " line n°" << count_line << " not a valide number" << std::endl;
		else if (error > 0)
			std::cout << BLUE "Error n°" << error << ": data.csv:" RESET " line n°" << count_line << " bad input" << std::endl;
		else
			csv[date] = exchange_rate;
		count_line++;
	}
	dataFile.close();
	return (0);
}

int	inputFile_processing(std::map<std::string, float> &csv, char *input)
{
	int 		count_line = 1;
	float		value;
	std::string	date;
	int			error;
	std::string line;

	std::ifstream inputFile(input);
	if (inputFile.fail())
		return (3);
	while (std::getline(inputFile, line))
	{
		if (line == "date | value" && count_line == 1)
			;
		else if ((error = processing_line(line, date, value, " | ")) > 200)
			std::cout << PURPLE "Error:" RESET " not a valide date => " << line << std::endl;
		else if (error > 100)
			std::cout << PURPLE "Error:" RESET " not a valide number => " << line << std::endl;
		else if (error > 0)
			std::cout << PURPLE "Error:" RESET " bad input => " << line << std::endl;
		else if (value > 1000)
			std::cout << PURPLE "Error:" RESET " too large a number => " << line << std::endl;
		else if (value < 0)
			std::cout << PURPLE "Error:" RESET " not a positive number => " << line << std::endl;
		else if (date < csv.begin()->first)
			std::cout << PURPLE "Error:" RESET " no bitcoin value register at this date and before => " << line << std::endl;
		else
		{
			if (csv.find(date) != csv.end())
				std::cout << date << " => " << value << " = " << value * csv[date] << std::endl;
			else if (date > csv.rbegin()->first)
				std::cout << date << " => " << value << " = " << value * csv.rbegin()->second << YELLOW " (WARNING last value known: " << csv.rbegin()->first << ")" RESET << std::endl;
			else
			{
				std::map<std::string, float>::iterator it = csv.upper_bound(date);
				it--;
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			}
		}
		count_line++;
	}
	inputFile.close();
	return (0);
}

int main(int argc, char **argv)
{
	std::map<std::string, float> csv;

	if (argc != 2)
	{
		std::cout << RED "Error n°1:" RESET " need one argument" << std::endl;
		return (1);
	}
	if (dataFile_processing(csv) != 0)
	{
		std::cout << RED "Error n°2:" RESET " can't open data.csv" << std::endl;
		return (2);
	}
	if (inputFile_processing(csv, argv[1]))
	{
		std::cout << RED "Error n°3:" RESET " can't open " << argv[1] << std::endl;
		return (3);
	}
}