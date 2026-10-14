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
	_comparisonCount = 0;
    auto startDeq = std::chrono::high_resolution_clock::now();
    _sortedDeq = mergeInsertDeq(_deq, 1);
    auto endDeq = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> durationVec = endVec - startVec;
    std::chrono::duration<double, std::micro> durationDeq = endDeq - startDeq;

    std::cout << "After: ";
    print<std::vector<int>>(_sortedVec);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << durationVec.count() << " us\n";
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::deque : " << durationDeq.count() << " us\n";
	std::cout << "Number of comparisons: " << _comparisonCount << std::endl;
}

long generateJacobstHalAtIdx(long n) { 
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}





/* 

VECTOR MERGE INSERTION SORT
FOR JOHNSON ALGORITHM 


*/

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
	
	vec = mergeInsertVec(vec, pairSize * 2);
	
	// FORM MAINCHAIN WITH B1 AND ALL A's	
	std::vector<int> mainchain, pending;
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

	int inserted = 0;
	int prevJacob = generateJacobstHalAtIdx(1);
	int curJacob = 0;
	int offset = 0;
	for (int i = 2;; i++) {
		curJacob = generateJacobstHalAtIdx(i);
		if (curJacob - prevJacob > static_cast<int>(pending.size() / pairSize)) {
			break ;
		}
		for (int j = curJacob - 1; j >= prevJacob; j--) {
			if ( j > static_cast<int>(pending.size() / pairSize)) {
				continue;
			}
			int start = (j - 1) * pairSize;
			std::vector<int> chunk(pending.begin() + start, pending.begin() + start + pairSize);
			size_t bound = curJacob + inserted - offset;
			if (bound > mainchain.size() / pairSize)
				bound = mainchain.size() / pairSize;
			binaryInsert(mainchain, chunk, pairSize, bound, _comparisonCount);
			size_t inserted_pos = (bound < mainchain.size() / pairSize) ? bound : (mainchain.size() / pairSize);
        	if (inserted_pos == bound) offset++;
			inserted++;
		}
		prevJacob = curJacob;
		offset = 0;
	}

	//need to change this from back to frony
	if (static_cast<int>((pending.size() / pairSize)) > inserted) {
		for (size_t i = inserted * pairSize; i <= pending.size() - pairSize; i += pairSize) {
			std::vector<int> chunk(pending.begin() + i, pending.begin() + i + pairSize);
			int bound = mainchain.size() / pairSize;
			binaryInsert(mainchain, chunk, pairSize, bound, _comparisonCount);
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








/* 

DEQUE MERGE INSERTION SORT
FOR JOHNSON ALGORITHM 


*/

std::deque<int> PmergeMe::mergeInsertDeq(std::deque<int> deq, size_t pairSize) {
	if (deq.size() < pairSize * 2) {
		return deq;
	}
	
	for (size_t i = 0; i + 2 * pairSize - 1 < deq.size(); i += 2 * pairSize) {
		_comparisonCount++;
		if (deq[i + pairSize - 1] > deq[i + 2 * pairSize - 1]) {
			swapPair(deq, i, pairSize);
		}
	}

	deq = mergeInsertDeq(deq, pairSize * 2);
	
	// FORM MAINCHAIN WITH B1 AND ALL A's	
	std::deque<int> mainchain, pending;
	for (size_t i = 0; i < pairSize; i++) {
		mainchain.push_back(deq[i]);
	}
	for (size_t i = pairSize; i < deq.size() - pairSize + 1; i += pairSize * 2) {
		for (size_t j = 0; j < pairSize; j++) {
			mainchain.push_back(deq[i + j]);
		}
	}
	
	//FORM PENDING WITH REMAINING B'S AND NON PARTICIPATING
	for (size_t i = pairSize * 2; i + pairSize - 1 < deq.size(); i += pairSize * 2) {
		for (size_t j = 0; j < pairSize && j + i < deq.size(); j++) {
			pending.push_back(deq[i + j]);
		}
	}
	
	size_t leftoverStart = (deq.size() / pairSize) * pairSize;
	if (leftoverStart < deq.size()) {
		for (size_t i = leftoverStart; i < deq.size(); ++i) {
			pending.push_back(deq[i]);
		}
	}
	if (pending.size() < pairSize) {
		for (size_t i = 0; i < pending.size(); i++) {
			mainchain.push_back(pending[i]);
		}
		return mainchain;
	}

	int inserted = 0;
	int prevJacob = generateJacobstHalAtIdx(1);
	int curJacob = 0;
	int offset = 0;
	for (int i = 2;; i++) {
		curJacob = generateJacobstHalAtIdx(i);
		if (curJacob - prevJacob > static_cast<int>(pending.size() / pairSize)) {
			break ;
		}
		for (int j = curJacob - 1; j >= prevJacob; j--) {
			if ( j > static_cast<int>(pending.size() / pairSize)) {
				continue;
			}
			int start = (j - 1) * pairSize;
			std::deque<int> chunk(pending.begin() + start, pending.begin() + start + pairSize);
			size_t bound = curJacob + inserted - offset;
			if (bound > mainchain.size() / pairSize)
				bound = mainchain.size() / pairSize;
			binaryInsert(mainchain, chunk, pairSize, bound, _comparisonCount);
			size_t inserted_pos = (bound < mainchain.size() / pairSize) ? bound : (mainchain.size() / pairSize);
        	if (inserted_pos == bound) offset++;
			inserted++;
		}
		prevJacob = curJacob;
		offset = 0;
	}

	//need to change this from back to frony
	if (static_cast<int>((pending.size() / pairSize)) > inserted) {
		for (size_t i = inserted * pairSize; i <= pending.size() - pairSize; i += pairSize) {
			std::deque<int> chunk(pending.begin() + i, pending.begin() + i + pairSize);
			int bound = mainchain.size() / pairSize;
			binaryInsert(mainchain, chunk, pairSize, bound, _comparisonCount);
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