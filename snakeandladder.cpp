#include<iostream>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;

void displayBoard(char p1, char p2, int pos1, int pos2, int snake[], int ladder[]){

    const int size = 100;
    const int columns = 10;

    cout << "\n+----+----+----+----+----+----+----+----+----+----+\n| ";

    for(int i = 1; i <= size; i++){
        
        if (i < 10) cout<<' ';
        if(i == 100){
            if(pos1 == 100) cout<<p1<<" |";
            else if(pos2 == 100) cout<<p2<<" |";
            else cout<<100<<"|";
            cout<<"\n+----+----+----+----+----+----+----+----+----+----+\n";
            break;
        }
        // if(i == pos1 && i == pos2) cout<<"\b \b@&";
        else if(i == pos1) cout<<p1;
        else if(i == pos2) cout<<p2;
        else cout<<i;
        if(i >= 10 && (i == pos1 || i == pos2)) cout<<' ';
        if(i % columns == 0){
            cout<<" |\n+----+----+----+----+----+----+----+----+----+----+\n| ";
        }
        else{
            cout<<" | ";
        }
    }

    cout<<"Snakes position: ";
    for(int i=0; i<8; i++) cout<<snake[i]<<" ";
    cout<<"\nLadders position: ";
    for(int i=0; i<8; i++) cout<<ladder[i]<<" ";

    cout<<"\n\nCurrent Position => ";
    cout<<p1<<" : "<<pos1;
    cout<<" | "<<p2<<" : "<<pos2<<"\n\n";
    
}

int check_position(int &position, int &oppPosition){

    if(position > 100) return 101;

    if(position == oppPosition){
        oppPosition = 0;
        return 1;
    }

    int snake[] = {28, 37, 44, 52, 68, 77, 89, 98};
    int ladder[] = {10, 26, 39, 50, 62, 68, 70, 80};

    for(int i=0; i<8; i++){
        if(position == snake[i]){
            position -= 0.9*snake[i];
            return 2;
        }
        if(position == ladder[i]){
            position += 0.5*(100 - ladder[i]);
            return 3;
        }
    }
    return 0;

}

void play(int &position, char cp, int &oppPosition, bool computer, int &counter){

    cout<<cp<<"'s turn to roll the dice."<<endl;
    if(computer) Sleep(2500);
    int dice;
    if(!computer){

        cout<<"Press ENTER key to roll dice.";
        char ch = _getch();
        dice = rand() % 6 + 1;
        system("cls");
    
    }
    else{
        dice = rand() % 6 + 1;
    }
    cout<<"Dice rolling ";

    if(dice == 6 || dice == 1) counter--;

    int c = 0;
    while(c < 5){
        cout<<". ";
        Sleep(300);
        c++;
    }
    
    position += dice;
    if(position == 100){
        cout<<cp<<" won";
        return;
    }
    system("cls");

    cout<<cp<<" rolled "<<dice<<endl;
    
    int value = check_position(position, oppPosition);
    char opp = (cp == 'A')? 'A': 'B';
    if(value == 1) cout<<opp<<" back to base."<<endl;
    if(value == 2) cout<<"Snake bit "<<cp<<endl;
    if(value == 3) cout<<cp<<" found ladder"<<endl;

}


int main(){

    system("cls");

    bool computer;

    int choice;
    cout<<"1. Player vs Player"<<endl;
    cout<<"2. Player vs Computer"<<endl;
    cout<<"Enter Game Mode (1/2) : ";
    cin>>choice;

    if(choice == 1) computer = false;
    else computer = true;

    system("cls");
    int snake[] = {28, 37, 44, 52, 68, 77, 89, 98};
    int ladder[] = {10, 26, 39, 50, 62, 68, 70, 80};

    srand(time(NULL));

    int pos1 = 0;
    int pos2 = 0;
    char p1 = 'A';
    char p2 = 'B';
    int gameCounter = 0;

    displayBoard(p1, p2, pos1, pos2, snake, ladder);
    while(pos1 != 100 || pos2 != 100){

        if(gameCounter % 2 == 0) {
            play(pos1, p1, pos2, false, gameCounter);
        
        }
        else{
            play(pos2, p2, pos1, computer, gameCounter);
        }
        gameCounter++;
        displayBoard(p1, p2, pos1, pos2, snake, ladder);

    }

    return 0;
}
