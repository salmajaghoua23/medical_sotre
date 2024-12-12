function A = initialiser( n ,num)
if num==1
    A=zeros(n);
end 
if num==2;
    A=ones(n);
end
if num==3;
    A=eye(n);
end
if num==4;
    A=5*eye(n);
end
end

