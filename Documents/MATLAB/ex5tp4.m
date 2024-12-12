
xpas=0.01;
x(1)=0;
y(1)=7*(1-exp(-x(1)/3));
k=1;
while y(k)<=4
    x(k+1)=x(k)+xpas;
    y(k+1)=7*(1-exp(-x(k+1)/3));
    
    k=k+1;
end
xmax=x(k-1);
ymax=y(k-1);
xmax=x(k)
ymax=y(k)
plot(x,y,'r')
