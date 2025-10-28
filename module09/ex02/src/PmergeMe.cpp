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
    print<std::vector<int>>(_vec);
    auto startVec = std::chrono::high_resolution_clock::now();
    _sortedVec = mergeInsertVec(_vec, 1);
    auto endVec = std::chrono::high_resolution_clock::now();

    // auto startDeq = std::chrono::high_resolution_clock::now();
    // _sortedDeq = mergeInsertVec(_vec, 1);
    // auto endDeq = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> durationVec = endVec - startVec;
    // std::chrono::duration<double, std::micro> durationDeq = endDeq - startDeq;

    std::cout << "After: ";
    print<std::vector<int>>(_sortedVec);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << durationVec.count() << " us\n";
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::deque : " << durationVec.count() << " us\n";
	std::cout << "Number of comparisons: " << _comparisonCount << std::endl;
}

void PmergeMe::binaryInsertVec(std::vector<int> &vec, const std::vector<int> &pending, size_t pairSize, size_t bound) {
    if (vec.empty()) {
        vec.insert(vec.end(), pending.begin(), pending.begin() + pairSize);
        return;
    }

    // Compare using the last element of the chunk
    int value = pending[pairSize - 1];

    // Clamp bound to the actual number of existing chunks
    size_t totalChunks = vec.size() / pairSize;
    if (bound > totalChunks)
        bound = totalChunks;

    size_t left = 0;
    size_t right = bound;

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        int midValue = vec[mid * pairSize + (pairSize - 1)];

        if (value < midValue)
            right = mid;
        else
            left = mid + 1;

        _comparisonCount++;
    }

    // Insert the full chunk at the calculated position
    vec.insert(vec.begin() + left * pairSize, pending.begin(), pending.begin() + pairSize);
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
	
	for (int i = 3; i < static_cast<int>(seq.size()); ++i) {
		for (int j = seq[i] - 1; j >= seq[i - 1]; --j) {
			if (j <= size) {
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

long PmergeMe::generateJacobstHalAtIdx(long n) { 
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> vec, size_t pairSize) {
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
	
	std::vector<int> mainchain, pending;
	// FORM MAINCHAIN WITH B1 AND ALL A'S

	for (size_t i = 0; i < pairSize; i++) {
		mainchain.push_back(vec[i]);
	}
	for (size_t i = pairSize; i < vec.size() - pairSize + 1; i += pairSize * 2) {
		for (size_t j = 0; j < pairSize; j++) {
			mainchain.push_back(vec[i + j]);
		}
	}
	
	//FORM PENDING WITH REMAINING B'S AND NON PARTICIPATING
	for (size_t i = pairSize * 2; i + pairSize - 1 < vec.size(); i += pairSize * 2) {
		for (size_t j = 0; j < pairSize && j + i < vec.size(); j++) {
			pending.push_back(vec[i + j]);
		}
	}
	
	
	size_t leftoverStart = (vec.size() / pairSize) * pairSize;
	if (leftoverStart < vec.size()) {
		for (size_t i = leftoverStart; i < vec.size(); ++i) {
			pending.push_back(vec[i]);
		}
	}
	if (pending.size() < pairSize) {
		for (size_t i = 0; i < pending.size(); i++) {
			mainchain.push_back(pending[i]);
		}
		return mainchain;
	}


	// std::vector<int> order = getInsertionOrderVec(pending.size() / pairSize);
	// size_t inserted = 0;
	// std::cout << " ORDER :"; print<std::vector<int>>(order);
	// for (size_t i = 0; i < order.size(); i++) {
	// 	size_t start = (order[i] - 1) * pairSize;
	// 	std::vector<int> chunk(pending.begin() + start, pending.begin() + start + pairSize);
	// 	std::cout << order[i] << " CHUNK :"; print<std::vector<int>>(chunk);
	// 	binaryInsertVec(mainchain, chunk, pairSize);
	// 	inserted++;
	// }

	int inserted = 0;
	int prevJacob = generateJacobstHalAtIdx(1);
	int curJacob = 0;
	for (int i = 2;; i++) {
		curJacob = generateJacobstHalAtIdx(i);
		if (curJacob > static_cast<int>(pending.size() / pairSize)) {
			break ;
		}
		for (int j = curJacob - 1; j >= prevJacob; j--) {
			int start = (j - 1) * pairSize;
				std::vector<int> chunk(pending.begin() + start, pending.begin() + start + pairSize);
				binaryInsertVec(mainchain, chunk, pairSize, curJacob + inserted);
				inserted++;
		}
		prevJacob = curJacob;
	}

	//need to change this from back to frony
	if (static_cast<int>((pending.size() / pairSize)) > inserted) {
		for (size_t i = inserted * pairSize; i <= pending.size() - pairSize; i += pairSize) {
			std::vector<int> chunk(pending.begin() + i, pending.begin() + i + pairSize);
			binaryInsertVec(mainchain, chunk, pairSize, curJacob + inserted);
			inserted++;
		}
	}

	// INSERT REMAINING 
	if (pending.size() / pairSize) {
		for (size_t i = (pending.size() / pairSize) * pairSize; i < pending.size(); i++) {
			mainchain.push_back(pending[i]);
		}
	}
	return mainchain;
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


// void PmergeMe::mergeInsertVec(std::vector<int> &larger, std::vector<int> *smaller = nullptr) {
// 	if (larger.size() <= 1) {
// 		return;
// 	}

// 	std::vector<int> newLarger, newSmaller;

// 	for (size_t i = 0; i + 1 < larger.size(); i += 2) {
// 		if (larger[i] > larger[i + 1]) {
// 			_comparisonCount++;
// 			std::swap(larger[i], larger[i + 1]);
// 			if (smaller) {
// 				std::swap(smaller[i], smaller[i + 1]);
// 			}

// 		}
// 	}
// }