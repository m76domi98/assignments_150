#include <iostream>

void print_bits(unsigned int m) {
    std::cout << "ene" << std::endl;

    unsigned int mask {};
    mask = 1  << 31;

    while (mask != 0){
        if ((m & mask)==0) {
            std::cout << "0";
        } else {
            std::cout <<"1";
        }
        mask = mask >> 1;
    }

    std::cout << std::endl;


}

unsigned int fd (unsigned int m){
    unsigned int mask {};
    mask = 3;
    // mask = (1 << 0) | (1 << 1);


    unsigned int flip {};
    flip = 1;

    while (mask !=0){
        if (((m & mask)==0) || ((~m & mask)=0)){
        m = m ^ flip;
        }
        mask = mask << 2;
        flip = flip  << 2;
    }

    return m;
}

