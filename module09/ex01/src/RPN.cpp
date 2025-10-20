#include <RPN.hpp>

RPN::RPN(const std::string& input) {
    readInput(input);
}

RPN::~RPN() {
}

RPN::RPN(const RPN& src) {
	*this = src;
}

RPN& RPN::operator=(const RPN& src) {
    if (this != &src) {
        _stack = src._stack;
        _finalResult = src._finalResult;
    }
    return *this;
}

void RPN::pushOperand(const std::string& token) {
    float   num;
    if (token.length() != 1) {
        throw std::runtime_error("Invalid number");
    }
    num = std::stof(token);
    _stack.push(num);
}

void RPN::applyOperator(const std::string& token) {
    if (token.length() != 1) {
        throw std::runtime_error("Invalid operator");
    }
    if (_stack.size() < 2) {
        throw std::runtime_error("Invalid input");
    }
    char    op = token[0];
    float   b = _stack.top(); _stack.pop();
    float   a = _stack.top(); _stack.pop();
    switch (op) {
        case '+': 
            _stack.push(a + b);
            break;
        case '-':
            _stack.push(a - b);
            break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Can't divide by 0");
            }
            _stack.push(a / b);
            break;
        case '*':
            _stack.push(a * b);
            break;
        default:
            throw std::runtime_error("Invalid operator");
    }
}

void RPN::checkResult() {
    if (_stack.size() != 1) {
        throw std::runtime_error("Invalid input");
    }
    _finalResult = _stack.top();
    _stack.pop();
}

void RPN::readInput(const std::string& input) {
    std::istringstream  ss(input);
    std::string         token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            pushOperand(token);
        }
        else {
            applyOperator(token);
        }
    }
    checkResult();
}

float RPN::getFinalResult() const {
    return _finalResult;
}