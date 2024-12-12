x=1:0.01:10;
y=1:0.01:10;
[X,Y]=meshgrid(x,y);
Z=log(sqrt(X))+cos(Y);
C=contourf(X,Y,Z)
clabel(C,'manual')
view(90,25)