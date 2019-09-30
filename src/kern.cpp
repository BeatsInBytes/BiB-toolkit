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

void replace(string str, string from, string to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

// Kern functions:
string numList(string song) {

    string numlist, remove;
    remove = grep(grep(grep(song, "!", 'v'), "*", 'v'), "=", 'v');
    stringstream f(remove);
    string line;    
    while (getline(f, line)) {
        line = string(line);
        string newline;
        // cout << line << endl;
        // cout << line.length() << endl;
        for ( int i = 0; i < line.length(); i++ ) {
            char character = line[i];
            if (isdigit(character)) {
                newline += character;
            }
            else if ( character == '\t' ) {
                newline += "\t";
            }
            else if ( character == ' ' ) {
                newline += " ";
            }
        }
        if ( newline != "" ) {
            numlist += newline + "\n";
        }
    }

    return numlist;
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
    vector<int> themes;
    return themes;
}

string Kern::keySig() {
    string found = grep(contents, "*k[", 'n');

    if ( found == "" ) {
        // try key interpretations
    }
    else {
        replace(found, " ", "t");
    }
    return found;
}

vector<int> Kern::scales() {
    vector<int> scales;
    return scales;
}        

map<int,float> Kern::pitchDist() {
    map<int,float> pitchDist;
    return pitchDist;
}

map<int, float> Kern::rhythmDist() {
    map<int,float> rhythmDist;
    return rhythmDist;
}

int Kern::trackNum() {
    int trackNum;
    return trackNum;
}

string Kern::analyze() {
    // perform full analysis
    string returnstr;
    cout << numList(contents);
    //meta:
    // map<string, string> meta = Kern::meta();

    // returnstr += "Composer:\t" + meta["composer"] + "\n";    
    // returnstr += "Key signature:\t" + keySig();

    //finished
    return returnstr;
}