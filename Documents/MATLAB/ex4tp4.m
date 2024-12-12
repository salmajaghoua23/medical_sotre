for k=1:8
    a(k,k)=-5;
    for j=k+1:8;
        a(k,j)=7;
    end
end
disp(a)
