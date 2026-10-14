/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:02:27 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/29 10:31:14 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const int input)
{
	_value = input << _fract_bits;
}

Fixed::Fixed(const float input)
{
	_value = roundf(input * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed& Fixed::operator = (const Fixed& src)
{
	if (this == &src)
	{
		return (*this);
	}
	_value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fract_bits);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fract_bits));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

//comparison operators
bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

//arithmetic operators
float	Fixed::operator+(const Fixed& other) const
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed& other) const
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat());
}

//increment & decrement operators
Fixed	&Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;

	tmp = *this;
	_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp;

	tmp = *this;
	_value--;
	return (tmp);
}

//min & max methods
const Fixed	&Fixed::max(const Fixed& one, const Fixed& two)
{
	return (one.toFloat() >= two.toFloat() ? one : two);
}

Fixed	&Fixed::max(Fixed& one, Fixed& two)
{
	return (one.toFloat() >= two.toFloat() ? one : two);
}

const Fixed	&Fixed::min(const Fixed& one, const Fixed& two)
{
	return (one.toFloat() <= two.toFloat() ? one : two);
}

Fixed	&Fixed::min(Fixed& one, Fixed& two)
{
	return (one.toFloat() <= two.toFloat() ? one : two);
}