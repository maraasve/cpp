#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base::~Base() {
   std::cout << "Base destructor called" << std::endl;
}

Base *generate(void) {
	bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	int num = rand() % 3;

	switch (num) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p) {
	if (!p) {
		std::cout << "nullptr" << std::endl;
	}
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Type unknown" << std::endl;
	}
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}
	std::cout << "Type unknown" << std::endl;
}