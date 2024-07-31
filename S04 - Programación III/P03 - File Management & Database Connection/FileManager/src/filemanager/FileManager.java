/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package filemanager;

import java.io.*;

/**
 *
 * @author josel
 */
public class FileManager {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //para crear nuevo archivo y empezar a escribir en él
        try {
            FileWriter writer = new FileWriter("archivo.txt");
            
            writer.write("Wenas, este es un ejemplo de un FileWriter en Java");
            
            writer.close();
            System.out.println("Se ha escrito en el archivo exitosamente :D");
        } catch (IOException e) {
            System.out.println("Ocurrio un error al escribir en el archivo D:");
            e.printStackTrace();
        }
        //para agregar contenido al archivo
        try {
            FileWriter writer = new FileWriter("archivo.txt",true);
            
            writer.write("\n :O ");
            
            writer.close();
            System.out.println("Se ha escrito en el archivo exitosamente :D");
        } catch (IOException e) {
            System.out.println("Ocurrio un error al escribir en el archivo D:");
            e.printStackTrace();
        }
        
        
    }
    
}
