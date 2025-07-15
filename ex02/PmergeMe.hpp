#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <exception>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>
# include <iomanip>


class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	void	fordJohnsonSortVector(std::vector<int>& arr);
	void	fordJohnsonSortDeque(std::deque<int>& arr);
	long	getTimeMicroseconds();

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe();

	void	binaryInsertVector(std::vector<int>& arr, int value, size_t end);
	void	binaryInsertDeque(std::deque<int>& arr, int value, size_t end);
	void	process(int argc, char** argv);
};

#endif
