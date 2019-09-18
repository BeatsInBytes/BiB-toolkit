#include <iostream>
#include "../include/kern.hpp"

using namespace std;

void Kern::meta() {
    cout << "meta function";
}

Kern::Kern(string path) {
    // file_path = path;
    cout << path << endl;
}