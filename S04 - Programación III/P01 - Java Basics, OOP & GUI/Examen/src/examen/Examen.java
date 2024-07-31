/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package examen;

/**
 *
 * @author josel
 */
public class Examen {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BienInmueble vector[];// = new BienInmueble[3];
        
        vector[0]= new Edificio();
        vector[1]= new CasaHabitacion();
        vector[2]= new Departamento();
        
        for(BienInmueble x : vector)
            x.mostrarDatos();
        
        
        
    }
    
}
