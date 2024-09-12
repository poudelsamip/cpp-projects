#include<iostream>
#include<windows.h>
using namespace std;

bool checkwin(char board[3][3], char player){
    // for horizontal
    for(int i=0;i<3;i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            return true;
        }
    }
    // for vertical
    for(int i=0;i<3;i++){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player){
            return true;
        }
    }
    // for diagonal
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player){
        return true;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player){
        return true;
    }
    return false; // return false if no above conditions are matched.
}

void showBoard(char board[3][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j>0) cout<<"| ";
            cout<<board[i][j];
            cout<<" ";
        }
        cout<<endl;
        if(i<2) cout<<"--+---+--";
        cout<<endl;
    }
}

bool checkplace(char board[3][3], int x, int y){
    if(x>=3 || y>=3){
        cout<<"Please enter valid position."<<endl;
        return false;
    }
    if(board[x][y]==' '){
        return true;
    }
    else{
        cout<<x+1<<" "<<y+1<<" is already occupied."<<endl;
        return false;
    }
}

bool isEmpty(char board[3][3], int x, int y){
    if(board[x][y] == ' ') return true;
    else return false;
}

bool play(char board[3][3], int &count,char player){
    int x, y;
    cout<<endl<<player<<" turn"<<endl;
    do{

        cout<<"Enter position: ";
        cin>>x>>y;

    }while(!checkplace(board,x-1,y-1));
    board[x-1][y-1] = player;
    count++;
    if(checkwin(board,player))
        return true;
    else
        return false;
}

void computerPlay(char board[3][3], int &count, char player){
    count++;
    // is there any place we win if we put O there?
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(isEmpty(board, i, j)){
                board[i][j] = player;
                if(checkwin(board, player)) return;
                board[i][j] = ' ';
            }
        }
    }
    // is there any place other will win? if yes place O there.
    char enemy;
    if(player == 'X') enemy = 'O';
    else enemy = 'X';
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(isEmpty(board, i, j)){
                board[i][j] = enemy;
                if(checkwin(board, enemy)){
                    board[i][j] = player;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // if center available then put O there.
    if(board[1][1] == ' '){
        board[1][1] = player;
        return ;
    }
    //check all corners and place in one if available.
    if(board[0][0] == ' '){
        board[0][0] = player;
        return;
    }
    if(board[0][2] == ' '){
        board[0][2] = player;
        return;
    }
    if(board[2][0] == ' '){
        board[2][0] = player;
        return;
    }
    if(board[2][2] == ' '){
        board[2][2] = player;
        return;
    }

    // if not possible for any above
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ' '){
                board[i][j] = player;
                return;
            }
        }
    }

}

int main(){
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int count=0;
    int choice;
    cout<<"1. Player vs Computer"<<endl;
    cout<<"2. Player vs Player"<<endl;
    cout<<"3. Computer vs Computer"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    do{
        system("cls");
        showBoard(board);

        if(count%2 == 0 && (choice == 1 || choice == 2)) {
            if(play(board, count, 'X')) break;
        }
        else if(count%2 == 0 && choice == 3){
            cout<<"\nX's turn"<<endl;
            cout<<"Searching best spot ...";
            Sleep(1500);
            computerPlay(board, count, 'X');
            if(checkwin(board, 'X')) break;
        }
        else if(count%2 == 1 && (choice == 1 || choice == 3)){
            cout<<"\nO's turn"<<endl;
            cout<<"Searching best spot ...";
            Sleep(1500);
            computerPlay(board, count, 'O');
            if(checkwin(board, 'O')) break;
        }
        else{
            if(play(board, count, 'O')) break;
        }

    }while(count<9);

    system("cls");
    showBoard(board);
    if(count%2 == 0 && count < 9)
        cout<<"\nO WINS !!\n";
    else if(count%2 == 1 && count < 9)
        cout<<"\nX WINS !!\n";
    else
        cout<<"\nGAME DRAW\n";
    return 0;
}
