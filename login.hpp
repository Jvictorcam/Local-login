#include <fstream>
#include <bits/stdc++.h>
#include <locale.h>
using namespace std;

//Variables:
char user[50];
char password[50];
char repss[50];
//end of Variables

void clear(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void readUser(){
    fflush(stdin);
    fgets(user, sizeof(user), stdin);
}

void readPassword(){
    fgets(password, sizeof(password), stdin);
}

int Welcome(){
    clear();
    int aux;
    cout << "Welcome to Project Carot!";
    cout << "Select the service u want: "
         << "\n-\n"
         << "(1): Login\n"
         << "(2): Register\n"
         << "(3): Exit\n"
         << "(4): About Us\n"
         << '-';
    cin >> aux;
    return aux;
}

bool Login(){
    
    readUser();
    readPassword();

    string userit;
    string passwordit;
    fstream file;
    file.open("data.txt", ios::app);
    file.close();
    file.open("data.txt", ios::in);
    if(!file.is_open()){
        cerr << "Data Error";
    }

    while(!file.eof()){
        
        //fgets(userit, sizeof(userit), file);
        //fgets(passwordit, sizeof(passwordit), file);
        getline(file, userit);
        getline(file, passwordit);
        if(userit == user && passwordit == password){
            return true;
        }
    }
    file.close();
    return false;
}

void Register(){
    
    cout << "Choose your Username: ";
    readUser();
    cout << user << "? Okay, its avaible\n";
    A:
    cout << "\nSet a Password: ";
    readPassword();
    fflush(stdin);
    cout << "Re-Write the Password: ";
    fgets(repss, sizeof(repss), stdin);
    fflush(stdin);
    if(repss != password){
        cout << "\n\n_!_:The passwords filds doesn't match. Press ENTER to Try Again\n";
        getchar();
        clear();

        goto A;
    }
    else
    cout << "You has been registered.\nPress Enter to Continue to the Login Page... ";
   
    ofstream ofile;
    ofile.open("data.txt", ios::app | ios::out);
    ofile << user << '\n';
    ofile << password << '\n';

    getchar();
    clear();

    fflush(stdin);
}
