/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package figuragenerica;

/**
 *
 * @author josel
 */
public class Rectangulo extends Figura<DosDimensiones> {

    public Rectangulo(DosDimensiones dimension) {
        super(dimension);
    }

    @Override
    double obtenerArea() {
        DosDimensiones d = dimension;
        return d.ancho * d.altura;
    }
    
    
}
