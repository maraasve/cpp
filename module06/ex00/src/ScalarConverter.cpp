#include <ScalarConverter.hpp>
#include <getType.hpp>

static void handleInvalidLiteral() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void convertPseudoLiterals(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } 
    else if (literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff" || literal == "inf" || literal == "inff") {
        if (literal.find("ff") != std::string::npos) {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        } 
        else {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
    }
}

static void convertChar(const std::string& literal) {
    char c = literal[0];
	if (isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void convertInt(const std::string& literal) {
    int i = std::stoi(literal);
    if (i > 0 && i < 270 && isprint(i)) {
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    } 
    else if (i >= 0 && i <= 127) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static bool convertFloat(const std::string& literal) {
    float f;
    try {
        f = std::stof(literal);
    } 
    catch (const std::out_of_range&) {
        return false;
    }
    catch (const std::invalid_argument&) {
        handleInvalidLiteral();
        return true;
    }
    if (f > 0 && f < 270 && isprint(static_cast<int>(f))) {
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    }
    else if (f >= 0 && f <= 127) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX)) {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    else {
        std::cout << "int: impossible" << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
    return true;
}

static void convertDouble(const std::string& literal) {
    double d;
    try {
        d = std::stod(literal);
    } 
    catch (const std::out_of_range&) {
        handleInvalidLiteral();
        return;
    }
    catch (const std::invalid_argument&) {
        handleInvalidLiteral();
        return;
    }
    if (d > 0 && d < 270 && isprint(static_cast<int>(d))) {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }
    else if (d >= 0 && d <= 127) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX)) {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    else {
        std::cout << "int: impossible" << std::endl;
    }
    if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    }
    else {
        std::cout << "float: impossible" << std::endl;
    }
    std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string& literal) {
    LiteralType type = getLiteralType(literal);

    switch (type) {
        case CHAR: {
            convertChar(literal);
            break;
        }
        case INT: {
            convertInt(literal);
            break;
        }
        case FLOAT: {
            convertFloat(literal);
            break;
        }
        case DOUBLE: {
            convertDouble(literal);
            break;
        }
        case PSEUDO: {
            convertPseudoLiterals(literal);
            break;
        }
        case INVALID: {
            handleInvalidLiteral();
            break;
        }
    }
}
