#include <iostream>
#include "Calculator.h"

int main() {
    Calculator base(2);
    int x=2;
    std::cout<<base.getValue()<<std::endl;
    base.sum(x);
    std::cout<<base.getValue()<<std::endl;
    base.subtract(x);
    std::cout<<base.getValue()<<std::endl;
    base.mul(x);
    std::cout<<base.getValue()<<std::endl;

    return 0;
}