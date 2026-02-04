#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Base* p = generate();

    identify(p);
    identify(*p);

    delete p;
    return 0;
}
