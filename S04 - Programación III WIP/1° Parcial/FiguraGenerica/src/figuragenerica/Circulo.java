/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package figuragenerica;

/**
 *
 * @author josel
 */
public class Circulo extends Figura<Double> {
    
    public Circulo(Double radio) {
        super(radio);
    }

    @Override
    public double obtenerArea() {
        double radio = dimension;
        return Math.PI * radio * radio;
    }
    
}
