// Autor: David Betancourt Montellano
// Fecha: 12/06/2018

public class TRF_algoritmo {
    private int N; // número de muestras
    private int P; // 2^P = N, P = log_2(N)
    private int[] orden;
    private float[] amplitudMuestras; // tomadas en el dominio del tiempo
    private float[] amplitudFrecuencias;
    private Complejo[] frecuenciasIntermedias;

    public TRF_algoritmo(int N) {
        this.N = N;
        this.P = (int)(Math.log(N) / Math.log(2));
        BitReversal bt = new BitReversal(N, P);
        orden = bt.obtenerOrden();
        // Se inicializan los arreglos
        amplitudMuestras = new float[N];
        amplitudFrecuencias = new float[N];
        frecuenciasIntermedias = new Complejo[N];
    }

    public int getN() {
        return N;
    }

    public void setN(int N) {
        this.N = N;
        this.P = (int)(Math.log(N) / Math.log(2));
        BitReversal bt = new BitReversal(N, P);
        orden = bt.obtenerOrden();
        // Se inicializan los arreglos
        amplitudMuestras = new float[N];
        amplitudFrecuencias = new float[N];
        frecuenciasIntermedias = new Complejo[N];
    }

    public int getP() {
        return P;
    }

    public float[] getAmplitudMuestras() {
        return amplitudMuestras;
    }

    public void setAmplitudMuestras(float[] amplitudMuestras) {
        for(int i = 0; i < N; i++) {
            this.amplitudMuestras[orden[i]] = amplitudMuestras[i];
        }
//        for (int i = 0; i < N; i++) {
//            System.out.println(this.amplitudMuestras[i] + " ");
//        }
    }

    public float[] getAmplitudFrecuencias() {
        return amplitudFrecuencias;
    }

    public void calcularAmplitudFrecuencias() {
        for (int i = 0; i < P; i++) {
            frecuenciasIntermedias = calcularFrecuenciasIntermedias(i);
            System.out.println("");
            for (int j = 0; j < N; j++) {
                System.out.println(Operacion.mostrarNumero(frecuenciasIntermedias[j]));
            }
//            if(i == 0) break;
        }
        amplitudFrecuencias = calcularAmplitudesFrecuencias();
    }
    
    private Complejo[] calcularFrecuenciasIntermedias(int p) {
        Complejo[] C = new Complejo[N];
        int bloque = (int)Math.pow(2, p+1);
        int cont = 0;
        Complejo[] factoresGiro = calcularFactoresGiro(bloque);
        System.out.println("Núm factores: " + factoresGiro.length);
        if(p == 0) { //para la primera iteración, son 4 interaciones
            for (int i = 0; i < N; i++) {
                if(i % 2 == 0) {
                    Complejo A = new Complejo(amplitudMuestras[i], 0);
                    Complejo b = new Complejo(amplitudMuestras[i+1], 0);
                    Complejo B;
                    B = Operacion.multiplicar(factoresGiro[0], b);
                    C[i] = Operacion.sumar(A, B);
                }
                else {
                    Complejo A = new Complejo(amplitudMuestras[i-1], 0);
                    Complejo b = new Complejo(amplitudMuestras[i], 0);
                    Complejo B;
                    B = Operacion.multiplicar(factoresGiro[0], b);
                    C[i] = Operacion.restar(A, B);
                }
            }
        }
        else {
            int aux = 0, d = bloque/2;
            for (int i = 0; i < N; i++) {
                if(cont < d) { // para positivos (sumas)
                    if(aux < d) { // se suma d
                        //System.out.println("C["+i+"] = x_"+i+"+ "
                               // + "w_"+cont+"*X_"+(i+d));
                        Complejo A = frecuenciasIntermedias[i];
                        Complejo b = frecuenciasIntermedias[i+d];
                        Complejo B;
                        B = Operacion.multiplicar(factoresGiro[cont], b);
                        C[i] = Operacion.sumar(A, B);
                        System.out.println("Sumar d, #suma");
                    }
                    else  { // se resta d
                        Complejo A = frecuenciasIntermedias[i-d];
                        Complejo b = frecuenciasIntermedias[i];
                        Complejo B;
                        B = Operacion.multiplicar(factoresGiro[cont], b);
                        C[i] = Operacion.sumar(A, B);
                        System.out.println("Restar d, #suma");
                    }
                    if(aux == bloque-1) aux = 0;
                    else aux++;
                }
                else { // para negativos (restas)
                    if(aux < d/2) { // se suma d
                        System.out.println("Sumar d, #resta");
                        Complejo A = frecuenciasIntermedias[i];
                        Complejo b = frecuenciasIntermedias[i+d];
                        Complejo B;
                        B = Operacion.multiplicar(factoresGiro[cont-d], b);
                        C[i] = Operacion.restar(A, B);
                    }
                    else  { // se resta d
                         System.out.println("restar d, #resta");
                        Complejo A = frecuenciasIntermedias[i-d];
                        Complejo b = frecuenciasIntermedias[i];
                        Complejo B;
                        B = Operacion.multiplicar(factoresGiro[cont-d], b);
                        C[i] = Operacion.restar(A, B);
                    }
                    if(aux == bloque-1) aux = 0;
                    else aux++;
                }
                C[i].setParteReal(intelRound(C[i].getParteReal()));
                C[i].setParteImaginaria(intelRound(C[i].getParteImaginaria()));
                if(cont == bloque-1) {
                    cont = 0;
                    continue;
                }
                cont++;
            }
        }
        
        return C;
    }
    
    private Complejo[] calcularFactoresGiro(int m) {
        int n = m / 2;
        Complejo[] factores = new Complejo[n];
        for (int i = 0; i < n; i++) {
            factores[i] = calcularFactorGiro(m, i);
        }
        return factores;
    }
    
    private Complejo calcularFactorGiro(int m, int n) {
        float x = (float)Math.cos(Math.toRadians((float)(-2 * 180 * n) / m));
        float y = (float)Math.sin(Math.toRadians((float)(-2 * 180 * n) / m));
        x = intelRound(x);
        y = intelRound(y);
        Complejo complex = new Complejo(x, y);
        //System.out.println(Operacion.mostrarNumero(complex));
        return complex;
    }
    
    private static float intelRound(float n) {
        float nRounded = Math.round(n);
        if(Math.abs(nRounded - n) < 0.05) n = nRounded;
        // Si se redondean y queda un valor muy pequeño se representa con 0
        if(Math.abs(n) < 0.01) n = 0;
        return n;
    }
    
    private float[] calcularAmplitudesFrecuencias() {
        float[] amplitudes = new float[N];
        for (int i = 0; i < N; i++) {
            amplitudes[i] = (frecuenciasIntermedias[i].getModulo() / N) * 2;
        }
        return amplitudes;
    }
    
    public static void main(String []args) {
        TRF_algoritmo ttf = new TRF_algoritmo(8);
        float[] muestras = new float[8];
        muestras[0] = 5;
        muestras[1] = -2.1213f;
        muestras[2] = 2;
        muestras[3] = 4.9497f;
        muestras[4] = -5;
        muestras[5] = 2.1213f;
        muestras[6] = -2;
        muestras[7] = -4.9497f;
        
        float[] muestras2 = new float[4];
        muestras2[0] = 8;
        muestras2[1] = 4;
        muestras2[2] = 8;
        muestras2[3] = 0;
        
        ttf.setN(4);
        
        ttf.setAmplitudMuestras(muestras2);
        ttf.calcularAmplitudFrecuencias();
        float[] resultados = ttf.getAmplitudFrecuencias();
        for (int i = 0; i < resultados.length; i++) {
            System.out.println(resultados[i]);
        }
    }
}
