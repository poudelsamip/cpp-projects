// This is a C++ code for console based tic-tac-toe game.
// This game has a major flaw --> You can place X or O even in places that are already in use.
// will update in next time.

#include<iostream>

using namespace std;

int checkwin(char board[3][3], char player){
    for(int i=0;i<3;i++){    // Row check garxa
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            return 1;
        }
    }
    for(int i=0;i<3;i++){    // Column check garxa
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player){
            return 1;
        }
    }
    // diagonal ko lagi
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player){
        return 1;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player){
        return 1;
    }
}

int main(){
    int count=0;
    char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    do{
        int x, y;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<board[i][j];
                cout<<" ";
            }
            cout<<endl;
        }
        if(count%2==0){
            cout<<endl<<"'X' turn"<<endl;
            cout<<"Enter Place: ";
            cin>>x>>y;
            board[x-1][y-1] = 'X';
            count++;
            if(checkwin(board,'X')==1){
                count = 20;
            }
        }
        else{
            cout<<endl<<"'O' turn"<<endl;
            cout<<"Enter Place: ";
            cin>>x>>y;
            board[x-1][y-1] = 'O';
            count++;
            if(checkwin(board,'Y')==1){
                count = 30;
            }
        }
        cout<<endl;
    }while(count<=9);
    if(count==20) cout<<endl<<"X WINS !!  ";
    if(count==30) cout<<endl<<"Y WINS !!  ";
    if(count==9) cout<<endl<<"DRAW";
    return 0;
}
