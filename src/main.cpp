#include <iostream>
#include "../include/kern.hpp"

using namespace std;

bool file_exists(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}

int main(int argc, char * argv[]) {
    vector<string> fileList;

    string usage = "BiB: usage: bib [options] infile ...";

    for ( int i = 1; i < argc; i++ ) {
        if ( file_exists(argv[i]) ) {
            fileList.push_back(argv[i]);
        }
    }

    if ( fileList.size() == 0 ) {
        cout << "bib: \e[31merror:\e[0m No input files specified";
        return 1;
    }
    for ( int i = 0; i < fileList.size(); i++) {
        string filepath = fileList[i];
        Kern kern(filepath);

        cout << kern.analyze() << endl;
        // cout << kern.getContents() << endl;
    }
}