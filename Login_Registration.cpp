#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool LoggingIn(){
    string username, password, user , pass;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;
    
    ifstream read(username + ".txt");
    getline(read, user);
    getline(read, pass);

    if(user == username && pass ==password){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int choice;
    cout << "Enter your choice \n1.Register \n2.login\nYOur choice:";
    cin >> choice;

    if(choice == 1){
        string username,password;
        cout << "Enter your username: "; cin >> username;
        cout << "Enter your password: "; cin >> password;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password << endl; 
        file.close();

        main();
    }
    else if(choice == 2){

        bool status = LoggingIn();
        if(!status){
        cout << "Incorrect Information, Try again!" << endl;
        system("PAUSE");
        return 0;
        }
        else{
        cout << "Login successful" << endl;
        system("PAUSE");
        return 1;
        }
    }
    else{
        cout << "Error";
    }
    return 0;
}
