%  ezsurf('jagh') 
% %ezmesh('jagh',60) 
% shading interp 
%nbre premier entre 2 et 999
clear;
clc;
close all;
for i=2:999
    nbr_div=0;
    for j=2:i/2
        if mod(i,j)==0
            nbr_div=nbr_div+1;
        end
    end
    if nbr_div==0
        disp(i)
    end
end