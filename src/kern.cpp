#include <iostream>
#include "../include/kern.hpp"
#include <fstream>
#include <sstream>

using namespace std;

Kern::Kern(string path) {
    file_path = path;
    ifstream t(file_path);
    stringstream buffer;
    buffer << t.rdbuf();
    contents = buffer.str();
}

map<string, string> Kern::meta() {
}

string Kern::getContents() {
    return contents;
}

vector<int> themes() {

}

vector<int> scales() {

}        

map<int,float> pitchDist() {

}

map<int, float> rhythmDist() {

}