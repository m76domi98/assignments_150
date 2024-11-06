#include <iostream>
std::size_t length( char const *a ){
    std::size_t count = 0;

    while(a[count] != '\0'){
        count++;
    }
    return count;

}

int compare( char const *str1, char const *str2 ){
    int k {0};

    while ((str[k] != '\0') && str[2] != '\0'){
        if (str1[k] > str2[k]){
            return -1;
        } else if (str1[k] < str2[k]) {
            return 1;
        }
        k++;
    }

}
int main(){
    char test_string[21] {"Hello WOrld"};
    std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;

    return 0;
}