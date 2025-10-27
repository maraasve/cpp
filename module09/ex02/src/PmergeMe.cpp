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
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_vec = src._vec;
		_deq = src._deq;
	}
	return *this;
}

void PmergeMe::run() {
    std::cout << "Before: ";
    printVec(_vec);
    auto startVec = std::chrono::high_resolution_clock::now();
    _sortedVec = mergeInsertVec(_vec, 1);
    auto endVec = std::chrono::high_resolution_clock::now();

    auto startDeq = std::chrono::high_resolution_clock::now();
    _sortedDeq = mergeInsertDeq(_deq);
    auto endDeq = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> durationVec = endVec - startVec;
    std::chrono::duration<double, std::micro> durationDeq = endDeq - startDeq;

    std::cout << "After: ";
    printVec(_sortedVec);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << durationVec.count() << " us\n";
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << durationDeq.count() << " us\n";
	std::cout << "Comparison count = " << _comparisonCount << std::endl;
}

void PmergeMe::printDeq(const std::deque<int> &deq) {
	print(deq);
}

void PmergeMe::printVec(const std::vector<int> &vec) {
	print(vec);
}

void PmergeMe::binaryInsertVec(std::vector<int> &vec, const int value) {
	size_t left = 0;
	size_t right = vec.size();
	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (value < vec[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
		_comparisonCount++;
	}
	vec.insert(vec.begin() + left, value);
}

std::vector<int> generateJacobsthalVec(int size) {
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < size) {
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	}
	return seq;
}

std::vector<int> getInsertionOrderVec(int size) {
	std::vector<int> seq = generateJacobsthalVec(size);
	std::vector<int> order;
	
	for (int i = 1; i < static_cast<int>(seq.size()); ++i) {
		for (int j = seq[i] - 1; j >= seq[i - 1]; --j) {
			if (j < size) {
				order.push_back(j);
			}
		}
	}
	return order;
}

void swapPair(std::vector<int> &vec, size_t i, size_t pairSize) {
    for (size_t j = 0; j < pairSize; j++) {
        std::swap(vec[i + j], vec[i + pairSize + j]);
    }
}


std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> &vec, size_t pairSize) {
	std::vector<int> smaller, larger;

	if (vec.size() < pairSize * 2) {
		return vec;
	}

	for (size_t i = 0; i + 2 * pairSize - 1 < vec.size(); i += 2 * pairSize) {
		_comparisonCount++;
		if (vec[i + pairSize - 1] > vec[i + 2 * pairSize - 1]) {
			swapPair(vec, i, pairSize);
		}
	}

	std::vector<int> temp = mergeInsertVec(vec, pairSize * 2);
	vec = temp;

	std::vector<int> mainChain;

	for (size_t i = 0; i < pairSize; i++) {
		mainChain.push_back(vec[i]);
	}
	for (size_t i = pairSize; i < 2 * pairSize; i++) {
		mainChain.push_back(vec[i]);
	}
	std::cout << "MAINCHAIN = " << std::endl; printVec(mainChain);

	// std::vector<int> order = getInsertionOrderVec(smaller.size());
	// for (size_t i = 1; i < order.size(); i++) {
	// 	binaryInsertVec(larger, smaller[order[i]]);
	// }
	return mainChain;
}

void binaryInsertDeq(std::deque<int> &deq, const int value) {
	size_t left = 0;
	size_t right = deq.size();
	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (value < deq[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	deq.insert(deq.begin() + left, value);
}

std::deque<int> generateJacobsthalDeq(int size) {
	std::deque<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < size) {
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	}
	return seq;
}

std::deque<int> getInsertionOrderDeq(int size) {
	std::deque<int> seq = generateJacobsthalDeq(size);
	std::deque<int> order;
	
	for (int i = 1; i < static_cast<int>(seq.size()); ++i) {
		for (int j = seq[i] - 1; j >= seq[i - 1]; --j) {
			if (j < size) {
				order.push_back(j);
			}
		}
	}
	return order;
}

std::deque<int>	PmergeMe::mergeInsertDeq(std::deque<int> &deq) {
	std::deque<int> smaller, larger;

	if (deq.size() <= 1) {
		return deq;
	}

	if (deq.size() == 2) {
		if (deq[0] > deq[1]) {
			std::swap(deq[0], deq[1]);
		}
		return deq;
	}


	for (size_t i = 0; i < deq.size(); i += 2) {
		if (deq[i] > deq[i + 1]) {
			std::swap(deq[i], deq[i + 1]);
		}
		larger.push_back(deq[i + 1]);
		smaller.push_back(deq[i]);
	}

	std::deque<int> temp = mergeInsertDeq(larger);
	larger = temp;

	binaryInsertDeq(larger, smaller[0]);

	std::deque<int> order = getInsertionOrderDeq(smaller.size());

	for (size_t i = 1; i < order.size(); i++) {
		binaryInsertDeq(larger, smaller[order[i]]);
	}
	return larger;
}

void PmergeMe::parseInput(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		try {
			std::string str = argv[i];
			size_t pos;
			int n = std::stoi(str, &pos);
			if (pos != str.size()) {
				throw std::runtime_error("Invalid argument");
			}
			if (n < 0) {
				throw std::runtime_error("Positive integers only");
			}
			_vec.push_back(n);
			_deq.push_back(n);
		}
		catch(std::exception &e) {
			throw;
		}
	}
}
