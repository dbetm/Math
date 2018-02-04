package operaciones;
/**
 *
 * @author david
 */
public class Calc {
    
    public static String sumar(Complejo A, Complejo B) {
        float resReal, resImaginario;
        resReal = A.getParteReal() + B.getParteReal();
        resImaginario = A.getParteImaginaria() + B.getParteImaginaria();
        return construirResultado(resReal, resImaginario);
    }
    
    
    public static String construirResultado(float real, float imaginaria) {
        String resultado = Float.toString(real);
        
        resultado += (imaginaria > 0) ? " + j" : " - j";
        imaginaria = Math.abs(imaginaria);
        resultado += Float.toString(imaginaria);
        
        return resultado;
    }
}
