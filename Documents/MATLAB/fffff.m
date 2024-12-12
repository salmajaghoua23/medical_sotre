
function [ z,r] = fffff(x,y) 
r = sqrt(x.^2 + y.^2); 
z = sin(r)./r; 
end