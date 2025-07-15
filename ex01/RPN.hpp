#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stack>
# include <sstream>

class RPN
{
private:
	std::stack<int>	_stack;

	bool	isOperator(const std::string& token);
	void	doOperation(const std::string& op);

public:
	RPN();
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN();

	int	evaluate(const std::string& expression);
};

#endif