package operaciones;

/**
 *
 * @author david
 */
public class TestCalc {
    public static void main(String []args) {
        Complejo c1 = new Complejo(-3, 5);
        Complejo c2 = new Complejo(13, -7);

        Complejo res = Calc.sumar(c1, c2);   
        System.out.println("Suma c1+c2: " + Calc.mostrarNumero(res));
        
        res = Calc.restar(c1, c2);   
        System.out.println("Resta c1-c2: " + Calc.mostrarNumero(res));
        
        res = Calc.multiplicar(c1, c2);
        System.out.println("Multiplicación c1*c2: " + Calc.mostrarNumero(res));
        
        res = Calc.dividir(c1, c2);
        System.out.println("División c1/c2: " + Calc.mostrarNumero(res));
        
    }
}
