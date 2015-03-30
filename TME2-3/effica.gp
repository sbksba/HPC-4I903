#!/usr/bin/gnuplot
reset
set terminal png
set output "effica.png"
set boxwidth 0.75 absolute
set xtic auto # set xtics automatically
set ytic auto # set ytics automatically
set xlabel "nbProc"
set ylabel "Efficacite (%)"
set label "Yield Point" at 0.003,260
set arrow from 0.0028,250 to 0.003,280
set grid
set xr [2:10]
set yr [0.00:101.00]
plot "effic.dat" using 1:2 title 'Sequentiel' with linespoints, \
     "effic.dat" using 1:3 title 'Vanilla' with linespoints, \
     "effic.dat" using 1:4 title 'Slave' with linespoints
