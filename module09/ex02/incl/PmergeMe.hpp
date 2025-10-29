#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <chrono>
# include <iomanip>
# include <cmath>


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

		void run();
		void parseInput(int argc, char *argv[]);
		std::vector<int>	mergeInsertVec(std::vector<int> vec, size_t pairSize);
		std::deque<int>		mergeInsertDeq(std::deque<int> deq, size_t pairSize);

		template <typename T>
		void print(const T& container, const std::string& sep = " ") {
			for (auto it = container.begin(); it != container.end(); ++it) {
				std::cout << *it;
				if (std::next(it) != container.end())
					std::cout << sep;
			}
			std::cout << std::endl;
		}

		template <typename T>
		void binaryInsert(T& mainchain, const T& chunk, size_t pairSize, size_t bound, size_t& comparisonCount) {
			if (mainchain.empty()) {
				mainchain.insert(mainchain.end(), chunk.begin(), chunk.end());
				return;
			}

			int value = chunk[pairSize - 1];
			size_t totalChunks = mainchain.size() / pairSize;
			if (bound > totalChunks) bound = totalChunks;

			size_t left = 0, right = bound;
			while (left < right) {
				size_t mid = left + (right - left) / 2;
				int midValue = mainchain[mid * pairSize + (pairSize - 1)];
				comparisonCount++;
				if (value < midValue) right = mid;
				else left = mid + 1;
			}

			mainchain.insert(mainchain.begin() + left * pairSize, chunk.begin(), chunk.end());
		}

		template <typename Container>
		void swapPair(Container &c, size_t startIndex, size_t pairSize) {
			for (size_t i = 0; i < pairSize; i++) {
				std::swap(c[startIndex + i], c[startIndex + pairSize + i]);
			}
		}

};

#endif
