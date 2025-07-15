/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:02:23 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/20 16:42:21 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Error: try using ./btc <input_file>"
					<< std::endl;
		return (1);
	}
	BitcoinExchange	exchange;
	exchange.processInput(argv[1]);
	return (0);
}
