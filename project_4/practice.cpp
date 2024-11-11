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

    while ((str[k] != '\0') && (str[2] != '\0')){
        if (str1[k] > str2[k]){
            return -1; // this means that str 2 comes after str 1 so i can return -1
        } else if (str1[k] < str2[k]) {
            return 1;// this means that str 1 comes afyer str 2 so i can return 1
        }
        k++;
        // since the characters are equal, move to the next computer
    }


    //if ilm gonna reach the end of both strings simoueltanuously, they are equal
    if((str1[k] == '\0') && (str2[k]=='\0')){
        return 0; //theyre the same string
    }

    // shorter string comes befor elonger string
    if (str[k] == '\0'){
        return -1; // str 1 comes before so -1
    }else{
        return 1; //only other option now is that str is shorter so its bf fo return 1
    }
}

void assign( char *str1, char const *str2 ){
    int i = 0;
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}
unsigned int distance( char const *str1, char const *str2 ){
    // base case
    if (*str1 =='\0'){
        int lnh = 0;
        while (str2[lnh]!= '\0'){
            ++lnh;
        }
        return lnh;
    }
    if (*str2 =='\0'){
        int lnh = 0;
        while (str2[lnh]!= '\0'){
            ++lnh;
        }
        return lnh;
    }

    if (*str1== *str2){
        return distance (str1+1, str2+1);
        // first two ch are the same so i need to check the next
    }

    // if first ch are diff, calc min distance
    int sub = distance (str1+1, str2+1);
    int ins = distant (str1, str2+1);
    int del = distance (str1+1, str2);

    unsigned int minDis = sub;
    minDis = (ins < minDis) ? insert : minDis;
    minDis = (del < minDis)? del:minDis;



}
int main(){
    char test_string[21] {"Hello WOrld"};
    std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;

    return 0;
}