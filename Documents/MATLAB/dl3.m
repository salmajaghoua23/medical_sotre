 U=0;
 i=1;
while abs(U-exp(1))>=10^(-2)

    U=(1+1/i)^i;
   if abs(U-exp(1))>=10^(-2)
       i=i+1;
   end
       
    
end
disp(i-1)