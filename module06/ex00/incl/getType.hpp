#ifndef TYPES_HPP
# define TYPES_HPP

# include <iostream>

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

LiteralType	getLiteralType(const std::string& literal);

#endif