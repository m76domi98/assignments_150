#include <iostream>
#include <cassert>

// this is my practice work which i have done by myself me myself and i
// thank you dw harder

// first two functions were done using my brain on october 31 instead of going out. thank you.
// second two functions i ised my brain on on nov 1 instead of going out AGAIN.

double *geometric( double a, double ratio, std::size_t cap );
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);
std::size_t shift_duplicates( int array[], std::size_t capacity );

void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0 ){
    if (is_array){
        
        for (int entries = 0; entries < capacity; entries++){
            ptr[entries]= 0.0;
            }
    } else {
        *ptr =0.0;
    }
    delete[]ptr;
    ptr = nullptr;

}
int main () {
    double * test1{ geometric ( 1.0, 2.0, 4 ) };

    double arr0[0]{};
    double arr1[3]{0, 0, 0};
    double * test2{ cross_correlation( arr0, 0, arr1, 3) };

    int arr2[0]{};
    std::size_t num_unique { shift_duplicates( arr2, 0) };

    deallocate(test1, true, 4);
    deallocate(test2, true, 5);

    // don't forget the default parameter
    double * test3 { new double {4} };
    deallocate(test3, false);

    return 0;
}

double *geometric( double a, double ratio, std::size_t cap ) {
    if (cap == 0) {
        return nullptr;
        }
    double *arr {new double[cap]{}};

    arr[0] = a;

    for (int sh =1; sh <cap; sh++){
        arr[sh] = (arr[sh-1])* (ratio);
    }
    return arr;

}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
    assert ((cap0+cap1)>=1);
    double *arr2 {new double[cap0 + cap1 - 1]{}};

    for (int i = 0; i <(cap0) ;i++){
        for (int j = 0 ; j <(cap1);j++)
        arr2[i+j] += array0[i] *array1[j];
    }
    return arr2;
}
std::size_t shift_duplicates_test( int array[], std::size_t capacity ){
    // int dupilicates{0};
    // for (int i = 0; i < capacity ;i++){
    //     for (int j = 0; j < capacity; j++){
    //         if (array[i]= array[j]){
    //             dupilicates++;
    //         }
    //     }
    // }
    // return capacity- dupilicates;

    for (int entries = 0; entries < capacity ; entries++){
        
        bool dupIs {false}; 
        if (capacity == 1){
            unique_Num = capacity;
            break;
        }
        for (int comparis= 0; comparis< unique_Num;++comparis){
            if(array[entries]== array[comparis]){
                dupIs = true;
                break;
            }
        }

        // move to unique selection if the thing is uniquw and the dup number goes into dup array
        if(!dupIs){
            array[unique_Num]= array[entries];
            ++unique_Num;
        }else {
            dupArr[dup_num]= dupArr[entries];
            ++dup_num;
        }

    }

    for (int m {0}; m < unique_Num; m++){
        array[unique_Num+ m] = array[m];
    }
    for (int n{0}; n < dup_num ; n++){
        dupArr[dup_num+n]= dupArr[n];
    }

    return unique_Num;
}

std::size_t shift_duplicates( int array[], std::size_t capacity ){
    int unique_Num {};
    bool dupIs {false};
    
    for (int entries = 0; entries < capacity ; entries++){

        dupIs = false; // this variable takes care of my if statements to check

        // in this duplicate i am checking if the array [entries] appears earleier
        // in like the unique section??
        // possibly this is 3 am
        for (int  comparis= 0; comparis< unique_Num;++comparis){
            if(array[entries]== array[comparis]){
                dupIs = true;
                break;
            }
        }

        // move to unique selection if the thing is uniquw
        if(!dupIs){
            array[unique_Num++]= array[entries];
        }

    }
    //now i want to make the remaining part of the array into like the duplicates
    for (int fill = unique_Num; fill < capacity;++fill){
        array[fill] = 0;
    }
    // now im gonna explain my logic since this is my work.
    /*

    first i identified unique element
    then i move to that position,and then unique is increemented
    then i fill in the position w zeros
    and then i return the number
    */
    return unique_Num;
}

