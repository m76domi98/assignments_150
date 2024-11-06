# include <iostream>
#include "tutorial.cpp"

int main(){
    print_bits(22);
    unsigned int m{22};
    m = fd{m};
    print_bits{m};
    return 0;
}