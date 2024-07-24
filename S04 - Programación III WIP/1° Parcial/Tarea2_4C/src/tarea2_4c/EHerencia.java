/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

import java.util.Scanner;

/**
 *
 * @author josel
 */

/*
Archivos relacionados:
    Empleado.java
    Operario.java
    Directivo.java
    Oficial.java
    Tecnico.java
    
    Avion.java
    AvionPasajeros.java
    AvionHidrante.java
*/

public class EHerencia {
    
    static Scanner in = new Scanner(System.in);
    
    public static void ejercicio_2()
    {
        Empleado [] array = new Empleado [5];
        array[0] = new Empleado("Rafa");
        array[1] = new Directivo("Mario");
        array[2] = new Operario("Alfonso");
        array[3] = new Oficial("Luis");
        array[4] = new Tecnico("Pablo");
        
        for(Empleado i: array)
            System.out.println(i);
        
        System.out.print("\nPresione Enter para continuar . . .");
        in.nextLine();
    }
    
    public static void ejercicio_3()
    {
        AvionPasajeros ap = new AvionPasajeros("AZ19B2", "Londres", 2400, 270.5F);
        AvionHidrante ah = new AvionHidrante("BT3533P8", "Bariloche", 500);
        ap.mostrarDatos();
        ah.mostrarDatos();
        ah.descargarAgua(300);
        ah.mostrarDatos();
        ah.descargarAgua();
        ah.mostrarDatos();
        Avion[] vuelos = new Avion[2];
        vuelos[0] = ap;
        vuelos[1] = ah;
        for(Avion x : vuelos)
            if (x instanceof AvionHidrante)
                System.out.println("el vuelo " + x.getNombre() + " es un Hidrante");
        
        System.out.print("\nPresione Enter para continuar . . .");
        in.nextLine();
    }
}
