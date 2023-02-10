#include "include/FIR.h"
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<float> loadSignal();
int getSignalSize(vector<float>);

int main(int argv, char *argc[]) {
    vector<float> signal = loadSignal();

    // cout << getSignalSize(signal);

    return 0;
}

int getSignalSize(vector<float> signal) {
    int length = 0;

    for (float element: signal)
        length++;
    
    return length;
} 

vector<float> loadSignal() {
    vector<float> signal;

    fstream file;
    file.open("/home/volt/code/filter-coffee/data/signal.txt", ios_base::in);

    for(string line; getline(file, line);) {
        float value;
        istringstream readInput(line);

        readInput >> value;

        signal.push_back(value);
    }

    return signal;
} 