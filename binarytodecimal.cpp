// While this code runs fine it has a lot of problems.
// Input is taken in the form of integer which doesnot let us take bigger values of binary.

#include<iostream>
#include<math.h>
using namespace std;

int converter(int n){
    int decimal = 0;
    int p = 0;
    while(n>0){
        int value = (n%10)*pow(2,p);
        decimal += value;
        n/=10;
        p++;
    }
    return decimal;
}

int main(){
    int n;
    cout<<"Enter in binary: ";
    cin>>n;
    int res = converter(n);
    cout<<"Decimal value : "<<res;    
    return 0;
}
