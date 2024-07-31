/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package tarea1_4c;

/**
 *
 * @author José Luis Espinoza Sánchez
 */
import java.util.Scanner;

public class Tarea1_4C
{

    static Scanner in = new Scanner(System.in);
    public static void main (String[] args)
    {
        int opc;
        do {
            System.out.println();
            System.out.println();

            System.out.println("      MENU");
            System.out.println("1. Ejercicio 1");
            System.out.println("2. Ejercicio 2");
            System.out.println("3. Ejercicio 3");
            System.out.println("4. Ejercicio 4");
            System.out.println("5. Ejercicio 5");
            System.out.println("6. Ejercicio 6");
            System.out.println("7. Ejercicio 7");
            System.out.println("8. Ejercicio 8");
            System.out.println("9. Ejercicio 9");
            System.out.println("10. Ejercicio 10");
            System.out.println("11. Salir");

            System.out.print("Elige una opción: ");
            opc = in.nextInt();
            
            System.out.println();

            switch (opc) {
                case 1 -> Ejercicios.ejercicio_1();
                case 2 -> Ejercicios.ejercicio_2();
                case 3 -> Ejercicios.ejercicio_3();
                case 4 -> Ejercicios.ejercicio_4();
                case 5 -> Ejercicios.ejercicio_5();
                //case 6 -> Ejercicios.ejercicio_6();
                case 7 -> Ejercicios.ejercicio_7();
                //case 8 -> Ejercicios.ejercicio_8();
                case 9 -> Ejercicios.ejercicio_9();
                case 10 -> Ejercicios.ejercicio_10();
            }

        } while (opc != 11);

        in.close();
    }
    /*
    public static void ejercicio_1 ()
    {
        double a,b,c,d;
        System.out.print("Introduce un numero: ");
        a = in.nextDouble();
        System.out.print("Introduce un numero: ");
        b = in.nextDouble();
        System.out.print("Introduce un numero: ");
        c = in.nextDouble();
        System.out.print("Introduce un numero: ");
        d = in.nextDouble();

        double res1, res2;
        res1 = (a+b+c) / d;
        System.out.println("\na) " + res1);

        res1 = Math.pow((a-b),2);
        res1 = res1 / c;

        res2 = Math.pow((a-b),3);
        res2 = res2 / (d/a);
        
        System.out.println("b) " + (res1+res2));
    }
    
    
    public static void ejercicio_2 ()
    {
        int ullman;

        System.out.print("Introduce un numero: ");
        ullman = in.nextInt();

        System.out.print("\n" + ullman + " ");

        do {
            if (ullman % 2 == 0) {
                ullman /= 2;
            }else{
                ullman *= 3;
                ullman += 1;
            }

            System.out.print(ullman + " ");

        } while (ullman != 1);
    }
    
    
    public static void ejercicio_3 ()
    {
        char letra;
        int sueldo;
        System.out.print("Categoría del contrato: ");
        letra = in.next().charAt(0);
        System.out.print("Sueldo actual: ");
        sueldo = in.nextInt();

        switch (letra) {
            case 'S' -> sueldo *= 1.20;
            case 'C' -> sueldo *= 1.15;
            case 'D' -> sueldo *= 1.10;
            case 'E' -> sueldo *= 1.05;
        }
        
        System.out.println("\nNuevo sueldo: " + sueldo);
    }
    
    
    public static void ejercicio_4 ()
    {
        char [] texto;
        int digito = 0, letras = 0;

        System.out.print("Ingresa un texto (alfanumérico): ");
        texto = in.nextLine().toCharArray();

        for (int index = 0; index < texto.length ; index++)
            if ( Character.isDigit(texto[index]) )
                digito += 1;
            else if (Character.isLetter(texto[index]))
                letras += 1;

        System.out.println("\nCantidad de Digitos: " +  digito);

        System.out.println("Cantidad de Letras: " +  letras);
    }

    
    public static void ejercicio_5 ()
    {
        String texto;

        System.out.print("Ingresa un texto: ");
        in.nextLine();
        texto = in.nextLine();

        System.out.println("\n" + texto);

        texto = modificaCadena_5(texto);
        
        System.out.println("\n" + texto);

    }

    public static String modificaCadena_5 ( String texto)
    {
        String txNew = new String();
        char aux;
        int tam = texto.length();

        for (int i = 0; i < tam; i++) {
            aux = texto.charAt(tam-i-1);

            if(Character.isLetter(aux))
            {
                if (Character.isLowerCase(aux)) {
                    aux = Character.toUpperCase(aux);
                }else{
                    aux = Character.toLowerCase(aux);
                }
            }

            System.out.println(aux);
            
            txNew = txNew + aux;
        }

        return txNew;
    }    
    */
}
