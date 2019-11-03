#include <string>
#include <vector>
#include <map>

using namespace std;
    
class Kern {
    string file_path;
    string contents;

    string rhythm;
    string degree;
    int numTrack;


    public:
        
    Kern(string path);

    // fetching data
    string getContents();

    // analysis methods
    string keySig();
    map<string, string> meta();
    vector<int> themes(), scales();
    map<int, float> pitchDist(), rhythmDist();
    
    // kern processing
    int trackNum(string file);

    string analyze();

};