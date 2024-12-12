%x=-2:0.2:2;
%y=-2:0.2:2;
%[X,Y]=meshgrid(x,y)
%Z=X.*exp(-X.^(2)-Y.^(2))
%mesh(X,Y,Z)
%xlabel('x')
%ylabel('y')
%title('representation')
%x=-pi:pi/5:pi;
%y=-pi:pi/5:pi;
%[X,Y]=meshgrid(x,y);
%Z=Y.^(3).*cos(2*X.^(2) -1);
%surf(X,Y,Z)
%xlabel('x')
%ylabel('y')
%zlabel('z')
%title('f(x,y)')
x=-pi:pi/5:-pi;
f=cos(x)
g=sin(x.^(2))
t=log(x+2*pi)
plot(x,f,'m:','Linewidth',2)
hold on
plot(x,g,'g*','Linewidth',2)
plot(x,g,'k<','Linewidth',2)
