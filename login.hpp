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
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void readUser(){
    fflush(stdout);
    fgets(user, sizeof(user), stdin);
    size_t lenu = strlen(user) - 1;
    if(user[lenu] == '\n') user[lenu] = '\0';
}

void readPassword(){
    fflush(stdout);
    fgets(password, sizeof(password), stdin);
    size_t lenp = strlen(password) - 1;
    if(password[lenp] == '\n') password[lenp] = '\0';
}

int Welcome(){
    clear();
    int aux;
    cout << "Welcome to Project Carot!";
    cout << "Select the service you want: "
         << "\n-\n"
         << "(1): Login\n"
         << "(2): Register\n"
         << "(3): Exit\n"
         << "(4): About Us\n"
         << '-' << '\n'
         << "-> ";
    cin >> aux; // say what the user want to do
    
    fflush(stdout); // SAFETY
    fflush(stdin);  // JUST FOR SAFE!!!! HATE GARBAGE, ITS 1AM AND IM CODING THIS
    cin.ignore();   // SAFETY

    return aux;
}

bool Login(){
   int attempt = 3;
   B: 
    cout << "Sign-In Space\n-\n-\n-\n-\n" 
         << "User: ";
    readUser();
    cout << "Password: ";
    readPassword(); 
    
   
    
    

    string userit;
    string passwordit;
    fstream file;
    file.open("data.txt", ios::app);
    file.close();
    file.open("data.txt", ios::in);
    
    if(!file.is_open()){        // If the file cant be open or created, then
        cerr << "An Data Error Ocurred, Sorry\n";   // print "An Data Error Ocurred, Sorry" and
        return -1;              // return -1
    }

    while(!file.eof()){
        
        //fgets(userit, sizeof(userit), file);
        //fgets(passwordit, sizeof(passwordit), file);
        getline(file, userit);
        getline(file, passwordit);
        if(userit == user && passwordit == password){
            clear();
            cout << "Logged Successfully!!\nWelcome to Carot >" << user << "<\n\n\n\n";
            file.close();
            return true;
        }
    }
    file.close();
    attempt--;
    cout << "Authentication Failed\n_!_" << attempt << "Attempts Left _!_\nPress ENTER to continue... ";
    getchar();
    clear();
    
    if(attempt != 0) goto B;

    return false;
}

void Register(){
    
    cout << "Choose your Username: ";
    readUser();

    A:
    cout << "Set a Password: ";
    readPassword();
    fflush(stdout);
    cout << "Re-Write the Password: ";

    fgets(repss, sizeof(repss), stdin);
    size_t lenp2 = strlen(repss) - 1;
    if(repss[lenp2] == '\n') repss[lenp2] = '\0';
 

    if(string(repss) != string(password)){
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

    fflush(stdout);
}
