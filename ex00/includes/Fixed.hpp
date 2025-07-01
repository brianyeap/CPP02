/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:14:29 by brian             #+#    #+#             */
/*   Updated: 2025/06/18 01:01:58 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
private:
  int _fp_value;
  static const int _fract_bits;

public:
  Fixed();
  Fixed(const Fixed &copy);

  ~Fixed();
  Fixed &operator=(const Fixed &src);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};