/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:14:29 by brian             #+#    #+#             */
/*   Updated: 2025/06/18 02:44:07 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
  int _fp_value;
  static const int _fract_bits;

public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);

		~Fixed();
		Fixed &operator=(const Fixed &src);

		float toFloat(void)const;
		int toInt(void)const;
    
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);