/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pilasgenericas;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author josel
 */
public class PilasGenericas {

    /**
     * @param args the command line arguments
     */

    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        
        
        int opc;
        do {            
            System.out.println("\tMENU");
            System.out.println("Anadir - - - - 1");
            System.out.println("Eliminar - - - 2");
            System.out.println("Mostrar  - - - 3");
            System.out.println("Salir  - - - - 4");
            System.out.print("Opcion: ");
            opc = in.nextInt();
            
            switch (opc) {
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
            }        
        } while (opc != 4);
    }
    
}
