#include<iostream>
#include<fstream>
using namespace std;

void addtask(string task[20], int& count);
void removetask(string task[20], int& count);

int main(){
    int choice;
    string task[20];
    string newdata;
    // ifstream newfile("myfile.txt");
    // while(getline(newfile, newdata)){
    //     task[count++] = newdata;
    // }
    // newfile.close();
    // string data;
    do{
        int count = 0;
        ifstream file("myfile.txt");
        while(getline(file, newdata)){
            task[count] = newdata;
            count++;
        }
        system("cls");
        if(count>0){
            cout<<endl<<"<---- Your Tasks ---->"<<endl;
            for(int i=0;i<count;i++){
                cout<<i+1<<". "<<task[i]<<endl;
            }
        }
        else{
            cout<<endl<<"No tasks available.";
        }
        // int i=0;
        // cout<<"Your tasks: "<<endl;
        // while(getline(file,data)){
        //     cout<<i+1<<". "<<data<<endl;
        //     i++;
        // }
        cout<<endl<<"1. Add task"<<endl;
        cout<<"2. Remove task"<<endl;
        cout<<"0. Exit program"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        file.close();
        switch (choice){
        case 1:
            addtask(task, count);
            break;
        case 2:
            removetask(task, count);
            break;
        case 0:
            cout<<endl<<"Program Exiting ...... ";
        }
    }while(choice!=0);
    return 0;
}

void addtask(string task[20], int& count){
    system("cls");
    fstream file("myfile.txt",ios::app);
    string todo;
    cout<<"Enter task : ";
    cin.ignore();
    getline(cin,todo);
    file << todo;
    file << endl;
    task[count] = todo;
    count++;
    cout<<endl<<endl;
    file.close();
    return;
}

void removetask(string task[20], int& count){
    if(count>0){
        int choice;
        cout<<"Task No: ";
        cin>>choice;
        for(int i=(choice-1);i<count-1;i++){
            task[i] = task[i+1];
        }
        count--;
        ofstream file("myfile.txt");
        file.clear();
        for(int i=0;i<count;i++){
            file<<task[i]<<endl;
        }
        return ;
    }
    else{
        cout<<"No tasks to remove."<<endl;
        return;
    }
}
