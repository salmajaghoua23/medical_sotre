set title 'Stocks des médicaments'
set xlabel 'Médicament'
set ylabel 'Stock'
set grid
set style data histograms
set style fill solid
plot 'stocks.dat' using 2:xtic(1) title 'Stock'
