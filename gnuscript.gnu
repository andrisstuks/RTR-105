# Scale font and line width (dpi) by changing the size! It will always display stretched.
set terminal svg size 400,300 enhanced fname 'arial'  fsize 10 butt solid
set output 'out.svg'

# Key means label...
set key inside bottom right
set xlabel 'Deflection (m)'
set ylabel 'Force (kN)'
set title 'Some Data'
plot  "dati.txt" using 1:2 title 'Col-Force' with lines, "data.txt" using 1:3 title 'Beam-Force' with linespoints
