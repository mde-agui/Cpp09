#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	PmergeMe	pmerge;

	try
	{
		pmerge.process(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
