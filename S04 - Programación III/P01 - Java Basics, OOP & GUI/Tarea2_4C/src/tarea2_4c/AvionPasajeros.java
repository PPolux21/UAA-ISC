/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class AvionPasajeros extends Avion {
    
    int kilos;
    float tiempo;

    public AvionPasajeros(String nombre, String destino, int kilos, float tiempo) {
        super(nombre, destino);
        this.kilos = kilos;
        this.tiempo = tiempo;
    }    
    
    @Override
    public void mostrarDatos()
    {
        super.mostrarDatos();
        System.out.println("Equipaje: " + this.kilos + " kg");
        System.out.println("Duracion del vuelo: " + this.tiempo + " min.");
    }
    
}
