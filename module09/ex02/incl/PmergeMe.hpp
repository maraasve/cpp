#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <chrono>
# include <iomanip>


template <typename Container>
void print(Container &c) {
	for (const auto &value : c) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}


class PmergeMe 
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	_sortedVec;
		std::deque<int>		_sortedDeq;
		size_t				_comparisonCount = 0;


	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();

		void	parseInput(int argc, char *argv[]);
		std::vector<int>	mergeInsertVec(std::vector<int> &vec, size_t pairSize);
		std::deque<int>		mergeInsertDeq(std::deque<int> &deq);
		void	printVec(const std::vector<int> &vec);
		void	printDeq(const std::deque<int> &deq);
		void	run();
		void	binaryInsertVec(std::vector<int> &vec, const int value);
};

#endif
