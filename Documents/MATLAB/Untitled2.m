%n=input('valeur de n: ');
%fact=1;
for i=1 :n
    fact=fact*i;
end
disp([num2str(n) '!=' num2str(fact)])