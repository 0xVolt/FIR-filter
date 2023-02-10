#include "include/FIR.h"
#include <sstream>
#include <string>
using namespace std;

int countLines();

int main(int argv, char *argc[]) {
    // fstream source;
    // source.open("data/signal.txt", ios_base::in);

    // for(string line; getline(source, line);) {
    //     float index, value;
    //     istringstream readInput(line);

    //     readInput >> index >> value;

    //     cout << index << ": " << value << endl;                //and read the first whitespace-separated token
    // }

    int length = countLines();
    cout << length;

    return 0;

    // cout << "Start of main function\n";
    // int n = 1000;

    // Generating noisy data to be filtered
    // float input[n];
    // float filteredInput[n];

    /*
    // FIR filter with circular buffer
    // Declaring the filter struct variable
    FIRFilter fir;

    // Initialise the filter coefficient (the weight)
    FIRFilter_init(&fir);

    // Calculating the filtered values
    for (int i = 0; i < n; i++)
    {
        FIRFilter_calc(&fir, input[i]);
        filteredInput[i] = fir.out;
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
    for (int i = 0; i < n; i++)
    {
        fprintf(gnuplot, "%d %lf\n", i, input[i]);
    }
    fprintf(gnuplot, "e\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(gnuplot, "%d %lf\n", i, filteredInput[i]);
    }
    fprintf(gnuplot, "e\n");
    fprintf(gnuplot, "replot\n");

    // Close the GNU plot piping
    fclose(gnuplot);

    cout << "Generated commands.p file!\n";

    */
}

int countLines() {
    string line;   // To read each line from code
    int count = 0;    // Variable to keep count of each line
    fstream file;
    file.open("/home/volt/code/filter-coffee/data/signal.txt", ios::in);  

    if(file.is_open()) {
        while(file.peek() != EOF) {
            getline(file, line);
            count++;
        }
        file.close();
        
        return count;
    } else {
        cout << "Couldn't open the file\n";
        
        return -1;
    }
}