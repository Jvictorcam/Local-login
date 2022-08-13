#include <bits/stdc++.h>
#include "login.hpp"

using namespace std;

int main(int argc, char** argv){
    
    int act = Welcome();
    bool auth; // save if credentials are valid or not
    if(act == 1){
       auth = Login(); // Check the credentials and return if its correct or not
    }

    if(act == 2){
        Register();
        auth = Login();
    }

    if(!auth){
        cout << "Access Denied" << endl;
    }

    return 0;
}