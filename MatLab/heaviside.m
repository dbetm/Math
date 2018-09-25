function y = heaviside( t )
    y = 0 * t;
    y(t >= 0) = 1;
end

