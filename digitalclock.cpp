#include<iostream>
#include<ctime>
#include<windows.h> //<unistd.h>
using namespace std;

int main(){
    
    char timeinformat[50];
    char dateinformat[50];
    while(true){

        system("cls");
        time_t rawtime;
        time(&rawtime); 

        struct tm* currenttime;
        currenttime = localtime(&rawtime); 

        strftime(timeinformat, 50, "%I:%M:%S %p", currenttime);
        strftime(dateinformat, 50, "%A %B %d, %Y", currenttime);

        cout<<"Current time : "<<timeinformat<<endl;
        cout<<"Current date : "<<dateinformat<<endl;
        Sleep(1000);

    }

    return 0;
}
