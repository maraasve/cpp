#include <getType.hpp>

static bool isChar(const std::string& literal) {
    if (literal.length() == 1 && !isdigit(literal[0])) {
        return true;
    }
    return false;
}

static bool isPseudo(const std::string& literal) {
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" 
        || literal == "-inf" || literal == "-inff" || literal == "inf" || literal == "inff") {
        return true;
    }
    return false;
}

static bool isInt(const std::string& literal) {
    size_t pos = 0;
    try {
        std::stoi(literal, &pos);
    } 
    catch (const std::out_of_range&) {
        return false;
    }
    catch (const std::invalid_argument&) {
        return false;
    }
    if (pos != literal.length()) {
        return false;
    }
    return true;
}

static bool isFloat(const std::string& literal) {
    if (literal.back() != 'f' || literal == "f") {
        return false;
    }
    size_t pos = 0;
    try {
        std::stof(literal.substr(0, literal.length() - 1), &pos);
    } 
    catch (const std::out_of_range&) {
        return false;
    }
    catch (const std::invalid_argument&) {
        return false;
    }
    if (pos != literal.length() - 1) {
        return false;
    }
    return true;
}

static bool isDouble(const std::string& literal) {
    size_t pos = 0;
    try {
        std::stod(literal, &pos);
    }
    catch (const std::out_of_range&) {
        return false;
    }
    catch (const std::invalid_argument&) {
        return false;
    }
    if (pos != literal.length()) {
        return false;
    }
    return true;
}

LiteralType getLiteralType(const std::string& literal) {
    if (isChar(literal)) {
        return CHAR;
    }
    if (isPseudo(literal)) {
        return PSEUDO;
    }
    if (isInt(literal)) {
        return INT;
    }
    if (isFloat(literal)) {
        return FLOAT;
    }
    if (isDouble(literal)) {
        return DOUBLE;
    }
    return INVALID;
}