#include <string>
#include <vector>
#include <map>

using namespace std;
    
class Kern {

    string title;
    string file_path;
    string contents;

    public:
        
        Kern(string path);

        // Data fetch methods
        string getContents();

        // aata add methods
        map<string, string> meta();
        vector<int> themes(), scales();
        map<int, float> pitchDist(), rhythmDist();

};