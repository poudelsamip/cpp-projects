
#include<iostream>
using namespace std;

void addtask(string task[20], int* count);
void removetask(string task[20], int* count);

int main(){
    int choice, count=0;
    string task[20];
    do{
        cout<<endl<<"##----- WELCOME TO TO-DO LIST APP -----##"<<endl;
        if(count>0){
            cout<<endl<<"<---- Your Tasks ---->"<<endl;
            for(int i=0;i<count;i++){
                cout<<i+1<<". "<<task[i]<<endl;
            }
        }
        else{
            cout<<endl<<"No tasks available.";
        }
        cout<<endl<<"1. Add task"<<endl;
        cout<<"2. Remove task"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addtask(task, &count);
            break;
        
        case 2:
            removetask(task, &count);
            break;
        case 0:
            cout<<endl<<"Program Exiting ...... ";
        }
    }while(choice!=0);
    return 0;
}

void addtask(string task[20], int* count){
    string todo;
    cout<<"Enter task : ";
    cin.ignore();
    getline(cin,todo);
    task[*count] = todo;
    (*count)++;
    cout<<endl<<endl;
    return;
}

void removetask(string task[20], int* count){
    if(*count>0){
        int choice;
        cout<<"Task No: ";
        cin>>choice;
        for(int i=(choice-1);i<*count;i++){
            task[i] = task[i+1];
        }
        (*count)--;
        return;
    }
    else{
        cout<<"No tasks to remove."<<endl;
        return;
    }
}
