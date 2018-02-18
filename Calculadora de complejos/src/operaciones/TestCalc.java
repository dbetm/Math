package operaciones;
/**
 * @author david
 * Pruebas de las clases Calc y Complejo
 */
public class TestCalc {
    public static void main(String []args) {
        // Se instancian dos números complejos
        Complejo c1 = new Complejo(-3, 5);
        Complejo c2 = new Complejo(13, -7);
        Complejo c3 = new Complejo(1, 1);

        Complejo res = Calc.sumar(c1, c2);   
        System.out.println("Suma c1+c2: " + Calc.mostrarNumero(res));
        
        res = Calc.restar(c1, c2);   
        System.out.println("Resta c1-c2: " + Calc.mostrarNumero(res));
        
        res = Calc.multiplicar(c1, c2);
        System.out.println("Multiplicación c1*c2: " + Calc.mostrarNumero(res));
        
        res = Calc.dividir(c1, c2);
        System.out.println("División c1/c2: " + Calc.mostrarNumero(res));
        
        res = Complejo.conjugar(c2);
        System.out.println("El conjugado de 13 - i7 es: " + Calc.mostrarNumero(res));
        
        System.out.println("Forma trigonométrica de 1 + i: " + 
                Calc.mostrarFormaTrigonometrica(c3));
        
        System.out.println("Forma exponencial de 1 + i: " + 
                Calc.mostrarFormaExponencial(c3));
    }
}
