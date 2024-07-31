/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class AvionHidrante extends Avion {
    
    int litros;

    public AvionHidrante(String nombre, String destino, int litros) {
        super(nombre, destino);
        this.litros = litros;
    }

    public int getLitros() {
        return litros;
    }

    public void setLitros(int litros) {
        this.litros = litros;
    }
    
    public void descargarAgua()
    {
        this.litros = 0;
    }
    
    public void descargarAgua(int litros)
    {
        this.litros -= litros;
    }
    
    @Override
    public void mostrarDatos()
    {
        super.mostrarDatos();
        System.out.println("Agua: " + this.litros + " lts");
    }
}
