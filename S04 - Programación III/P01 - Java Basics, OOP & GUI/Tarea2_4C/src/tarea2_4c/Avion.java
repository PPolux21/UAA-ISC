/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class Avion {
    protected String nombre;
    protected String destino;

    public Avion(String nombre, String destino) {
        this.nombre = nombre;
        this.destino = destino;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }
    
    public void mostrarDatos()
    {
        System.out.println("\nVuelo: " + this.nombre + "\nDestino: " + this.destino);
    }
    
}
