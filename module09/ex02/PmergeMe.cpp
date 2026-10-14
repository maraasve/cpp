#include <PmergeMe.hpp>

PmergeMe::PmergeMe(int argc, char *argv[]) {
	parseInput(argc, argv);
	run();
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &src) {
	_vec = src._vec;
	_deq = src._deq;
	_comparisonCount = src._comparisonCount;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_vec = src._vec;
		_deq = src._deq;
		_comparisonCount = src._comparisonCount;
	}
	return *this;
}

long generateJacobstHalAtIdx(long n) { 
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}