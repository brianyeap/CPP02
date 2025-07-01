/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:41:59 by brian             #+#    #+#             */
/*   Updated: 2025/07/01 15:38:50 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const int value) : _value(value << _frac) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _frac))) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const &copy) { *this = copy; }

float Fixed::toFloat(void) const {
  return ((float)this->_value / (float)(1 << _frac));
}
int Fixed::toInt(void) const { return (this->_value >> this->_frac); }

// overloading operators
Fixed &Fixed::operator=(Fixed const &copy) {
  this->_value = copy.getRawBits();
  return (*this);
}

Fixed Fixed::operator+(Fixed const &copy) const {
  Fixed result(this->toFloat() + copy.toFloat());
  return (result);
}

Fixed Fixed::operator-(Fixed const &copy) const {
  Fixed result(this->toFloat() - copy.toFloat());
  return (result);
}

Fixed Fixed::operator*(Fixed const &copy) const {
  Fixed result(this->toFloat() * copy.toFloat());
  return (result);
}

Fixed Fixed::operator/(Fixed const &copy) const {
  Fixed result(this->toFloat() / copy.toFloat());
  return (result);
}

// Bool
bool Fixed::operator==(const Fixed &copy) const {
  return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(const Fixed &copy) const {
  return (this->toFloat() != copy.toFloat());
}

bool Fixed::operator<=(const Fixed &copy) const {
  return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator>=(const Fixed &copy) const {
  return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<(const Fixed &copy) const {
  return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>(const Fixed &copy) const {
  return (this->toFloat() > copy.toFloat());
}

// Pre incr / decr
Fixed &Fixed::operator++(void) {
  this->setRawBits(this->getRawBits() + 1);
  return (*this);
}

Fixed &Fixed::operator--(void) {
  this->setRawBits(this->getRawBits() - 1);
  return (*this);
}

// Post incr / decr
Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  this->setRawBits(this->getRawBits() + 1);
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  this->setRawBits(this->getRawBits() - 1);
  return temp;
}

const Fixed &Fixed::min(Fixed const &copy1, Fixed const &copy2) {
  if (copy1 < copy2)
    return (copy1);
  return (copy2);
}

const Fixed &Fixed::max(Fixed const &copy1, Fixed const &copy2) {
  if (copy1 > copy2)
    return (copy1);
  return (copy2);
}

int Fixed::getRawBits(void) const { return (this->_value); }

void Fixed::setRawBits(const int raw) { this->_value = raw; }

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr) {
  return (str << fixed_nbr.toFloat());
}