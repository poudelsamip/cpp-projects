#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;

int main(){
    string strcollection[] = {
        "The quick brown fox jumps over the lazy dog",
        "The five boxing wizards jump quickly",
        "Like this video and subscribe this channel",
    };
    int n = 3;
    srand(time(NULL));
    int random = rand() % 3;

    string sentence = strcollection[random];
    int size = sentence.length();
    time_t start = time(NULL);

    cout<<sentence<<endl;
    string inputstring="";
    char ch;
    int index = 0;

    while(index < size){

        ch = _getch();
        if(ch == sentence[index]){
            cout<<ch;
            inputstring += ch;
            index++;
        }

    }
    
    time_t end = time(NULL);

    int word = 1;
    for(int i=0;i<size;i++) if(inputstring[i] == ' ') word++;
    double timetaken = difftime(end, start);

    int wpm = (word/timetaken) * 60;
    cout<<"\nTime : "<<timetaken<<" Seconds"<<endl;
    cout<<"WPM : "<<wpm;
    return 0;
}
