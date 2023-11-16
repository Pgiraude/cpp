#include "BitcoinExchange.hpp"


int CSV_processing(std::map<std::string, float> &csv, char **argv)
{
    std::ifstream dataFile(argv[1]);
    std::string line;
    std::getline(dataFile, line);
    std::getline(dataFile, line);
    // while (std::getline(dataFile, line).eof())
    // {
        std::size_t pos = line.find(",");

        std::stringstream ss;
        ss << line.substr(pos);
        float value;
        ss >> value;
        csv[line.substr(0, pos)] = value;
        std::cout << csv.begin()->first << " " << csv.begin()->second << std::endl;
        
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