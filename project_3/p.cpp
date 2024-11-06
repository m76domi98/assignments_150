#include <iostream>


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

int main (){
    int arr2[20]{6692, 6692, 2, 2, 7820, 7820, 4474, 6787, 1041, 3364, 5696, 7926, 2244, 4519, 6882, 1160, 3459, 5750, 41, 2359};
    
    std::size_t num_unique { shift_duplicates(arr2, 20) };
    std::cout << shift_duplicates( arr2, 20) <<std::endl ;
}

