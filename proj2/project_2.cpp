#include <iostream>
#include <cassert>
int main();
void pattern(unsigned int n){
    int sp=0;
    if (n==0){
        std::cout<<"*";
        std::cout<<std::endl;
    }else{
        for(int i=n;i>=0;i--,sp++){
            for (int k=sp; k>0;k--){
                std::cout<<' ';
            }
            for(int j=i*2+1;j>0;j--){
                std:: cout<<"*";
            }   
            std::cout<<std::endl;
        }
        sp=sp-2;
        for( unsigned int i=1;i<=n;i++,sp--){
            for (int k=sp; k>0;k--){
                std::cout<<' ';
            }
            for(int j=i*2+1;j>0;j--){
                std:: cout<<"*";
            }
            std::cout<<std::endl;
        }
    }
}

unsigned int log10(unsigned int n){
    assert (n!= 0);
    int m = 0;

    while (n>=10) {
        n/=10;
        ++m;
    }
    return m;
}


unsigned int count(unsigned int n, unsigned int bit){
    assert(bit ==0 || bit == 1);
    
    int m = 0;
    
    while(n!=0){
            if ((n&1)==1){
                m+=1;
            }
            n>>=1;
        }
        
        if (bit==1){
            return m;
        }
        else{
            return (32-m);
        };
}

unsigned int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1 ){
    // the function will not run if b0 and b1 are not integers
    assert(b0 >= 0 && b0 < 4);    // making sure b0 is between 0 and 3
    assert(b1 >= 0 && b1 < 4);    // making usre b1 is between 0 and 3

    if (b0==b1){
        return n;   //condition if b1 and b2 are equal to just return the variable n
    } else{
        //0xFF is the binary value 11111111 aka one byte
        unsigned int m0= 0xFF<< (b0*8);  //creates mask to isolate b0 in integer n
        unsigned int m1= 0xFF<< (b1*8); // creates mask to isolate b1 in integer n, positioning mask over byte at position b1
        unsigned int by0= (n & m0)>>(b0*8);  // extracts valye of byte b0 from n in lease significant byte position
        unsigned int by1= (n & m1)>> (b1*8); //by1 contains value of byte b1 in least significant byte position
        
        // tilde m0 or tilde m1 inverts mask m0 which turns bits to zero and others to one
        // n &= ~m0 is bitwise and setting byte b0 to 0 while leaving other bytes unchanged.
        n&=~m0;  //sets to zero the byte at possition b0 in n
        n&=~m1;  // makes sure that byte b1 is ready to receive the new value.
        n|=(by0<<(b1*8));// insert og byte b0(by0) into byte position b1
        n|=(by1<<(b0*8)); // insert og byte b1(by1) into byte pos b0
        return n;
    }
}

int main() {

    unsigned int rows;
    std::cout<<"Enter the number of rows: ";
    std::cin>> rows;
    pattern(rows);


    unsigned int numb;
    std::cout<<"Enter the number for logarthim: ";
    std::cin>> numb;
    std::cout<<std::endl;
    std::cout<<log10(numb)<<" is the largest exponent";



    unsigned int integ;
    std::cout<<std::endl;
    std::cout<<"Enter the number: ";
    std::cin>> integ;
    std::cout<<std::endl;
    unsigned int bit;
    std::cout<<"Enter the bit: ";
    std::cin>>bit;
    std::cout<<std::endl;
    std::cout<<count(integ,bit);
    std::cout<<std::endl;
    
    unsigned int p;
    unsigned int b0;
    unsigned int b1;
    std::cout<<"Enter the number swapping to be in: ";
    std::cin>>p;
    std::cout<<std::endl;
    std::cout<<"Enter the number bit 1 location between 0 and 3: ";
    std::cin>>b0;
    std::cout<<std::endl;
    std::cout<<"Enter the number bit 2 location between 0 and 3: ";
    std::cin>>b1;
    std::cout<<std::endl;
    std::cout<<swap_bytes(p,b0,b1);
    return 0;
}