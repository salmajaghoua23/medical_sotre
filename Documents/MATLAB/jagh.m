function [ z,r] = jagh (x,y) 
r = sqrt(x.^2 + y.^2); 
z = sin(r)./r; 
end 