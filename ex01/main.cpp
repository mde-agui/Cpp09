/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:46:09 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/20 18:50:11 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: try using ./RPN <expression>" << std::endl;
		return (1);
	}
	RPN	rpn;
	try
	{
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}