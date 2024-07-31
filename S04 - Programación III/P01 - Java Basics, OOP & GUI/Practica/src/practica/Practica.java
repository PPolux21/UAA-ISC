/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package practica;

/**
 *
 * @author josel
 */
import java.util.Scanner;

public class Practica {

    /**
     * @param args the command line arguments
     */
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        // TODO code application logic here
        
        int tam,opc;
        
        System.out.print("Elementos a llenar: ");
        tam = in.nextInt();
        
        do {            
            
            System.out.println("Tipo de arreglo: \n");
            System.out.println("1. Integer");
            System.out.println("2. Double");
            System.out.println("3. Character");
            System.out.println("4. Long");
            System.out.println("5. Float");
            System.out.println("6. String");
            System.out.print("Opcion: ");
            opc = in.nextInt();
            
            switch (opc) {
                case 1:
                    
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
                case 6:
                    
                    break;
            }
            if(opc >= 1 && opc <= 6)
                break;
        } while (true);
    }
    
}
