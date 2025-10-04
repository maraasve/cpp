#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

};

#endif
