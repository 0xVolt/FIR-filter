plot 'data.dat' title 'Data'
set terminal wxt size 500, 400
set title 'Original and filtered samples'
set xlabel 'Time'
set ylabel 'Amplitude'
plot '-' w lines lc rgb 'blue' title "sampled data", '-' w lines lc rgb 'red' title "Filtered data"
