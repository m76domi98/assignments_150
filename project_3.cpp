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
        delete[] ptr;
    } else {
        *ptr =0.0;
        delete ptr;
    }
    ptr = nullptr;

}

double *geometric( double a, double ratio, std::size_t cap ) {
    double *arr {new double[cap]{}};

    if (cap >0){

        arr[0] = a;

        for (int sh =1; sh <cap; sh++){
            arr[sh] = (arr[sh-1])* (ratio);
        }
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

std::size_t shift_duplicates(int array[], std::size_t capacity) {
    //variable declrations
    int duplicate_array[capacity];
   std::size_t dup_count {0};
   std::size_t unique_num {0};
   int temporary_array[capacity]{};


    // if cap is 0 then i just return 0
    if (capacity == 0){
        return 0;
    }

    for (std::size_t i{0}; i < capacity;i++){
        //make a bool tracking if a duplicate is there
        bool dup_IS{false};

        for (std::size_t j{0}; j < unique_num; j++){
            //checking if duplicate is there
            if (array[i]== array[j]){
                dup_IS = true;
                break;
            }
        }

        //if duplicate is there adds it to duplicate array otherwise to uniquearray
        if (dup_IS){
            duplicate_array[dup_count++] = array[i];
        } else{
            temporary_array[unique_num++]= array[i];
        }
    }
    // i add the duplicate numbers to end of unique array (temporary array)
    for (std::size_t k{0}; k < dup_count;k++){
        temporary_array[unique_num+k] = duplicate_array[k];
    }
    //now i add the temp array to the array array
    for (std::size_t k {0}; k < capacity; k++){
        array[k] = temporary_array[k];
    }

    // this was just testing
    // for (std::size_t m = 0; m <capacity; m++){
    //     std::cout << array[m] << " ";
    // }

    return unique_num;
}

int main () {
    double * test1{ geometric ( 1.0, 2.0, 4 ) };

    double arr0[0]{};
    double arr1[3]{0, 0, 0};
    double * test2{ cross_correlation( arr0, 0, arr1, 3) };

    int arr2[20]{2446, 2446, 7007, 1332, 3652, 5990, 204, 2583, 4852, 7197, 1446, 3774, 6040, 370, 2606, 4990, 7211, 1518, 3882, 6125};
    
    std::size_t num_unique { shift_duplicates( arr2, 20) };
    std::cout << shift_duplicates( arr2, 20) <<std::endl ;


    deallocate(test1, true, 4);
    deallocate(test2, true, 5);

    // don't forget the default parameter
    double * test3 { new double {4} };
    deallocate(test3, false);

    return 0;
}