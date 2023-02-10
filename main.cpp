#include "include/FIR.h"
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<float> loadSignal();
void display(vector<float>);
int getSignalSize(vector<float>);
void generateCommandsScript(vector<float>);

int main(int argv, char *argc[]) {
    vector<float> signal = loadSignal();

    generateCommandsScript(signal);

    return 0;
}

void display(vector<float> signal) {
    cout << "Displaying signal in float values:\n";
    for (auto element: signal) {
        cout << element << endl;
    }
}

vector<float> loadSignal() {
    vector<float> signal;

    fstream file;
    file.open("/home/volt/code/filter-coffee/data/generated/signal.txt", ios_base::in);

    for (string line; getline(file, line);) {
        float value;
        istringstream readInput(line);

        readInput >> value;

        signal.push_back(value);
    }

    return signal;
}

void generateCommandsScript(vector<float> signal) {
    // fstream file;
    // file.open("commands.p", ios_base::out);

    // for (int i = 0; i < signal.size(); i++) {
    //     file << signal[i] << endl;
    // }

    // file.close();

    // return true;

    // int length = signal.size();
    int start = 30000;
    int end = start + 50000;

    vector<float> filteredOutput(end - start);

    // FIR filter with circular buffer
    // Declaring the filter struct variable
    FIRFilter fir;

    // Initialise the filter coefficient (the weight)
    FIRFilter_init(&fir);

    // Calculating the filtered values
    for (int i = start; i < end; i++) {
        FIRFilter_calc(&fir, signal[i]);
        filteredOutput[i] = fir.out;
    }

    // Plotting with GNU Plot
    FILE *gnuplot = fopen("commands.p", "w");

    char title[200] = "";
    char xLabel[200] = "";
    char yLabel[200] = "";

    // Set the plot title, xlabel and ylabel
    sprintf(title, "Original and filtered samples");
    sprintf(xLabel, "Time");
    sprintf(yLabel, "Amplitude");

    fprintf(gnuplot, "set terminal wxt size 500, 400\n");
    fprintf(gnuplot, "set title '%s'\n", title);
    fprintf(gnuplot, "set xlabel '%s'\n", xLabel);
    fprintf(gnuplot, "set ylabel '%s'\n", yLabel);

    // Plot the data
    fprintf(gnuplot, "plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\"\n");
    for (int i = start; i < end; i++) {
        fprintf(gnuplot, "%d %f\n", i, signal[i]);
    }

    fprintf(gnuplot, "e\n");

    for (int i = start; i < end; i++) {
        fprintf(gnuplot, "%d %f\n", i, filteredOutput[i]);
    }

    fprintf(gnuplot, "e\n");
    fprintf(gnuplot, "replot\n");

    // Close the GNU plot piping
    fclose(gnuplot);
}