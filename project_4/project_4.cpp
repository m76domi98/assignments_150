#include <iostream>
#include <fstream>
#include <cassert>

std::size_t length( char const *a ){
    std::size_t count = 0;

    while(a[count] != '\0'){
        count++;
    }
    return count;

}

int compare( char const *str1, char const *str2 ){
    int k {0};

    while ((str1[k] != '\0') && (str2[k] != '\0')){
        if (str1[k] < str2[k]){
            return -1; // str1 comes before str2
        } else if (str1[k] > str2[k]) {
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
    if (str1[k] == '\0'){
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
    str1[i]= '\0';
}

unsigned int distance( char const *str1, char const *str2 ){
    // base case
    if (*str1 =='\0'){
        return (length(str2));
        // i could also just use the length function i used before
        // i ended up using the length function i wrote
    }
    else if (*str2 =='\0'){
        return (length (str1));

    } else if (*str1== *str2){
        return distance (str1+1, str2+1);

        // first two ch are the same so i need to check the next
    }else{

    // if first ch are diff, calc min distance
    int sub = distance (str1+1, str2+1);
    int ins = distance (str1, str2+1);
    int del = distance (str1+1, str2);

    unsigned int minDis = sub;
    minDis = (ins < minDis) ? ins: minDis;
    minDis = (del < minDis)? del:minDis;

    return minDis+1;
    }

}

std::size_t is_sorted (char* array[], std::size_t capacity){
    for (std::size_t i {1}; i < capacity; i++){
        if (compare(array[i-1], array[i]) > 0) {
            return i;
        }
    }
    return capacity;
}

void insert(char *array[], std::size_t capacity){
    assert (capacity>0);

    char *val = array[capacity -1];
   std::size_t str_length = length(array[capacity -1]);


    assign(val, array[capacity-1]);
    std::size_t i = capacity -2;

    while ((i>=0) && (compare(array[i], val) > 0)){
        array [i+1] = array [i]; // shifts string right like one indice
        if (i == 0){
            break;
        }

        i--;
    }

    array[i+1] = val;
}

void insertion_sort(char *array[], std::size_t capacity) {

    for (std::size_t i =1; i < capacity; ++i){
        // insert every elememnt for inidice 1 to cap -1
        insert (array, i+1);
    }
    assert(is_sorted(array, capacity));
}

std::size_t remove_duplicates (char *array[], std::size_t capacity){
    if (capacity== 0){
        return  0;
    }

    std::size_t unique_c = 1;
    
    for (std::size_t i {1}; i < capacity; ++i){
        // if the element is diff from prev then i move it
        if (array[i]!= array[i-1]){
            array[unique_c] = array[i];
            ++unique_c;
        }
    }
    return unique_c;
}

// im gonna make a function to use in my find function that checls if the strings are equal
bool equalS (const char * str1, const char *str2){
    while (*str1 && *str2){
        if (*str1 != *str2){
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0') && (*str2 == '\0');

}

std::size_t find (char * array[], std::size_t capacity, char const *str){
    std::size_t b_index = 0;

    unsigned int min_dist = ~0u; // max unigned int value (4294967295)

    for (std::size_t i {0}; i < capacity; i++){
        if (equalS(array[i], str)){
            return i; 
            // then the string is found at index i
        }

        unsigned int c_dist = distance (array[i], str);

        if (c_dist < min_dist){
            min_dist = c_dist;
            b_index = 1;
        }
    }

    return b_index;
}

// void read_words_from_file(char const *filename, char **&word_array, std::size_t &num_words, std::size_t  width) {

//     // Attempt to open the file
//     std::ifstream file{ filename };
//     if (!file.is_open()) {
//         std::cout << "[ERROR] " << filename << " not found or could not open file" << std::endl;
//     }
//     assert( file.is_open() );

//     // Read the number of words from the first line of the file
//     file >> num_words;

//     // Ignore the newline '\n' character after the number
//     file.ignore();

//     /// Allocate memory and initialize the word array
//     word_array = new char*[num_words]{};                // pointers to individual words
//     word_array[0] = new char[num_words*(width + 1)]{};  // contiguous list of all words

//     for ( std::size_t k{ 1 }; k < num_words; ++k ) {    // connect the individual word pointers
//         word_array[k] = word_array[k-1] + width + 1;
//     }


//     // Read from the file into the word array
//     for ( std::size_t k{ 0 }; k < num_words; ++k ) {
//         file >> word_array[k];
//     }

//     file.close();
// }

// void free_word_array(char **word_array){
//     if(word_array){
//         delete[] word_array[0];
//         delete[] word_array;
//     }
// }

int main() {
    std::size_t const WIDTH{ 20 }; // set the maximum number of letters in a word
     
    char **test_words{};            // empty word array
    std::size_t num_test_words{};   // number of words (will be modified when a file is read)

    // populate the word array, and update the number of words
    //read_words_from_file("test_words.txt", test_words, num_test_words, WIDTH );

      //////////////////////
     // Function Testing //
    //////////////////////
    char test_string[21] {"cat"};

    // length
    std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;
    
    // comapare
    int test_compare { compare ( test_string, "dog") };
    if ( test_compare < 0 ) {
        std::cout << "The test_string comes before dog" << std::endl;
    } else if ( test_compare > 0 ) {
        std::cout << "The test_string comes after dog" << std::endl;
    } else {
        std::cout << "The test_string is dog" << std::endl;
    }

    // assign
    assign(test_string, "bird");
    std::cout << test_string << std::endl;
    
    // distance
    std::cout << "The distance between " << test_string 
              << " and hat is " << distance(test_string, "hat") << std::endl;

    // is sorted
    std::size_t num_sorted = is_sorted( test_words, num_test_words );
    if ( num_sorted == num_test_words ) {
        std::cout << "The test_words array is sorted." << std::endl;
    } else {
        std::cout << "Only the first " << num_sorted << " words are sorted." << std::endl;
    }

    /// Insert additional tests as needed

    // deallocate
    //free_word_array(test_words);

    return 0;
}