/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:24:05 by michel            #+#    #+#             */
/*   Updated: 2026/02/04 14:27:55 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

uintptr_t Serializer::serializer(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserializer(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}