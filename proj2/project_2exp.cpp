#include <iostream>
#include <cassert>

unsigned int count(unsigned int n, unsigned int bit){
    assert(bit ==0 || bit == 1);
    
    unsigned int num {n};
    unsigned int counter{0};
    unsigned int count_one {0};

    while (num) {
        (num >>= 1);
        counter++;
    }

    int checker =1;
    for (unsigned int i = 0;i<=counter; i++){
        if (n & checker){
            count_one++;
        }
        checker *=2;
    }

    if (bit ==1){
        return count_one;
    } else if (bit == 0) {
        return (32-count_one);
    }
    return 0;
}  

int main() {
        std::cout << count(0b010000000, 0) << std::endl;
        assert(count(0b10101010, 1) == 4);  // 10101010 has four 1 bits
        assert(count(0b11111111, 1) == 8);  // All bits are 1
        assert(count(0b00000000, 0) == 32);  // All bits are 0
        assert(count(0b11110000, 1) == 4);  // 11110000 has four 1 bits
        assert(count(0b11110000, 0) == 4);  // 11110000 has four 0 bits

}