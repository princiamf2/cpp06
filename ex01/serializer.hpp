#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
    int Value;
};
class Serializer
{
    private:
        Serializer();
    public:
        static uintptr_t serializer(Data *ptr);
        static Data *deserializer(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */
