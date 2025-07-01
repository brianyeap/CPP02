/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:41:11 by brian             #+#    #+#             */
/*   Updated: 2025/06/30 17:41:15 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  return (0);
}