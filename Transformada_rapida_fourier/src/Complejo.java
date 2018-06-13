

/**
 * @author david
 * Esta clase modela un número complejo (forma algebraica)  como par ordenado z = (x,y) = x + iy.
 * Contiene un método para obtener el conjugado de determinado número complejo.
 * Se pueden calcular ángulo y módulo para facilitar la representación de las otras formas
 */
public class Complejo {
    // Atributos, para la forma algebraica.
    private float parteReal;
    private float parteImaginaria;
    // Genéricos.
    private float modulo;
    // Forma exponencial (Euler) y trigonométrica.
    private float angulo; // <= en grados
    
    // Constructor
    public Complejo(float parteReal, float parteImaginaria) {
        this.parteReal = parteReal;
        this.parteImaginaria = parteImaginaria;
        calcularAngulo();
        calcularModulo();
    }
    
    // Para obtener el conjugado de un número complejo 
    public static Complejo conjugar(Complejo A) {
        Complejo complejoConjugado = new Complejo(A.getParteReal(), - A.getParteImaginaria());
        
        return complejoConjugado;
    }
    
    // Para obtener su módulo
    private void calcularModulo() {
        modulo = (float)Math.pow(parteReal, 2) + 
                (float)Math.pow(parteImaginaria, 2);
        modulo = (float)Math.sqrt(modulo);
    }
    
    // Para calcular el angulo
    private void calcularAngulo() {
        if(parteReal == 0) {
            angulo = 90;
        }
        else {
            angulo = (float)Math.toDegrees(Math.atan(parteImaginaria / parteReal));
        }
    }
    
    // Métodos de acceso
    public float getParteReal() {
        return parteReal;
    }

    public void setParteReal(float parteReal) {
        this.parteReal = parteReal;
        calcularModulo();
        calcularAngulo();
    }

    public float getParteImaginaria() {
        return parteImaginaria;
    }

    public void setParteImaginaria(float parteImaginaria) {
        this.parteImaginaria = parteImaginaria;
        calcularModulo();
        calcularAngulo();
    }
    
    public float getModulo() {
        return modulo;
    }
    
    public float getAngulo() {
        return angulo;
    }
}
