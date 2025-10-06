#include <Base.hpp>

int main(void) {
	Base *ptr = generate();
	identify(ptr);

	identify(*ptr);
}