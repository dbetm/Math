% Uso de ventana tipo Hamming, filtro pasa-banda
Fs = 20000; % Frecuencia de muestreo
Fc1 = 3000; % Frecuencia de corte inferior
Fc2 = 9000; % Frecuencia de corte superior
Fc1n = Fc1 / Fs; % Frecuencia de corte inferior normalizada
Fc2n = Fc2 / Fs; % Frecuencia de corte superior normalizada
A = 2; % Ganancia del filtro
N = 15; % Orden del filtro
n = 0:1:N-1; % Vector de coeficientes de n
D = (N-1)/2; % Cálculo del desplazamiento
h0 = 2 * A * (Fc2n - Fc1n); % Cálculo del coeficiente h(0) = g(7)
gn = []; % Vector vacío
% Ciclo para evaluar cada coeficiente en términos de n y el desplazamiento
% en D
for i=1:1:N
    gn(i) = ((A/(pi*(n(i)-D)))*(sin(2*pi*Fc2n*(n(i)-D))-sin(2*pi*Fc1n*(n(i)-D))))*(0.54-0.46*cos((2*pi*n(i))/(N-1)));
end
gn(8) = h0; % Inclusión del coeficiente h(0)
% Graficando la respuesta al impulso
figure, stem(gn), grid, xlabel('Muestras (n)'), ylabel('Magnitud');
% Graficando la respuesta en frecuencia
[He, Fe] = freqz(gn, 1, 100000, Fs);
Magn = abs(He);
figure, semilogx(Fe, 20*log10(Magn)), grid, xlabel('Frecuencia en Hz'), ylabel('Ganancia en dB');
