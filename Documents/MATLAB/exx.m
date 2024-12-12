x=linspace(0, 6)
y=linspace(0,3)
f=cos(x);
g=exp(y/2);
figure;
subplot(1,2,1)
plot(x,f,'b-','LineWidth',3)
xlabel('x')
ylabel('y')
title('representation')
grid on
gtext('graphique of function')
subplot(1,2,2)
plot(y,g,'r:','LineWidth',3)
xlabel('x')
ylabel('y')
titre('fir1:exp(y/2)')
grid on