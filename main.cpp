#include "include/FIR.h"

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 20

using namespace std;

int main(int argv, char *argc[])
{
    // cout << "Start of main function\n";
    // cout << "Enter the number of points to generate in the signal: ";
    // cin >> n;

    // Generating noisy data to be filtered
    float input[n];
    float filteredInput[n];

    // Generate the input values
    const float pi = 3.14159265358979;
    const float f = 2.5; // Hz
    for (int i = 0; i < n; i++)
    {
        float min = 0.0f;
        float max = 0.3f;
        float noise = min + ((float)rand() / (float)RAND_MAX) * (max - min);
        input[i] = (float)sin(2 * pi * f * i / n) + noise; // one cycle t=i/n=0 to 1
    }

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

    cout << "\n\nDisplaying the generated noisy input:\n";
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    cout << "\n\nDisplaying the filtered output:\n";
    for (int i = 0; i < n; i++) {
        cout << filteredInput[i] << " ";
    }

    // Display a new line for better formatting
    cout << endl;

    FILE *gnuplot;
    char gnuPlotCommandString[500]="";
    char title[200]="";
    char xLabel[200]="";
    char yLabel[200]="";

    //Open the gnuplot for writing/plotting
    sprintf(gnuPlotCommandString, "gnuplot -persistent");
    
    //Set the plot title, xlabel and ylabel
    sprintf(title, "Original and filtered samples");
    sprintf(xLabel, "Time");
    sprintf(yLabel, "Amplitude");
    
    fprintf(gnuplot, "set title '%s'\n", title);
    fprintf(gnuplot, "set xlabel '%s'\n", xLabel);
    fprintf(gnuplot, "set ylabel '%s'\n", yLabel);

    //Plot the data
    fprintf(gnuplot,"plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\" ");
    for(int i=0;i<n;i++){
        fprintf(gnuplot,"%d %lf\n",i,input[i]);
    }
    fprintf(gnuplot,"e\n");
    for(int i=0;i<n;i++){
        fprintf(gnuplot,"%d %lf\n",i,filteredInput[i]);
    }

    //Close the GNU plot piping
    fflush(gnuplot);
    fclose(gnuplot);

    // Plotting with GNU Plot
    // FILE *gnuplotCommands = fopen("commands.p", "w");
    // FILE *gnuplotData = fopen("data.tmp", "w");

    // char title[200] = "";
    // char xLabel[200] = "";
    // char yLabel[200] = "";

    // // Set the plot title, xlabel and ylabel
    // sprintf(title, "Original and filtered samples");
    // sprintf(xLabel, "Time");
    // sprintf(yLabel, "Amplitude");

    // fprintf(gnuplotCommands, "plot \'data.tmp\' title \'Data\'\n");
    // fprintf(gnuplotCommands, "set terminal wxt size 500, 400\n");
    // fprintf(gnuplotCommands, "set title '%s'\n", title);
    // fprintf(gnuplotCommands, "set xlabel '%s'\n", xLabel);
    // fprintf(gnuplotCommands, "set ylabel '%s'\n", yLabel);

    // fprintf(gnuplotCommands, "plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\"\n");

    // fprintf(gnuplotData, "Raw Input, Filtered Output\n");
    // for (int i = 0; i < n; i++)
    // {
    //     fprintf(gnuplotData, "%lf, %lf\n", input[i], filteredInput[i]);
    // }
    
    // // Close the GNU plot piping
    // fclose(gnuplotCommands);
    // fclose(gnuplotData);

    // FILE *plotData = NULL, *plotPipeline = NULL, *plotCommands = NULL;
    
    // vector<string> plotCommands;

    // plotCommands.push_back("plot \'data.tmp\' title \'Data\'\n");
    // plotCommands.push_back("set terminal wxt size 500, 400\n");
    // plotCommands.push_back("set title 'Original and filtered samples'\n");
    // plotCommands.push_back("set xlabel 'Time'\n");
    // plotCommands.push_back("set ylabel 'Amplitude'\n");

    // plotCommands = fopen("commands.txt", "w");

    // fprintf(plotCommands, "plot \'data.tmp\' title \'Data\'\n");
    // fprintf(plotCommands, "set terminal wxt size 500, 400\n");
    // fprintf(plotCommands, "set title 'Original and filtered samples'\n");
    // fprintf(plotCommands, "set xlabel 'Time'\n");
    // fprintf(plotCommands, "set ylabel 'Amplitude'\n");

    // string data;

    // if(plotCommands.isopen()){
    //     string data;
    //     while(getline(plotCommands,data)){
    //         cout << data << "\n";
    //     }
    //     plotCommands.close();
    // }

    // fclose(plotCommands);

    // for (int i = 0; i < plotCommands.size(); ++i) {
    //     cout << plotCommands[i];
    // }

    // plotData = fopen("data.tmp", "w");
    // plotPipeline = _popen("gnuplot -persistent", "w");

    // for (int i = 0; i < n; ++i) {
    //     fprintf(plotData, "%lf %lf\n", input[i], filteredInput[i]);
    // }


    // for (int i = 0; i < plotCommands.size(); ++i) {
    //     fprintf(plotPipeline, "%s\n", plotCommands[i]);
    // }

    // cout << "End of main function\n\n";
    return 0;
}