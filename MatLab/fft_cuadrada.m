% Calculando la FFT de una onda cuadrada
Fs = 150; % Frecuencia de muestreo (Hz)
t = 0:1/Fs:1; % Vector tiempo de 1 segundo
f = 50; % Frecuencia de la onda senoidal
x = square(2*pi*t*f); % Onda cuadrada
nfft = 1024; % El número de puntos de la fft
% Tomar la FFT, y llenando con ceros, 
% de manera que el largo de la FFT sea nfft 
Y = fft(x, nfft);
Y = Y(1:nfft/2); % La FFT es simétrica
my = abs(Y).^2; % tomar la potencia espectral, módulo al cuadrado de la FFT
f = (0:nfft/2-1)*Fs/nfft; % construcción del vector de frecuencia

% generar los plots, títulos y nombres
figure(1);
plot(t, x);
title('Señal');
xlabel('Tiempo(s)');
ylabel('Amplitud');
figure(2);
plot(f, my);
title('Espectro de potencia');
xlabel('Frecuencia(Hz)');
ylabel('Potencia');
