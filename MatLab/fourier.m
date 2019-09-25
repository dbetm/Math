function y = fourier( t, N ) % función para calcular la serie truncada de Fourier
    y = 0.0;
    for n=1:N
        %y = y + (((2*((-1)^n))-2) / (n*pi)) * sin(2*n*pi*t);
		%y = y + (4 / pi) * (1 / (2*n - 1)) * sin((2*n-1)*2*pi*t);
		y = y + ((2*(1-(-1)^n)) / (n*pi)) * sin(2*n*pi*t);
    end
end
% en consola poner:
% t = -0.5:0.01:0.5, y = fourier(t), plot(t, y), xlabel('t'), ylabel('f(t)'), title('n = ###');
% t es el intervalo en el cual queremos graficar

