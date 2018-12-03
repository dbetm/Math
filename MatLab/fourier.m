function y = fourier( t )
    y = 0.0;
    for n=1:10
        y = y + (((2*((-1)^n))-2) / (n*pi)) * sin(2*n*pi*t);
    end
end
% en consola poner:
% t = -0.5:0.01:0.5, y = fourier(t), plot(t, y), xlabel('t'), ylabel('f(t)'), title('n = 300');

