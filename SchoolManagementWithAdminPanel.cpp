#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
using namespace std;

void typepassword(string& pw){
    char ch;
    int idx = 0;
    while(1){
        ch = _getch();
        if(ch == '\b'){
            if(idx > 0){
                cout<<"\b \b";
                idx--;
                pw.pop_back();
            }
        }
        else if(ch == '\r')
            break;
        else{
            cout<<'*';
            pw.push_back(ch);
            idx++;
        }
    }
}

class user{
protected:
    string name;
    string uname;
    string password;
public:
    user(){}
    user(string name, string uname, string password){
        this->name = name;
        this->uname = uname;
        this->password = password;
    }
    void info(){
        cout<<"Name \t: "<<name<<endl;
    }
};
class student : public user{
    string sid;
    int grade;
    int duefees;
public:
    friend class admin;
    student(){}
    student(string sid, string name, string uname, string password, int grade, int duefees) : user(name, uname, password){
        this->sid = sid;
        this->grade = grade;
        this->duefees = duefees;
    }

    void info(int n = 0){
        if(n == 0) system("cls");
        user::info();
        cout<<"ID\t: "<<sid<<endl;
        cout<<"Grade\t: "<<grade<<endl;
        cout<<"Dues\t: "<<duefees<<endl;
        if(n == 0){
            cout<<"\nPress ENTER to go back";
            _getch();
        }
    }
    friend int handleLogin(string uname, string pass, const vector<student>& s);
    void changelogininfo(){
        string oldpw;
        system("cls");
        cout<<"Enter old password\t: ";
        cin>>oldpw;
        if(password == oldpw){
            cout<<"Enter new password\t: ";
            cin.ignore();
            getline(cin,password);
            cout<<"Password Changed Successfully! ";
            _getch();
        }
        else{
            cout<<"Password Incorrect ";
            _getch();
        }
    }
};
class teacher : public user{
    string tid;
    int salary;
public:
    teacher(){}
    teacher(string name, string uname, string password ,string tid, int salary) : user(name, uname, password){
        this->tid = tid;
        this->salary = salary;
    }
    void info(){
        user::info();
        cout<<"ID\t: "<<tid<<endl;
        cout<<"Salary\t: "<<salary<<endl;
    }
};
class admin : public user{
public:
    admin(){}
    void addStudent(vector<student>& s){
        system("cls");
        string sid, name, unmae, password;
        int grade;
        cout<<"Enter name\t: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Set new ID\t: ";
        cin>>sid;
        cout<<"Set username\t: ";
        cin>>uname;
        cout<<"Set password\t: ";
        cin>>password;
        cout<<"Enter grade\t: ";
        cin>>grade;
        student temp(sid,name,uname,password,grade,10000);
        s.push_back(temp);
        cout<<"\nNew Student Successfully Added ! ";
        _getch();
    }
    void viewStudents(vector<student>& s){
        system("cls");
        cout<<"Name\t\tID\t\tGrade\t\tDue"<<endl<<endl;
        for(student std : s){
            cout<<std.name<<"\t\t"<<std.sid<<"\t\t"<<std.grade<<"\t\t"<<std.duefees<<endl;
        }
        _getch();
    }
    void addTeacher(vector<teacher>& t){
        string tid, name, unmae, password;
        int salary;
        cout<<"Enter TID NAME UNAME PASSWORD & SALARY in order"<<endl;
        cin>>tid>>name>>uname>>password>>salary;
        teacher temp(tid,name,uname,password,salary);
        t.push_back(temp);
    }
    void feepayment(vector<student>& s){
        system("cls");
        bool found = false;
        cout<<"Fee Payment"<<endl<<endl;
        int amount;
        string id;
        cout<<"Enter Student ID : ";
        cin>>id;
        for(student &std : s){
            if(std.sid == id){
                std.info(1);
                cout<<endl<<"Enter amount : ";
                cin>>amount;
                std.duefees -= amount;
                found = true;
                cout<<"Fee paid successfully";
                break;
            }
        }
        if(!found) cout<<"No student with id "<<id<<" found"<<endl;
        _getch();
    }
};

int handleLogin(string uname, string pass, const vector<student>& s){
    bool username;
    bool password;
    int usernum = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i].uname == uname){
            username = true;
            if(s[i].password == pass){
                usernum = i;
            }
            break;
        }
        username = false;
    }
    if(usernum == -1) throw "\nLogin Details Incorrect";
    return usernum;
}

void showMenu(int usernum, vector<student>& s){
    while(1){
        system("cls");
        int ch;
        cout<<"Student Portal"<<endl<<endl;
        cout<<"1. View Info"<<endl;
        cout<<"2. Change LogIn info"<<endl;
        cout<<"0. Log Out"<<endl;
        cin>>ch;
        if(ch == 1){
            s[usernum].info();
            system("cls");
        }
        else if(ch == 2)
            s[usernum].changelogininfo();
        if(ch == 0) break;
    }
    return;
}

void adminMenu(admin& a, vector<student>& s){
    while(1){
        system("cls");
        cout<<"WELCOME TO ADMIN PORTAL"<<endl<<endl;
        cout<<"1. ADD students"<<endl;
        cout<<"2. VIEW all students"<<endl;
        cout<<"3. Fee Payment"<<endl;
        cout<<"Press ENTER to go back"<<endl;
        char ch;
        ch = _getch();
        if(ch == '1'){
            cout<<'1';
            _getch();
            a.addStudent(s);
        }
        else if(ch == '2'){
            cout<<'2';
            _getch();
            a.viewStudents(s);
        }
        else if(ch == '3'){
            cout<<'3';
            _getch();
            a.feepayment(s);
        }
        else break;
    }
}

int main(){
    vector<student> s;
    vector<teacher> t;
    admin a;
    while(1){
        system("cls");
        cout<<"WELCOME TO ONLINE PORTAL"<<endl<<endl;
        cout<<"1. Student Login"<<endl;
        cout<<"2. Admin Login"<<endl;
        int choice;
        cin>>choice;
        string un;
        string pw;
        system("cls");
        cout<<"PLEASE LOGIN TO CONTINUE"<<endl<<endl;
        
        if(choice == 1){
            cout<<"Username : ";
            cin>>un;
            cout<<"Password : ";
            typepassword(pw);
            try{
                int usernum = handleLogin(un,pw,s);
                showMenu(usernum, s);
            }
            catch(const char* error){
                cout<<error;
                _getch();
            }
        }
        else if(choice == 2){
            cout<<"Username : ";
            cin>>un;
            cout<<"Password : ";
            typepassword(pw);
            if(un == "admin" && pw == "admin"){
                adminMenu(a, s);
            }
            else{
                cout<<"\nLogin Credentials are incorrect";
                _getch();
            }
        }
        else break;
    }
    return 0;
}
