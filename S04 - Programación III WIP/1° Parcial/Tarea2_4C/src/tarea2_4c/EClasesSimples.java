/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */

/*
Archivos relacionados:
    CuentaAhorroJr.java
    Sala.java
    Vagon.java
    Tren.java
    Libro.java
*/

import java.util.Scanner;
import java.util.Random;

public class EClasesSimples {
    
    static Scanner in = new Scanner(System.in);
    public static void ejercicio_1()
    {
        CuentaAhorroJr miAhorro = new CuentaAhorroJr(0);
        
        miAhorro.setSaldo(20000);
        
        double cantidad;
        int opc;
        do {
            System.out.println();
            System.out.println();

            System.out.println("   MENU");
            System.out.println("1.  Deposito");
            System.out.println("2.  Retiro");
            System.out.println("3.  Saca Mitad");
            System.out.println("4.  Salir");

            System.out.print("Elige una opción: ");
            opc = in.nextInt();
            
            System.out.println();

            switch (opc) {
                case 1 -> {
                    System.out.print("Cantidad a depositar: ");
                    cantidad = in.nextDouble();
                    
                    miAhorro.deposito(cantidad);
                }
                case 2 -> {
                    System.out.print("Cantidad a retirar: ");
                    cantidad = in.nextDouble();
                    
                    miAhorro.retiro(cantidad);
                }
                case 3 -> miAhorro.sacaMitad();               
            }

        } while (opc != 4);
    }
    
    public static void ejercicio_2()
    {
        Sala sala1 = new Sala("Sala1",8,12,true);
        Sala sala2 = new Sala("Sala2",18,20,false);
        Sala sala3 = new Sala("Sala3",12,15,true);
        
        System.out.println("Nombre: " + sala1.getNombre());
        System.out.println("Superficie: " + sala1.getSuperficie());
        sala1.datosSala();
        
        Random rand = new Random();
        int tam = rand.nextInt(25);
        
        Sala vec []= new Sala[tam];
        
        for (int i = 0; i < tam; i++) {
            vec[i] = new Sala("Sala "+(i+1),rand.nextDouble(22.75),rand.nextDouble(22.75),rand.nextBoolean());
        }
        
        System.out.println();
        
        for (int i = 0; i < tam; i++) {
            if(vec[i].cantAsistentes() >= 200)
            {
                System.out.println(vec[i].getNombre() + " puede alojar el evento de 200 asistentes");
                System.out.println("Ancho: " + vec[i].getAncho() + "\nLargo: " + vec[i].getLargo());
                System.out.println();
            }

            if(vec[i].cantAsistentes() >= 150)
            {
                System.out.println(vec[i].getNombre() + " puede alojar el evento de 150 asistentes");
                System.out.println("Ancho: " + vec[i].getAncho() + "\nLargo: " + vec[i].getLargo());
                System.out.println();
            }
            
            if(vec[i].cantAsistentes() >= 100)
            {
                System.out.println(vec[i].getNombre() + " puede alojar el evento de 100 asistentes");
                System.out.println("Ancho: " + vec[i].getAncho() + "\nLargo: " + vec[i].getLargo());
                System.out.println();
            }
            
            if(vec[i].cantAsistentes() >= 50)
            {
                System.out.println(vec[i].getNombre() + " puede alojar el evento de 50 asistentes");
                System.out.println("Ancho: " + vec[i].getAncho() + "\nLargo: " + vec[i].getLargo());
                System.out.println();
            }
        }
        
        System.out.print("\nPresione Enter para continuar . . .");
        in.nextLine();
    }
    
    public static void ejercicio_3()
    {
        Vagon vagon1 = new Vagon();
        
        Vagon vagon2 = new Vagon();
        
        vagon1.llenaVagon();
        vagon1.muestraVagon();
        
        vagon2.setClase(2);
        vagon2.llenaVagon();
        vagon2.muestraVagon();
        
        Tren tren1 = new Tren(5,"Aguascalientes","Jalisco");
        
        tren1.llenaTren();
        tren1.mostrarTren();
        
        System.out.println("\nVenta total de tickets: " + tren1.ticketsVendidos());
        System.out.println("Ganancias con las ventas de tickets: $" + tren1.ventas());
        
        System.out.print("\nPresione Enter para continuar . . .");
        in.nextLine();
    }
    
    public static void ejercicio_4()
    {
        Libro libro1 = new Libro("La metamorfosis","Franz Kafka",15,0);
        
        libro1.mostrar();
        
        libro1.prestamo();
        
        libro1.mostrar();
        
        libro1.devolucion();
        
        libro1.mostrar();
        
        System.out.print("\nPresione Enter para continuar . . .");
        in.nextLine();
    }
}
