#include<iostream>
using namespace std;

void display_soduku(int soduku[9][9]);
int check_value(int soduku[9][9], int, int, int);
int solve_soduku(int soduku[9][9], int, int);

int main(){

    int soduku[9][9] = {
        {3,0,0,0,2,0,0,7,0},
        {9,0,0,5,0,0,0,1,4},
        {0,1,6,3,7,0,0,0,8},
        {2,0,0,8,0,0,0,0,1},
        {5,0,0,0,4,1,8,0,0},
        {0,8,9,0,0,0,0,5,0},
        {0,0,5,0,1,0,2,8,0},
        {0,4,0,0,0,6,0,9,3},
        {7,3,1,0,8,2,0,0,0}
    };

    cout<<"\nSoduku before solving ";
    display_soduku(soduku);

    // cout<<check_value(soduku, 5, 0, 1);

    if(solve_soduku(soduku, 0, 0)){
        cout<<"The soduku is solved: \n";
        display_soduku(soduku);
    }
    else{
        cout<<"Soduku is not solveable";
    }

    return 0;
}

void display_soduku(int soduku[9][9]){

    cout<<endl;
    cout<<" - - - - - - - - - - - - - - -\n";
    for(int i=0;i<9;i++){
        if(i%3 == 0 && i!=0) cout<<" - - - - - - - - - - - - - - -\n";
        for(int j=0;j<9;j++){
            if(j%3 == 0) cout<<"|";
            cout<<" "<<soduku[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<" - - - - - - - - - - - - - - -\n";
    cout<<endl;

}

int check_value(int soduku[9][9], int value, int row, int col){

    for(int i=0;i<9;i++){
        if(soduku[row][i] == value) return 0;
    }

    for(int i=0;i<9;i++){
        if(soduku[i][col] == value) return 0;
    }

    int r = row - row % 3;
    int c = col - col % 3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(soduku[r+i][c+j] == value) return 0;
        }
    }

    return 1;
}

int solve_soduku(int soduku[9][9], int row , int col){

    if(col == 9){
        if(row == 8) return 1;
        row++;
        col = 0;
    }


    if(soduku[row][col] > 0) return solve_soduku(soduku, row, col+1);
    
    for(int i=1; i<=9; i++){
        if(check_value(soduku, i, row, col)){
            soduku[row][col] = i;
            if(solve_soduku(soduku, row, col+1)){
               return 1; 
            }
            soduku[row][col] = 0;
        }
    }

    return 0;

}
