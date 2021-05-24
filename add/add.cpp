#include "add.hpp"

#include <iostream>

int add(int a, int b) {
#ifdef NDEBUG
    std::cout<<"Release add"<<std::endl;
#else
    std::cout<<"Debug add"<<std::endl;
#endif
    std::cout<<"Call add function."<<std::endl;
    return a+b; 
}
