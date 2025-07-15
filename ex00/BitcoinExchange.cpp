/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:58:32 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/20 16:41:30 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool	BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	
	if (!file.is_open())
	{
		std::cerr << "Error: unable to open database file" << std::endl;
		return (false);
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		float				rate;
		//char				comma;
		
		if (std::getline(ss, date, ',') && ss >> rate)
			_database[date] = rate;
		else
			std::cerr << "Error: invalid database entry: " << line << std::endl;
	}
	file.close();
	return (true);
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int					year;
	int					month;
	int					day;
	char				dash1;
	char				dash2;
	std::stringstream	ss(date);

	ss >> year >> dash1 >> month >> dash2 >> day;
	if (ss.fail() || dash1 != '-' || dash2 != '-' || year < 2009 ||
			month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	int		daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool	isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month == 2 && isLeapYear)
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidValue(float value)
{
	return (value >= 0 && value <= 1000);
}

float	BitcoinExchange::getExchangeRate(const std::string& date)
{
	std::map<std::string, float>::iterator it = _database.lower_bound(date);
	
	if (it == _database.end() || it->first != date)
	{
		if (it == _database.begin())
			throw (std::runtime_error("no exchange rate available for date"));
		--it;
	}
	return (it->second);
}

void	BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		std::string			value_str;
		//char				pipe;

		if (std::getline(ss, date, '|') && ss >> value_str)
		{
			date.erase(date.find_last_not_of(" \t") + 1);
			value_str.erase(0, value_str.find_first_not_of(" \t"));
			float	value = std::atof(value_str.c_str());
			if (!isValidDate(date))
			{
				std::cerr << "Error: invalid date => " << date << std::endl;
				continue ;
			}
			if (!isValidValue(value))
			{
				std::cerr << "Error: invalid value => " << value << std::endl;
				continue ;
			}
			try
			{
				float	rate = getExchangeRate(date);
				std::cout	<< date << " => " << value << " = "
							<< value * rate << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr	<< "Exception: " << e.what()
							<< " => " << date << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	file.close();
}
