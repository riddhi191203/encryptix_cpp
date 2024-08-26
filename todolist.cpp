#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>
using namespace std;
int ID;
struct todo {
    int id;
    string task;
};
void addTodo() {
    cout<<"\t\t\t                     WELCOME TO Your ToDo List                     "<<endl;
    cout<<endl;
    cout<<endl;
    
    todo todo;
    cout << "\n\tEnter new task : ";
    cin.get();
    getline(cin, todo.task); 
    ID++; 

    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"\n\tDo you want to add more task? y or n : "; cin>> ch;
    if(ch == 'y'){
        addTodo();
    }
    else{
        cout << "\n\tTask has been added successfully";
        return;
    }
}
void print(todo s) {
    cout << "\tID is : " << s.id;
    cout << "\tTask is : " << s.task;
}
void readData() {
    cout<<"\t\t\t                     WELCOME TO Your ToDo List                     "<<endl;
    cout<<endl;
    cout<<endl;
    
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t\t\t------------------Your current Tasks in the list--------------------";
        while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}
int searchData() {
    cout<<"\t\t\t                     WELCOME TO Your ToDo List                     "<<endl;
    cout<<endl;
    cout<<endl;

    int id;
    cout << "\n\tEnter task id : ";     cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}
void deleteData() {
    cout<<"\t\t\t                     WELCOME TO Your ToDo List                     "<<endl;
    cout<<endl;
    cout<<endl;

    int id = searchData();
    cout << "\n\tDo you want to delete this task? y or n : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}


int main()
{
	cout<<"\t\t\t                     WELCOME TO Your ToDo List                     "<<endl;
    cout<<endl;
    cout<<endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<endl<<endl;
        cout << "\n\t1.Add task: ";
        cout << "\n\t2.See tasks: ";
        cout << "\n\t3.Search tasks: ";
        cout << "\n\t4.Delete tasks: ";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addTodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        default: cout<<"Enter Choice between 1 to 4";
        }
    }
}