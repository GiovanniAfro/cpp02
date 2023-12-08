/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:47 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/08 15:33:48 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed _y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& src);
		~Point(void);

		Point& operator=(const Point& rhs);

		float	getX(void) const;
		float	getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
