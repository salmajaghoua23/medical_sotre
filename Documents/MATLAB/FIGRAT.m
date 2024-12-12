x=linspace(1,20,50);
y=linspace(1,20,50);
[X,Y]=meshgrid(x,y);
Z=sin(pi.*X).*log(Y);
mesh(X,Y,Z)
colorbar
xlable('x')
