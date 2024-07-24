/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package figuragenerica;

/**
 *
 * @author josel
 */
abstract class Figura<T> {
    
    protected T dimension;
    
    public Figura(T dimension)
    {
        this.dimension = dimension;
    }
    
    abstract double obtenerArea();
    
}
