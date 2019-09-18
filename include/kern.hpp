#include <string>
#include <vector>

using namespace std;
    
class Kern {

    string title;
    string file_path;
    string contents;

public:
    
    Kern(string path);

    void meta();
};