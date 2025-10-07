#include <Span.hpp>
#include <colors.hpp>
#include <limits>

void waitForEnter() {
    std::cout << "\nPress Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // TEST 1: Basic shortest/longest span
    std::cout << BOLDMAGENTA << "TEST 1: Basic shortest/longest span" << RESET << std::endl;
    Span sp(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << BLUE << "Shortest span: " << RESET << sp.shortestSpan() << std::endl;
    std::cout << BLUE << "Longest span: " << RESET << sp.longestSpan() << std::endl;
    waitForEnter();


    // TEST 2: AddNumbers with too many elements
    std::cout << BOLDMAGENTA << "TEST 2: Adding multiple numbers with exception" << RESET << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++)
        vec.push_back(i * 2);

    try {
        sp.addNumbers(vec.begin(), vec.end());
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    waitForEnter();


    // TEST 3: AddNumbers within capacity
    std::cout << BOLDMAGENTA << "TEST 3: Adding multiple numbers without exception" << RESET << std::endl;
    Span sp2(10000);
    try {
        sp2.addNumbers(vec.begin(), vec.end());
        std::cout << BLUE << "Added 10000 numbers successfully!" << RESET << std::endl;
        std::cout << BLUE << "Shortest span: " << RESET << sp2.shortestSpan() << std::endl;
        std::cout << BLUE << "Longest span: " << RESET << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    waitForEnter();


    // TEST 4: NoSpan exception
    std::cout << BOLDMAGENTA << "TEST 4: NoSpan exception" << RESET << std::endl;
    Span sp3(1);
    sp3.addNumber(42);
    try {
        std::cout << BLUE << "Attempting shortest span..." << RESET << std::endl;
        sp3.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    try {
        std::cout << BLUE << "Attempting longest span..." << RESET << std::endl;
        sp3.longestSpan();
    } catch (const std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    waitForEnter();

    // TEST 5: Edge case with duplicates
    std::cout << BOLDMAGENTA << "TEST 5: Edge case with duplicates" << RESET << std::endl;
    Span sp4(5);
    sp4.addNumber(7);
    sp4.addNumber(7);
    sp4.addNumber(7);

    std::cout << BLUE << "Shortest span: " << RESET << sp4.shortestSpan() << std::endl;
    std::cout << BLUE << "Longest span: " << RESET << sp4.longestSpan() << std::endl;
    waitForEnter();
}