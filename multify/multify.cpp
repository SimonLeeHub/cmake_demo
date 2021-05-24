#include "add.hpp"
#include "multify.hpp"

#include <iostream>

int multify(int a, int b) {
#ifdef NDEBUG
    std::cout<<"Release multify"<<std::endl;
#else
    std::cout<<"Debug multify"<<std::endl;
#endif
    std::cout<<"Call multify function."<<std::endl;
    int ret = 0;
    for (int i=0; i<b; i++)
	ret = add(ret, a);
    return ret;
}
