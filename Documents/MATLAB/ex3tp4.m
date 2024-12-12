% T=0:0.01:3;
% A1=1;
% A2=3;
% F1=2;
% F2=4;
% Y1=signal(A1,F1);
% Y2=signal(A1,F2)
% Y3=signal(A2,F1)
% Y4=signal(A2,F2);
% figure;
% subplot(2,2,1)
% plot(t,Y1,'r:')
% grid on

subplot(2,2,2)
plot(t,Y2,'r:')
grid on

subplot(2,2,3)
plot(t,Y3,'r:')
grid on
plot('signal')
subplot(2,2,4)
plot(t,Y4,'r:')
grid on
