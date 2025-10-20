#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>


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

	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();

		void	parseInput(int argc, char *argv[]);
		std::vector<int>	mergeInsertVec(std::vector<int> vec);
		void	printVec();
		void	printDeq();
};

#endif
