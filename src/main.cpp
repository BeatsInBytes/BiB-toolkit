#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/kern.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    string file = argv[1];

    ifstream t(file);
    stringstream buffer;
    buffer << t.rdbuf();
    cout << buffer.str() << endl;

    Kern kern(file);
    // for ( int i = 0; i < argc; i++) {
    //     cout << argv[i] << endl;
    // }
}