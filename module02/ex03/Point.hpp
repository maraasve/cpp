/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:37:08 by marieke           #+#    #+#             */
/*   Updated: 2024/09/29 10:54:52 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	y;
		const Fixed	x;

	public:
		Point();
		Point(const float y, const float x);
		Point(const Point& src);
		~Point();
		
		// copy assignment operator
		Point& operator = (const Point& src);
};

#endif