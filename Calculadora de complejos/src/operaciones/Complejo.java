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
public class Complejo {
    // Atributos
    
    private float parteReal;
    private float parteImaginaria;
    
    // Constructor
    
    public Complejo(float parteReal, float parteImaginaria) {
        this.parteReal = parteReal;
        this.parteImaginaria = parteImaginaria;
    }
    
    // Para obtener el conjugado de un número complejo 
    public static Complejo conjugar(Complejo A) {
        Complejo complejoConjugado = new Complejo(A.getParteReal(), - A.getParteImaginaria());
        return complejoConjugado;
    }
    
    // Métodos de acceso

    public float getParteReal() {
        return parteReal;
    }

    public void setParteReal(float parteReal) {
        this.parteReal = parteReal;
    }

    public float getParteImaginaria() {
        return parteImaginaria;
    }

    public void setParteImaginaria(float parteImaginaria) {
        this.parteImaginaria = parteImaginaria;
    }
    
}
