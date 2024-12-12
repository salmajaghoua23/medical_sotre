disp('ce programme consiste a trouver le premier nombre divisible par (9)');

for i=13:97;
    if mod(i,9)==0
        disp(['le premier nombre divisible par 9 est' num2str(i)]);
    break;
     
    end
  
end