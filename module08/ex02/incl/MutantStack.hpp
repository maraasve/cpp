#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		using std::stack<T>::stack;

		using iterator = typename std::stack<T>::container_type::iterator;

		iterator begin() {
			return this->c.begin();
		};
		iterator end() {
			return this->c.end();
		};

		const iterator begin() const{
			return this->c.begin();
		};
		const iterator end() const {
			return this->c.end();
		};
};

#endif
