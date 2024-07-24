/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
import java.util.Scanner;


public class Tarea2_4C {

    /**
     * @param args the command line arguments
     */
    
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        
        int opc;
        do {
            System.out.println();
            System.out.println();

            System.out.println("            MENU");
            System.out.println("1.  Ejercicio Clases Simples 1");
            System.out.println("2.  Ejercicio Clases Simples 2");
            System.out.println("3.  Ejercicio Clases Simples 3");
            System.out.println("4.  Ejercicio Clases Simples 4");
            System.out.println("5.  Ejercicio Herencia 1");
            System.out.println("6.  Ejercicio Herencia 2");
            System.out.println("7.  Ejercicio Herencia 3");
            System.out.println("8.  Ejercicio Polimorfismo 1");
            System.out.println("9.  Ejercicio Polimorfismo 2");
            System.out.println("10. Ejercicio Polimorfismo 3");
            System.out.println("11. Ejercicio Polimorfismo 4");
            System.out.println("12. Salir");

            System.out.print("Elige una opción: ");
            opc = in.nextInt();
            
            System.out.println();

            switch (opc) {
                case 1 -> EClasesSimples.ejercicio_1();
                case 2 -> EClasesSimples.ejercicio_2();
                case 3 -> EClasesSimples.ejercicio_3();
                case 4 -> EClasesSimples.ejercicio_4();
                //case 5 -> ;
                case 6 -> EHerencia.ejercicio_2();
                case 7 -> EHerencia.ejercicio_3();
                /*case 8 -> ;
                case 9 -> ;
                case 10 -> ; 
                case 11 -> ; */
            }

        } while (opc != 12);

        in.close();
    }
    
}
