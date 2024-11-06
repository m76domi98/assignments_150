#include <iostream>
#include <cassert>

int main ();
void money_t (int n);

int main (){

    int n {};
    std::cout << "Please number >3 and odd";
    std::cin >> n;
    assert (n >=3);
    assert (n%2 == 1);


    money_t(n);
}

void money_t (int n){

    // top line
    for (int col {}; col <n; ++col){
        std::cout << "$";
    }
    std::cout << std::endl;

    for (int rows {}; rows <(n-2); rows++) {
        for (int col; col < ((n-1)/2) ; col++){
            std::cout << " ";
            std::cout << "$" << std::endl;
        }
    
    }

}