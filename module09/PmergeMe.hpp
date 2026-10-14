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

		long generateJacobstHalAtIdx(long n)

		void	parseInput(int argc, char *argv[]);
		std::vector<int>	mergeInsertVec(std::vector<int> vec, size_t pairSize);
		std::deque<int>		mergeInsertDeq(std::deque<int> &deq);
		void	run();
		void	binaryInsertVec(std::vector<int> &vec, const std::vector<int> &pending, size_t pairSize);

		template <typename T> void print(T &container) {
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

		template <typename T> void PmergeMe::swapPair(T it, int pairSize) {
			T start = next(it, -pairSize + 1);
			T end = next(start, pairSize);
			while (start != end) {
				std::iter_swap(start, next(start, pairSize));
				start++;
			}
		}

		template <typename T> void PmergeMe::mergeInsert(T &c, int pairSize) {

			typedef typename T::iterator Iterator;

			int pairCount = c.size() / pairSize;
			if (pairCount < 2) {
				return ;
			}

			bool odd = pairCount % 2;

			Iterator start = c.begin();
			Iterator end = std::advance(c.begin(), pairSize * pairCount);
			Iterator lastPair = std::advance(end, -(odd * pairSize));

			for (Iterator cur = start; cur != lastPair; std::advance(cur, pairSize * 2)) {
				Iterator thisPair = std::advance(cur, pairSize - 1);
				Iterator nextPair = std::advance(cur, (pairSize * 2) - 1);
				if(compare(thisPair, nextPair)) {
					swapPair(thisPair, pairSize);
				}
			}
			mergeInsert(c, pairSize * 2);

			std::vector<Iterator> mainchain, pending;

			//insert b1 into main
			main.insert(main.end(), std::advance(c.begin(), pairSize - 1));
			
			//insert a's into main
			for (int i = 2; i < pairCount; i += 2) {
				main.insert(main.end(), std::advance(c.begin(), pairSize * (i - 1) - 1));
			}

			//insert b's into pending
			for (int i = 3; i < pairCount; i += 2) {
				pending.insert(pending.end(), std::advance(c.begin(), pairSize * (i - 1) - 1));
			}
			
			if (odd) {
				pending.insert(pending.end(), std::advance(lastPair, pairSize - 1));
			}

			int prevJacobsthalNum = generateJacobsthalAtIdx(1);
			int curJacobsthalNum;
			int inserted = 0;
			for (int i = 2; curJacobsthalNum < pending.size(); i++) {
				curJacobsthalNum = generateJacobsthalAtIDx(i);
				int jacobsthalDiff = curJacobsthalNum - prevJacobsthalNum;
				Iterator pend_it = std::advance(pending.begin(), jacobsthalDiff - 1);
				Iterator bound_it = std::advance(main.begin(), curJacobsthalNum + inserted);
				int j = curJacobsthalNum;
				while(j > prevJacobsthalNum) {
					Iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, compare<Iterator>);
					Iterator insertedIdx = main.insert(idx, *pend_it);
					j--;
				}
			}
		}

};

#endif
