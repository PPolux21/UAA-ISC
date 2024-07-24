/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea1_4c;

/**
 *
 * @author josel
 */

import java.util.Scanner;
import java.util.Random;

public class Ejercicios {
    
    
    static Scanner in = new Scanner(System.in);
    
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
        //in.nextLine();
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
            
            txNew = txNew + aux;
        }

        return txNew;
    }
    /*
    public static void ejercicio_6 ()
    {
        String s1, s2;
        
        System.out.print("Ingresa un texto: ");
        s1 = in.nextLine();
        
        System.out.print("Ingresa un texto: ");
        s2 = in.nextLine();
    }
    */
    
    public static void ejercicio_7 ()
    {
        char [] s1;
        int tam = 0,iniC = 0;
        
        System.out.print("Ingresa un texto: ");
        s1 = in.nextLine().toCharArray();
        
        for(int i = 0; i < s1.length; i++)
        {
            if(Character.isLetter(s1[i]))
            {
                if(i != 0 && Character.isSpaceChar(s1[i-1]))
                    iniC = i;
                tam++;
            }else if(Character.isSpaceChar(s1[i]))
            {
                for (int j = iniC; j < i; j++) {
                    if(Character.isLowerCase(s1[iniC]))
                    {
                        s1[iniC] = Character.toUpperCase(s1[iniC]);
                    }
                    System.out.print(s1[j]);
                }
                
                
                System.out.println(" " + tam); 
                tam = 0;
            }
            
        }   
        
        for (int j = iniC; j < s1.length; j++) {
            if(Character.isLowerCase(s1[iniC]))
            {
                s1[iniC] = Character.toUpperCase(s1[iniC]);
            }
            System.out.print(s1[j]);
        }


        System.out.println(" " + tam); 
    }
    
    public static void ejercicio_9 ()
    {
        Random r = new Random();
        int [][] matriz;
        int longitud, sumFila, sumCol;
        
        System.out.print("Ingresa la longitud de la matriz: ");
        longitud = in.nextInt();      
        
        matriz = new int [longitud][longitud];
        
        for (int i = 0; i < longitud; i++) {
            for (int j = 0; j < longitud; j++) {
                matriz[i][j] = r.nextInt(100);
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
        
        System.out.println("\nResultados: ");
        
        System.out.println("   Columnas: ");
        
        for (int i = 0; i < longitud; i++) {
            sumCol = 0;
            for (int j = 0; j < longitud; j++) {
                sumCol += matriz[i][j];
            }
            
            System.out.println("\t " + sumCol);
        }
        
        System.out.println("\n   Filas: ");
        
        for (int i = 0; i < longitud; i++) {
            sumFila = 0;
            for (int j = 0; j < longitud; j++) {
                sumFila += matriz[j][i];
            }
            
            System.out.println("\t " + sumFila);
        }
    }
    
    
    public static void ejercicio_10 ()
    {
        Random r = new Random();
        int [][] matriz1;
        int [][] matriz2;
        int filas,columnas;
        
        System.out.print("Ingresa la cantidad de Filas de la matriz: ");
        filas = in.nextInt();
        
        System.out.print("Ingresa la cantidad de Columnas de la matriz: ");
        columnas = in.nextInt();
        
        System.out.println();
        
        matriz1 = new int [filas][columnas];
        matriz2 = new int [filas][columnas];
        
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz1[i][j] = r.nextInt(100);
                matriz2[i][j] = r.nextInt(100);
            }
        }
        
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.print(matriz1[i][j] + " ");
            }
            
            System.out.print("\t");
            
            for (int j = 0; j < columnas; j++) {
                System.out.print(matriz2[i][j] + " ");
            }
            System.out.println();
        }
        
        System.out.println("\nResultado: ");
        
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.print((matriz1[i][j]+matriz2[i][j]) + " ");
            }
            System.out.println();
        }
        
    }
}
