#include <PmergeMe.hpp>

PmergeMe::PmergeMe(int argc, char *argv[]) {
	parseInput(argc, argv);
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

void PmergeMe::printDeq() {
	print(_deq);
}

void PmergeMe::printVec() {
	print(_vec);
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> vec) {
	std::vector<int> smaller, larger;

	if (vec.size() <= 1) {
		return vec;
	}

	if (vec.size() == 2) {
		if (vec[0] > vec[1]) {
			std::swap(vec[0], vec[1]);
		}
		return vec;
	}

	for (int i = 0; i + 1 < vec.size(); i++) {
		if (vec[i] > vec[i + 1]) {
			std::swap(vec[i], vec[i + 1]);
			smaller.push_back(vec[i]);
			larger.push_back(vec[i + 1]);
		}
	}
	if (vec.size() % 2) {
		smaller.push_back(vec.back());
	}
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
			_vec.push_back(n);
			_deq.push_back(n);
		}
		catch(std::exception &e) {
			throw;
		}
	}
}
