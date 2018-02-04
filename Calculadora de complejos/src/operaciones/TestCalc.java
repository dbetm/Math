/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package operaciones;

/**
 *
 * @author david
 */
public class TestCalc {
    public static void main(String []args) {
        Complejo complex1 = new Complejo(5, 8);
        Complejo complex2 = new Complejo(3, -4);
        System.out.println(Calc.sumar(complex1, complex2));
    }
}
