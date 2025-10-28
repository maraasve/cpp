#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <chrono>
# include <iomanip>


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

		long generateJacobstHalAtIdx(long n);

		void	parseInput(int argc, char *argv[]);
		std::vector<int>	mergeInsertVec(std::vector<int> vec, size_t pairSize);
		void	run();
		void	binaryInsertVec(std::vector<int> &vec, const std::vector<int> &pending, size_t pairSize, size_t bound);

		template <typename T> void print(T &c) {
			for (const auto &value : c) {
				std::cout << value << " ";
			}
			std::cout << std::endl;
		}

		template <typename T> bool compare(T one, T two) {
			_comparisonCount++;
			return *one > *two;
		}

		template <typename T> T next(T it, int steps) {
			std::advance(it, steps);
			return it;
		}

		// template <typename T> void PmergeMe::swapPair(T &c, size_t i, int pairSize) {
		// 	for (size_t j = 0; j < pairSize; j++) {
		// 		std::swap(c[i + j], c[i + pairSize + j]);
		// 	}
		// }
};

#endif
