package operaciones;
/**
 *
 * @author david
 */
public class Calc {
    
    public static Complejo sumar(Complejo A, Complejo B) {
        float resReal, resImaginario;
        
        resReal = A.getParteReal() + B.getParteReal();
        resImaginario = A.getParteImaginaria() + B.getParteImaginaria();
        
        return new Complejo(resReal, resImaginario);
    }
    
    public static Complejo restar(Complejo A, Complejo B) {
        float resReal, resImaginario;
        
        resReal = A.getParteReal() - B.getParteReal();
        resImaginario = A.getParteImaginaria() - B.getParteImaginaria();
        
        return new Complejo(resReal, resImaginario);
    }
    
    public static Complejo multiplicar(Complejo A, Complejo B) {
        float resReal, resImaginario;
        
        // (x1x2 - y1y2)
        resReal = A.getParteReal() * B.getParteReal() - 
                (A.getParteImaginaria() * B.getParteImaginaria());
        // i(x1y2 + x2y1)
        resImaginario = (A.getParteReal() * B.getParteImaginaria()) + 
                (B.getParteReal() * A.getParteImaginaria());
        
        return new Complejo(resReal, resImaginario);
    }
    
    public static Complejo dividir(Complejo A, Complejo B) {
        float resReal, resImaginario, denominador;
        
        denominador = (float)Math.pow(B.getParteReal(), 2) + 
                (float)Math.pow(B.getParteImaginaria(), 2);
        
        resReal = (A.getParteReal() * B.getParteReal()) + 
                (A.getParteImaginaria() * B.getParteImaginaria());
        resReal /= denominador;
        
        resImaginario = (B.getParteReal() * A.getParteImaginaria()) - 
                (A.getParteReal() * B.getParteImaginaria());
        
        resImaginario /= denominador;
        
        return new Complejo(resReal, resImaginario);
    }
    
    // Genera una string con la representación de un número complejo
    public static String mostrarNumero(Complejo complejo) {
        float real = complejo.getParteReal();
        float imaginaria = complejo.getParteImaginaria();
        
        String resultado = Float.toString(real);
        
        resultado += (imaginaria >= 0) ? " + i" : " - i";
        imaginaria = Math.abs(imaginaria);
        
        resultado += (imaginaria != 1) ? Float.toString(imaginaria) : "";
        
        return resultado;
    }
    
}
