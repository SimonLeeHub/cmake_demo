#include "multify.hpp"
#include <iostream>

int main() {
#ifdef NDEBUG
    std::cout<<"Release test"<<std::endl;
#else
    std::cout<<"Debug test"<<std::endl;
#endif
    int a=5;
    int b=3;
    std::cout<<a<<" multified "<<b<<" is "<<multify(a, b)<<std::endl;
    return 0;
}
