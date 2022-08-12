#include <fstream>
#include <bits/stdc++.h>
using namespace std;

//Variables:
char user[50];
char password[50];
//end of Variables

void readUser(){
    fgets(user, sizeof(user), stdin);
}

void readPassword(){
    fgets(password, sizeof(password), stdin);
}

bool checkLogin(){
    string userit;
    string passwordit;
    fstream file;
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
    return false;
}


