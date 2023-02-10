#include "include/FIR.h"
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<float> loadSignal();
int getSignalSize(vector<float>);
bool generateCommandsScript(vector<float>, int);

int main(int argv, char *argc[]) {
    vector<float> signal = loadSignal();
    int length = getSignalSize(signal);

    bool generated = generateCommandsScript(signal, length);

    if (generated) {
        cout << "GNU plot commands script generated!";
    } else {
        cout << "Failed to generated commands script file!";
    }

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

bool generateCommandsScript(vector<float> signal, int length) {
    // vector<float> filteredOutput(length);

    // // FIR filter with circular buffer
    // // Declaring the filter struct variable
    // FIRFilter fir;

    // // Initialise the filter coefficient (the weight)
    // FIRFilter_init(&fir);

    // // Calculating the filtered values
    // for (int i = 0; i < length; i++) {
    //     FIRFilter_calc(&fir, signal[i]);
    //     filteredOutput[i] = fir.out;
    // }

    // // Plotting with GNU Plot
    // FILE *gnuplot = fopen("commands.p", "w");

    // char title[200] = "";
    // char xLabel[200] = "";
    // char yLabel[200] = "";

    // // Set the plot title, xlabel and ylabel
    // sprintf(title, "Original and filtered samples");
    // sprintf(xLabel, "Time");
    // sprintf(yLabel, "Amplitude");

    // fprintf(gnuplot, "set terminal wxt size 500, 400\n");
    // fprintf(gnuplot, "set title '%s'\n", title);
    // fprintf(gnuplot, "set xlabel '%s'\n", xLabel);
    // fprintf(gnuplot, "set ylabel '%s'\n", yLabel);

    // // Plot the data
    // fprintf(gnuplot, "plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\"\n");
    // for (int i = 0; i < length; i++) {
    //     fprintf(gnuplot, "%d %f\n", i, signal[i]);
    // }

    // fclose(gnuplot);

    fstream file;
    file.open("commands.p", ios_base::out);

    for(int i = 0; i < length; i++)
    {
        file << signal[i] << endl;
    }

    file.close();

    // fprintf(gnuplot, "e\n");

    // for (int i = 0; i < length; i++) {
    //     fprintf(gnuplot, "%d %f\n", i, filteredOutput[i]);
    // }

    // fprintf(gnuplot, "e\n");
    // fprintf(gnuplot, "replot\n");

    // Close the GNU plot piping
    // fclose(gnuplot);

    // if (filesystem::exists("commands.p")) {
    //     // char title[200] = "";
    //     // char xLabel[200] = "";
    //     // char yLabel[200] = "";

    //     // // Set the plot title, xlabel and ylabel
    //     // sprintf(title, "Original and filtered samples");
    //     // sprintf(xLabel, "Time");
    //     // sprintf(yLabel, "Amplitude");

    //     // fprintf(gnuplot, "set terminal wxt size 500, 400\n");
    //     // fprintf(gnuplot, "set title '%s'\n", title);
    //     // fprintf(gnuplot, "set xlabel '%s'\n", xLabel);
    //     // fprintf(gnuplot, "set ylabel '%s'\n", yLabel);

    //     // // Plot the data
    //     // fprintf(gnuplot, "plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\"\n");
    //     // for (int i = 0; i < length; i++) {
    //     //     fprintf(gnuplot, "%d %f\n", i, signal[i]);
    //     // }

    //     // fprintf(gnuplot, "e\n");

    //     // for (int i = 0; i < length; i++) {
    //     //     fprintf(gnuplot, "%d %f\n", i, filteredOutput[i]);
    //     // }

    //     // fprintf(gnuplot, "e\n");
    //     // fprintf(gnuplot, "replot\n");

    //     // // Close the GNU plot piping
    //     // fclose(gnuplot);

    //     return true;
    // } else {
    //     return false;
    // }
}