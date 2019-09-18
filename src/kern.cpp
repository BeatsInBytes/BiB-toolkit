#include <iostream>
#include "../include/kern.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void Kern::meta() {
    cout << "meta function";
}

Kern::Kern(string path) {
    file_path = path;

    ifstream t(file_path);
    stringstream buffer;
    buffer << t.rdbuf();
    cout << buffer.str() << endl;
}