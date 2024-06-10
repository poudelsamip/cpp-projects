#include<iostream>
#include<windows.h>
using namespace std;

void timer(int hr, int min, int sec){
       while(hr>0 || min>0 || sec>0){
        cout<<hr<<" : "<<min<<" : "<<sec;
        Sleep(1000);
        system("cls");
        sec--;
        if(sec<0){
            min--;
            sec = 59;
        }
        if(min<0){
            if(hr>0){
                hr--;
                min = 59;
            }
            else{
                min = 0;
            }
        }
    }
}

void stopwatch(int h, int m, int s){
    int hr=0,min=0,sec=0;
    while(hr!=h || min!=m || sec!=s){
        cout<<hr<<" : "<<min<<" : "<<sec;
        Sleep(1000);
        system("cls");
        sec++;
        if(sec>59){
            sec = 0;
            min++;
        }
        if(min>59){
            min = 0;
            hr++;
        }
    }
}
int main(){
    int hr,min,sec;
    cout<<"1. Timer"<<endl<<"2. Stopwatch"<<endl;
    int choice;
    cin>>choice;
    cout<<"Enter hours: ";
    cin>>hr;
    cout<<"Enter minutes: ";
    cin>>min;
    cout<<"Enter seconds: ";
    cin>>sec;
    if(choice==1) timer(hr,min,sec);
    if(choice==2) stopwatch(hr,min,sec);
    cout<<"Time Up";
    return 0;
}
