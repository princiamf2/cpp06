#include "serializer.hpp"
#include <iostream>

int main()
{
    Data d;
    d.Value = 42;

    Data* ptr = &d;
    uintptr_t raw = Serializer::serializer(ptr);
    Data* back = Serializer::deserializer(raw);

    std::cout << "Original ptr: " << ptr << std::endl;
    std::cout << "Raw value:    " << raw << std::endl;
    std::cout << "Back ptr:     " << back << std::endl;

    std::cout << "Original value: " << ptr->Value << std::endl;
    std::cout << "Back value:     " << back->Value << std::endl;

    if (ptr == back)
        std::cout << "OK: pointers match" << std::endl;
    else
        std::cout << "KO: pointers differ" << std::endl;

    return 0;
}
