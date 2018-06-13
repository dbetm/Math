import java.util.ArrayList;

public class BitReversal {
    private int N,P;
    private int[] orden; //guardar las posiciones
    

    public BitReversal(int N, int P) {
        this.N = N;
        this.P = P;
        orden = new int[N];
    }
    
    public int[] obtenerOrden() {
        for(int i = 0; i < N; i++) {
            orden[i] = convertirEntero(reversar(convertirBinario(i)));
        }
        return orden;
    }
    
    private String convertirBinario(int n) {
        String binario = "";
        for(int j = P - 1; j >= 0; j--) {
            binario += Integer.toString((n >> j) & 1);
        }
        return binario;
    }
    
    private String reversar(String bin) {
        String rev = "";
        for (int i = bin.length() - 1; i >= 0; i--) {
            rev += bin.charAt(i);
        }
        return rev;
    }
    
    private int convertirEntero(String bin) {
        int num = 0;
        int j = 0;
        for (int i = bin.length() - 1; i >= 0 ; i--) {
            num += Integer.parseInt(String.valueOf(bin.charAt(i))) * Math.pow(2, j);
            j++;
        }
        return num;
    }
    
    public void imprimirOrden() {
        for (int i = 0; i < N; i++) {
            System.out.println(orden[i]);
        }
    }
    
    public static void main(String []args) {
        BitReversal bt = new BitReversal(8, 3);
        bt.obtenerOrden();
        bt.imprimirOrden();
    }
}
