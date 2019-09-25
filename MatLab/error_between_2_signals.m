clear
T = 1; % Periodo
t = 0:0.001:2; % vector de tiempo (2 unidades)
Fs = length(t)/2; % Frecuencia de muestro
original = square(2*pi*t);
plot(t, original);
hold on;
N = 100; % Número de términos de la serie de Fourier
truncada = fourier(t, N);
plot(t, truncada);
hold on;
suma = sum(abs(original - truncada).^2);
resultado = (1 / T*Fs) * suma
title(['N = ', num2str(N), ', Error de energía = ',num2str(resultado)]);
ylim([-1.3 1.3]);


