#include <iostream>
#include "../include/kern.hpp"
#include <fstream>
#include <sstream>

using namespace std;

// GENERAL TEXT PROCESSING:
//========================

string grep(string content, string key, char type) {
    stringstream f(content);
    string line;
    string returnStr;
    while (getline(f, line)) {
        if ( type == 'v' ) {
            if (line.find(key) == string::npos) {
                returnStr+=line + "\n";
            }
        }
        else if ( type == 'n' ) {
            if (line.find(key) != string::npos) {
                returnStr+=line + "\n";
            }
        }
    }
    return returnStr;
}

// KERN METHODS:
//========================
Kern::Kern(string path) {
    file_path = path;
    ifstream t(file_path);
    stringstream buffer;
    buffer << t.rdbuf();
    contents = buffer.str();
}

map<string, string> Kern::meta() {
    map<string, string> meta;

    string metaText = grep(contents, "!!!", 'n');

    if ( metaText == "" ) {
        cout << "No meta information available";
        //throw error
    }
    else {
        string lastName, firstName, composerName, composer;

        composer = grep(metaText, "COM:", 'n');
        composer = composer.substr(8,composer.size());
        
        lastName = composer.substr(0, composer.find(","));
        firstName = composer.erase(0, composer.find(",") + 2);
        composerName = firstName.substr(0,firstName.size() - 1) + " " + lastName;

        meta.insert({"composer", composerName});
    }
    
    
    return meta;
}

string Kern::getContents() {
    return contents;
}

vector<int> Kern::themes() {

}

vector<int> Kern::scales() {

}        

map<int,float> Kern::pitchDist() {

}

map<int, float> Kern::rhythmDist() {

}

int Kern::tracknum() {

}