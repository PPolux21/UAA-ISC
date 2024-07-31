/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class Directivo extends Empleado {

    public Directivo() {
        super();
    }

    public Directivo(String nombre) {
        super(nombre);
    }
    
    
    @Override
    public String toString() {
        return super.toString() + " -> Directivo";
    }
}
