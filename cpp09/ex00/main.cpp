#include "BitcoinExchange.hpp"

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
	if (value < min || value > max)
		return (3);
	return (0);
}

int check_valide_date(std::string date)
{
	int error;
	std::size_t pos1 = date.find("-");
	if (pos1 == std::string::npos)
		return (1);
	if ((error = check_date_string(date.substr(0, pos1), 2009, 2023, 4)) != 0)
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

int	processing_line(std::string &line, std::map<std::string, float> &csv)
{
	std::size_t pos = line.find(",");
	if (pos == std::string::npos)
		return (1);
	if (line.substr(pos + 1).find(",") != std::string::npos)
		return (2);
	std::stringstream ss;
	ss << line.substr(pos + 1);
	float value;
	ss >> value;
	ss.clear();
	int error;
	if ((error = check_valide_number(line.substr(pos + 1))) != 0)
		return (error + 100);
	if ((error = check_valide_date(line.substr(0, pos))) != 0)
		return (error + 200);
	csv[line.substr(0, pos)] = value;
	// std::cout << line + " : " << line.substr(0, pos) << " " << csv[line.substr(0, pos)] << std::endl;
	return (0);
}

int dataFile_processing(std::map<std::string, float> &csv)
{
	int numLine = 1;

	std::ifstream dataFile("data.csv");
	if (dataFile.fail())
		return (2);
	std::string line;
	std::getline(dataFile, line);
	processing_line(line, csv);
	int error;
	while (std::getline(dataFile, line))
	{
		numLine++;
		if ((error = processing_line(line, csv)) > 200)
			std::cout << "Error n°" << error << ": data.csv: line n°" << numLine << " not a valide date" << std::endl;
		else if (error > 100)
			std::cout << "Error n°" << error << ": data.csv: line n°" << numLine << " not a valide number" << std::endl;
		else if (error > 0)
			std::cout << "Error n°" << error << ": data.csv: line n°" << numLine << " bad input" << std::endl;
	}
	dataFile.close();
	return (0);
}

int	inputFile_processing(std::map<std::string, float> &csv, char *input)
{
	std::ifstream inputFile(input);
	if (inputFile.fail())
		return (3);
		
}

int main(int argc, char **argv)
{
	std::map<std::string, float> csv;

	if (argc != 2)
	{
		std::cout << "Error n°1: need one argument" << std::endl;
		return (1);
	}
	if (dataFile_processing(csv) != 0)
	{
		std::cout << "Error n°2: can't open data.csv" << std::endl;
		return (2);
	}
	if (inputFile_processing(csv, argv[1]))
	{
		std::cout << "Error n°3: can't open " << argv[1] << std::endl;
		return (3);
	}
}