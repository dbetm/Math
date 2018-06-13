package operaciones;
/**
 * @author david
 * Esta clase contiene las operaciones básicas, cada una recibe dos números
 * complejos con los que se va a operar, y por defecto retorna la instancia de un número
 * complejo que representa el resultado en su forma algebraica.
 */

public class Calc {
    // ============== SUMA
    public static Complejo sumar(Complejo A, Complejo B) {
        // Atributos a calcular para contruir el número complejo resultado
        float resReal, resImaginario;
        
        // Se hacen los cálculos, en este caso la suma => (x1+x2) + i(y1+y2)
        resReal = A.getParteReal() + B.getParteReal();
        resImaginario = A.getParteImaginaria() + B.getParteImaginaria();
        
        // Se retorna un objeto Complejo.
        return new Complejo(resReal, resImaginario);
    }
    
    // ============== RESTA => (x1-x2) + i(y1-y2)
    public static Complejo restar(Complejo A, Complejo B) {
        float resReal, resImaginario;
        
        resReal = A.getParteReal() - B.getParteReal();
        resImaginario = A.getParteImaginaria() - B.getParteImaginaria();
        
        return new Complejo(resReal, resImaginario);
    }
    
    // ============== MULTIPLICACIÓN => (x1x2 - y1y2) + i(x1y2 - x2y1)
    public static Complejo multiplicar(Complejo A, Complejo B) {
        float resReal, resImaginario;
        
        resReal = A.getParteReal() * B.getParteReal() - 
                (A.getParteImaginaria() * B.getParteImaginaria());
        
        resImaginario = (A.getParteReal() * B.getParteImaginaria()) + 
                (B.getParteReal() * A.getParteImaginaria());
        
        return new Complejo(resReal, resImaginario);
    }
    
    // ============== DIVISIÓN => [ (x1x2 + y1y2) / (x2^2 + y2^2) ] +  
        // i [ (x2y1 - x1y2) / (x2^2 + y2^2) ]
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
    
    // Genera una string con la representación de un número complejo => x + iy
    public static String mostrarNumero(Complejo complejo) {
        float real = complejo.getParteReal();
        float imaginaria = complejo.getParteImaginaria();
        
        String resultado = Float.toString(real);
        resultado += (imaginaria >= 0) ? " + i" : " - i";
        imaginaria = Math.abs(imaginaria);
        resultado += (imaginaria != 1) ? Float.toString(imaginaria) : "";
        
        return resultado;
    }
    
    // Genera una string con la forma trigonométrica de un complejo
    public static String mostrarFormaTrigonometrica(Complejo complejo) {
        String numero, r, angulo;
        r = String.format("%.2f", complejo.getModulo());
        angulo = String.format("%.2f", complejo.getAngulo());
        numero = r + "[cos(" + angulo + "°) + isen(" + angulo + "°)]";
        return numero;
    }
    
    // Genera una string con la forma exponencial o de Euler de un complejo
    public static String mostrarFormaExponencial(Complejo complejo) {
        String numero, r, angulo;
        r = String.format("%.2f", complejo.getModulo());
        angulo = String.format("%.2f", complejo.getAngulo());
        numero = r + "e^i" + angulo;  
        return numero;
    }
    
}
