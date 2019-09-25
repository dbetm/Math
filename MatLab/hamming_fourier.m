clear
t = 0:0.001:2; % Vector de tiempo
N = 300; % Cantidad de términos de la serie de Fourier
y = fourier(t, N);
%figure(1);
%plot(t, y); % graficar la serie de Fourier
%title('n = 300')
h=1;% Contador auxiliar para la ventana Hamming
for i=(N/2):N-1
    % Definición de la ventana para cada n (mitad descendente)
    ventana(h)= 0.54-(0.46*cos((2*pi*i) / (N-1)));
    %ventana(h)=0.54+0.46*cos((2*i*pi)/(N-1));
    % Multiplicar cada punto de la ventana por suma truncada de Fourier (coeficientes Ck)
    parcial(h,:) = ventana(h).*fourier(t, i);
    %disp(parcial(h, :));
    h=h+1; % Incrementar contador
end
for j=1:length(t) % Suma de todas las columnas de “parcial”
    sin_batman(j)=sum(parcial(:,j));% Señal filtrada aplicándole la ventana Hamming
    %disp(sin_batman(j));
end
figure(2);
plot(t, sin_batman); % se grafica el resultado del filtrado
title('Resultado del filtrado')
