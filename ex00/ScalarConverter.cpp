/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:19:56 by michel            #+#    #+#             */
/*   Updated: 2026/02/04 13:47:32 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    bool inputInvalid = false;
    bool charImpossible = false;
    bool charNonDisplayable = false;
    bool intImpossible = false;
    bool isIntLike = false;
    
    bool isPseudo = false;
    std::string floatPseudo;
    std::string doublePseudo;
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || 
        literal == "+inff" || literal == "-inf" || literal == "-inff")
    {
        charImpossible = true;
        intImpossible = true;
        isPseudo = true;
        if (literal == "nan" || literal == "nanf")
        {
            doublePseudo = "nan";
            floatPseudo = "nanf";
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            doublePseudo = "+inf";
            floatPseudo = "+inff";
        }
        else
        {
            doublePseudo = "-inf";
            floatPseudo = "-inff";
        }
    }
    double d = 0.0;
    if (!isPseudo)
    {
        if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
            d = static_cast<double>(literal[0]);
        else
        {
            char *end;
            d = std::strtod(literal.c_str(), &end);
            if (end == literal.c_str())
                inputInvalid = true;
            else if (*end != '\0' && !(*end == 'f' && end[1] == '\0'))
                inputInvalid = true;
        }
    }
    if (inputInvalid)
    {
        std::cout << "char : impossible\n";
        std::cout << "int : impossible\n";
        std::cout << "float : impossible\n";
        std::cout << "double : impossible\n";
        return ;
    }
    if (isPseudo)
    {
        std::cout << "char : impossible\n";
        std::cout << "int : impossible\n";
        std::cout << "float : " << floatPseudo << "\n";
        std::cout << "double : " << doublePseudo << "\n";
        return ;
    }
    if (d < 0.0 || d > 127.0 || std::isnan(d) || std::isinf(d))
        charImpossible = true;
    else
    {
        char c = static_cast<char>(d);
        if (!std::isprint(static_cast<unsigned char>(c)))
            charNonDisplayable = true;
    }
    if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX) || std::isnan(d) || std::isinf(d))
        intImpossible = true;
    if ((std::floor(d) == d) && !std::isinf(d) && !std::isnan(d))
        isIntLike = true;
    std::cout << "char: ";
    if (charImpossible)
        std::cout << "impossible\n";
    else
    {
        char c = static_cast<char>(d);
        if (charNonDisplayable)
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << c << "'\n";
    }
    std::cout << "int: ";
    if (intImpossible)
        std::cout << "impossible\n";
    else
    {
        int i = static_cast<int>(d);
        std::cout << i << "\n";
    }
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (isIntLike)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << f << "f\n";
    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6);
    std::cout << "double: ";
    if (isIntLike)
        std::cout << std::fixed << std::setprecision(1);
    std::cout << d << "\n";
    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6);
}