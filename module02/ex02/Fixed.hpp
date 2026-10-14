/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:41:01 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/29 10:53:15 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fract_bits = 8;
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& src);
		~Fixed();

		//copy asignment operator
		Fixed& operator = (const Fixed& src);
		
		//public methods
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		//ostream operator
		friend	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

		//comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		//arithmetic operators
		float	operator+(const Fixed& other) const;
		float	operator-(const Fixed& other) const;
		float	operator*(const Fixed& other) const;
		float	operator/(const Fixed& other) const;

		//increment & decrement operators
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		//min & max methods
		static const Fixed	&max(const Fixed& one, const Fixed& two);
		static Fixed		&max(Fixed& one, Fixed& two);
		static const Fixed	&min(const Fixed& one, const Fixed& two);
		static Fixed		&min(Fixed& one, Fixed& two);
};

#endif