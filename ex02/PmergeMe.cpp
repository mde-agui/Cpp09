/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 00:08:06 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/27 19:18:41 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

long	PmergeMe::getTimeMicroseconds()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000L + tv.tv_usec);
}

void	PmergeMe::binaryInsertVector(std::vector<int>& arr, int value, size_t end)
{
	size_t	left = 0;
	size_t	right = end;

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	arr.insert(arr.begin() + left, value);
}

void	PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return ;

	std::vector<int>	mainChain;
	std::vector<int>	pendElements;
	size_t				i;

	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		mainChain.push_back(arr[i]);
		pendElements.push_back(arr[i + 1]);
	}

	int	unpaired = -1;
	if (i < arr.size())
		unpaired = arr[i];

	fordJohnsonSortVector(mainChain);

	arr.clear();
	for (size_t j = 0; j < mainChain.size(); ++j)
			arr.push_back(mainChain[j]);
	if (pendElements.empty())
	{
		if (unpaired != -1)
			binaryInsertVector(arr, unpaired, arr.size());
		return ;
	}

	binaryInsertVector(arr, pendElements[0], arr.size());

	std::vector<size_t>	jacobsthal;
	jacobsthal.push_back(1);
	if (pendElements.size() > 1)
	{
		jacobsthal.push_back(3);
		while (jacobsthal.back() <= pendElements.size())
		{
			size_t	next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
			jacobsthal.push_back(next);
		}
	}

	std::vector<bool>	inserted(pendElements.size(), false);
	inserted[0] = true;
	for (size_t k = 1; k < jacobsthal.size(); ++k)
	{
		size_t	start = jacobsthal[k - 1] + 1;
		size_t	end = std::min(jacobsthal[k], pendElements.size());
		for (size_t idx = end; idx >= start; --idx)
		{
			size_t	penIdx = idx - 1;
			if (penIdx < inserted.size() && !inserted[penIdx])
			{
				binaryInsertVector(arr, pendElements[penIdx], arr.size());
				inserted[penIdx] = true;
			}
			if (idx == 1)
				break ;
		}
	}

	for (size_t i = 0; i < inserted.size(); ++i)
	{
		if (!inserted[i])
			binaryInsertVector(arr, pendElements[i], arr.size());
	}

	if (unpaired != -1)
		binaryInsertVector(arr, unpaired, arr.size());
}

void	PmergeMe::binaryInsertDeque(std::deque<int>& arr, int value, size_t end)
{
	size_t	left = 0;
	size_t	right = end;

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	arr.insert(arr.begin() + left, value);
}

void	PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return ;

	std::deque<int>	mainChain;
	std::deque<int>	pendElements;
	size_t				i;

	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		mainChain.push_back(arr[i]);
		pendElements.push_back(arr[i + 1]);
	}

	int	unpaired = -1;
	if (i < arr.size())
		unpaired = arr[i];

	fordJohnsonSortDeque(mainChain);

	arr.clear();
	for (size_t j = 0; j < mainChain.size(); ++j)
			arr.push_back(mainChain[j]);
	if (pendElements.empty())
	{
		if (unpaired != -1)
			binaryInsertDeque(arr, unpaired, arr.size());
		return ;
	}

	binaryInsertDeque(arr, pendElements[0], arr.size());

	std::deque<size_t>	jacobsthal;
	jacobsthal.push_back(1);
	if (pendElements.size() > 1)
	{
		jacobsthal.push_back(3);
		while (jacobsthal.back() <= pendElements.size())
		{
			size_t	next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
			jacobsthal.push_back(next);
		}
	}

	std::vector<bool>	inserted(pendElements.size(), false);
	inserted[0] = true;
	for (size_t k = 1; k < jacobsthal.size(); ++k)
	{
		size_t	start = jacobsthal[k - 1] + 1;
		size_t	end = std::min(jacobsthal[k], pendElements.size());
		for (size_t idx = end; idx >= start; --idx)
		{
			size_t	penIdx = idx - 1;
			if (penIdx < inserted.size() && !inserted[penIdx])
			{
				binaryInsertDeque(arr, pendElements[penIdx], arr.size());
				inserted[penIdx] = true;
			}
			if (idx == 1)
				break ;
		}
	}

	for (size_t i = 0; i < inserted.size(); ++i)
	{
		if (!inserted[i])
			binaryInsertDeque(arr, pendElements[i], arr.size());
	}

	if (unpaired != -1)
		binaryInsertDeque(arr, unpaired, arr.size());
}

void	PmergeMe::process(int argc, char** argv)
{
	if (argc < 2)
		throw (std::runtime_error("try using ./PmergeMe <positive ints>"));
	for (int i = 1; i < argc; ++i)
	{
		std::stringstream	ss(argv[i]);
		int					num;
		if (!(ss >> num) || num <= 0)
			throw (std::runtime_error("invalid input: " + std::string(argv[i])));
		_vec.push_back(num);
	_deq.push_back(num);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	long	start = getTimeMicroseconds();
	fordJohnsonSortVector(_vec);
	long	vecTime = getTimeMicroseconds() - start;

	start = getTimeMicroseconds();
	fordJohnsonSortDeque(_deq);
	long	deqTime = getTimeMicroseconds() - start;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout	<< "Time to process a range of " << _vec.size()
				<< " elements with std::vector: "
				<< std::fixed << std::setprecision(6)
				<< vecTime / 1000000.0 << " seconds" << std::endl;
	std::cout	<< "Time to process a range of " << _deq.size()
				<< " elements with std::deque: "
				<< std::fixed << std::setprecision(6)
				<< deqTime / 1000000.0 << " seconds" << std::endl;

}
