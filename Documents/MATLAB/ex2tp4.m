%qst 1
figure(1);
x=-pi:pi/100 :pi;
y=sin(x);
plot(x,y)
%qst 2
figure(2);
x=-pi:pi/5 :pi;
f=cos(x);
plot(x,f)
%qst 3
figure(3);
x=-pi:pi :pi;
g=cos(x)+1;
plot(x,g)
%qst 4
x=-2:0.2:2;
y=-2:0.2:2;
[X,Y]=meshgrid(x,y);
Z=X.*exp(-X.^(2) -Y.^(2));
mesh(X,Y,Z)
%qst 5
x=-pi:pi/5 :pi;
y=-pi:pi/5 :pi;
[X,Y]=meshgrid(x,y);
Z=Y.^(3)*cos(2*X.^(2) -1);
mesh(X,Y,Z)