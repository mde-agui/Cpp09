/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:30:11 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/27 19:11:43 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

bool	RPN::isOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void	RPN::doOperation(const std::string& op)
{
	if (_stack.size() < 2)
		throw (std::runtime_error("not enough operands"));
	int	a = _stack.top();
	_stack.pop();
	int	b = _stack.top();
	_stack.pop();
	switch (op[0])
	{
		case '+':
			_stack.push(a + b);
			break ;
		case '-':
			_stack.push(b - a);
			break ;
		case '*':
			_stack.push(a * b);
			break ;
		case '/':
			if (a == 0)
				throw (std::runtime_error("division by zero"));
			_stack.push(b / a);
			break ;
		default:
			throw (std::runtime_error("invalid operator: " + op));
	}
}

int	RPN::evaluate(const std::string& expression)
{
	std::stringstream	ss(expression);
	std::string			token;

	while (ss >> token)
	{
		if (token.length() == 1 && isdigit(token[0]) && token[0] <= '9')
			_stack.push(token[0] - '0');
		else if (isOperator(token))
			doOperation(token);
		else
			throw (std::runtime_error("invalid token: " + token));
	}
	if (_stack.size() != 1)
		throw (std::runtime_error("invalid expression"));
	return (_stack.top());
}
