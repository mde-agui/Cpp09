#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_database;

	bool	loadDatabase(const std::string& filename);
	bool	isValidDate(const std::string& date);
	bool	isValidValue(float value);
	float	getExchangeRate(const std::string& date);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	processInput(const std::string& filename);
};

#endif
