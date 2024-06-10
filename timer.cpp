#include<iostream>
#include<windows.h>
using namespace std;

void timer(int hr, int min, int sec){
    while(hr!=0 && min!=0 && sec!=0){
        cout<<hr<<" : "<<min<<" : "<<sec;
        Sleep(1000);
        system("cls");
        sec--;
        if(sec<=0){
            min--;
            sec = 59;
        }
        if(min<=0){
            hr--;
            min = 59;
        }
    }
}

int main(){
    int hr,min,sec;
    cout<<"Enter hours: ";
    cin>>hr;
    cout<<"Enter minutes: ";
    cin>>min;
    cout<<"Enter seconds: ";
    cin>>sec;
    timer(hr,min,sec);
    cout<<"Time Up";
    return 0;
}
