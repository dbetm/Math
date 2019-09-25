function y = original( t )
    if(t <= 0.5) 
        y = -1;
    elseif(t > 0.5 & t <= 1)
         y = 1;
    elseif(t > 1 & t < 1.5)
         y = -1;
    else
         y = 1;
    end
        
end

