/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:41:56 by brian             #+#    #+#             */
/*   Updated: 2025/06/30 18:37:22 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
  int _value;
  static const int _frac;

public:
  Fixed(void);
  Fixed(const int value);
  Fixed(const float value);
  ~Fixed(void);
  Fixed(Fixed const &copy);

  Fixed &operator=(Fixed const &copy);
  Fixed operator+(Fixed const &copy) const;
  Fixed operator-(Fixed const &copy) const;
  Fixed operator*(Fixed const &copy) const;
  Fixed operator/(Fixed const &copy) const;
  bool operator==(Fixed const &copy) const;
  bool operator!=(Fixed const &copy) const;
  bool operator<=(Fixed const &copy) const;
  bool operator>=(Fixed const &copy) const;
  bool operator<(Fixed const &copy) const;
  bool operator>(Fixed const &copy) const;

  Fixed &operator++(void);
  Fixed &operator--(void);
  Fixed operator++(int);
  Fixed operator--(int);

  static const Fixed &min(Fixed const &copy1, Fixed const &copy2);
  static const Fixed &max(Fixed const &copy1, Fixed const &copy2);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif