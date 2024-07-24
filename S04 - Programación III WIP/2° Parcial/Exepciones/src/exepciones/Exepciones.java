/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package exepciones;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author josel
 */
public class Exepciones {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*
        try {
            // Intentamos abrir un archivo que no existe
            File archivo = new File("archivo_que_no_existe.txt");
            Scanner scanner = new Scanner(archivo);
            // Si llegamos aquí, el archivo se abrió correctamente
            System.out.println("Archivo abierto correctamente.");
        } catch (FileNotFoundException e) {
            // Capturamos la excepción FileNotFoundException
            System.out.println("No se encontró el archivo: " + e.getMessage());
            // Aquí podríamos realizar alguna acción de manejo de la excepción, como informar al
            //usuario o registrar el error
        }*/
        /*
        try {
            int resultado = dividir(10,0);
            System.out.println("El resultado de la division es: " + resultado);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division entre cero");
            //System.out.println(e.getMessage());
        }*/
        /*
        try {
            int s = 4/0;
            System.out.println("El programa sigue");
        } catch(ArithmeticException e) {
            System.out.println("Division por cero");
            return;
        } catch (Exception e) {
            System.out.println("Excepcion general");
        } finally {
            System.out.println("Finally :D");
        }
        */
        
        try {
            //método que puede lanzar una excepcion
            metodoExcepcion();
        } catch (Exception e) {
            System.out.println("Excepcion capturada en el metodo main: " + e.getMessage());
        }
    }
    
    public static int dividir(int a,int b)
    {
        return a/b;
    }
    
    public static void metodoExcepcion() throws Exception
    {
        throw new Exception("Wenas, Esto es una excepcion :O");
    }
    
}
