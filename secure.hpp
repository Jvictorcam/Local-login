#include <bits/stdc++.h>
using namespace std;

int key = 2004; // key of encrypt()
char c;

void encrypt(){
    fstream fin, fout;    
    
    // Open input file
    // ios::binary- reading file
    // character by character
    fin.open("data.txt", ios::in || ios::out);
    fout.open("encrypt.txt", ios::out || ios::in);
 
    // Reading original file till
    // end of file
    while (fin >> noskipws >> c) {
        int temp = (c + key);
 
        // Write temp as char in
        // output file
        fout << (char)temp;
    }
    while (fout >> noskipws >> c) {
    {
        fin << c;
    }
    
    // Closing both files
    fin.close();
    fout.close();

}

void decrypt(){
    fstream fin;
    fstream fout;
    fin.open("data.txt", fstream::in);
    fout.open("data.txt", fstream::out);
 
    while (fin >> noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
}