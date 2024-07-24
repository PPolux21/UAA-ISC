/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package figuragenerica;

/**
 *
 * @author josel
 */
public class FiguraGenerica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Circulo circulo = new Circulo(5.0);
        System.out.println("Área del circulo: " + circulo.obtenerArea());
        
        Rectangulo recangulo = new Rectangulo(new DosDimensiones(4.0,3.0));
        System.out.println("Área del rectángulo: " + recangulo.obtenerArea());
    }
    
}
