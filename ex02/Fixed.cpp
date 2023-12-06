/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:25 by gcavanna          #+#    #+#             */
/*   Updated: 2023/12/06 11:07:36 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << fractionalBits)
{
    std::cout << "Int conctructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(value * (1 << fractionalBits))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src; //è un'espressione che indica l'assegnazione di un oggetto al proprio oggetto corrente nella programmazione. Nel contesto del copy constructor che hai definito, questa espressione è utilizzata per copiare il contenuto di un oggetto Fixed (rappresentato da src) nell'oggetto corrente, cioè *this. this: È un puntatore implicito all'oggetto corrente. In questo contesto, this rappresenta l'indirizzo dell'oggetto corrente di tipo Fixed. *this: L'operatore di dereferenziazione * applicato a this restituisce l'oggetto effettivo, non l'indirizzo. Quindi, *this rappresenta l'oggetto corrente di tipo Fixed
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->_value) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return  this->_value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other._value;
}

// Implementazione degli operatori aritmetici
Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(_value + other._value);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(_value - other._value);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed((_value * other._value) >> fractionalBits);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed((_value << fractionalBits) / other._value);
}

// Implementazione degli operatori di incremento/decremento
Fixed& Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

//condizione ? valore_se_vera : valore_se_falsa;
