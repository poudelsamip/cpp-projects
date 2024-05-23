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

bool checkplace(char board[3][3], int x, int y){
    if(board[x][y]=='-'){
        return true;
    }
    else{
        cout<<x+1<<" "<<y+1<<" is already occupied."<<endl;
        return false;
    }
}

void play(char board[3][3], int* count, char player){
    int x, y;
    cout<<endl<<player<<" turn"<<endl;
    do{
        cout<<"Enter Place: ";
        cin>>x>>y;
    }while(!checkplace(board,x-1,y-1));
    board[x-1][y-1] = player;
    (*count)++;
    return;
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
            play(board,&count,'X');
            
            if(checkwin(board,'X')==1){
                count = 20;
            }
        }
        else{
            play(board,&count,'O');

            if(checkwin(board,'O')==1){
                count = 30;
            }
        }
        cout<<endl;
    }while(count<=9);
    if(count==20) cout<<"X WINS !!  ";
    if(count==30) cout<<"O WINS !!  ";
    if(count==9) cout<<"DRAW";
    return 0;
}
