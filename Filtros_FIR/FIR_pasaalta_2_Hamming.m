% Uso de ventana tipo Hamming, filtro pasa-altas
Fs = 20000; % Frecuencia de muestreo
Fc = 5500; % Frecuencia de corte
Fcn = Fc / Fs; % Frecuencia de corte normalizada
A = 1.2; % Ganancia del filtro
N = 13; % Orden del filtro
n = 0:1:N-1; % Vector de coeficientes de n
D = (N-1)/2; % Cálculo del desplazamiento
h0 = 2*A*(0.5 - Fcn); % Cálculo del coeficiente h(0) = g(6)
gn = [];
% Ciclo para evaluar cada coeficiente en términos de n y el desplazamiento
% en D
for i=1:1:N
    gn(i) = ((-A/(pi*(n(i)-D)))*sin(2*pi*Fcn*(n(i)-D)))*(0.54-0.46*cos((2*pi*n(i))/(N-1)));
end
gn(7) = h0; % inclusión del coeficiente h(0)
figure, stem(gn), grid, xlabel('Muestras (n)'), ylabel('Magnitud')
% Y graficando la respuesta en frecuencia
[He, Fe] = freqz(gn, 1, 100000, Fs);
Magn = abs(He);
figure, semilogx(Fe, 20*log10(Magn)), grid, xlabel('Frecuencia en Hz'), ylabel('Ganancia en dB');