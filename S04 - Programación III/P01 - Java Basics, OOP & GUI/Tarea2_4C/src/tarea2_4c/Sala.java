/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class Sala {
    
    private String nombre;
    private double ancho;
    private double largo;
    private boolean equipado;

    public Sala(String nombre, double ancho, double largo, boolean equipado) {
        this.nombre = nombre;
        this.ancho = ancho;
        this.largo = largo;
        this.equipado = equipado;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getAncho() {
        return ancho;
    }

    public void setAncho(double ancho) {
        this.ancho = ancho;
    }

    public double getLargo() {
        return largo;
    }

    public void setLargo(double largo) {
        this.largo = largo;
    }

    public boolean isEquipado() {
        return equipado;
    }

    public void setEquipado(boolean equipado) {
        this.equipado = equipado;
    }
    
    public double getSuperficie()
    {
        return this.ancho * this.largo;
    }
    
    public int cantAsistentes()
    {
        double area;
        
        area = this.ancho * this.largo;
        
        return (int)(area/1.5);
    }
    
    public double valorAlquiler()
    {
        double area;
        
        area = this.ancho * this.largo;
        
        if(this.equipado)
        {
            return (area * 50);
        }else{
            return (area * 30);
        }
        
    }
    
    public void datosSala()
    {
        boolean aux = this.equipado;
        
        System.out.println("Cantidad maxima de asistentes: " + this.cantAsistentes());
        
        this.equipado = true;
        
        System.out.println("Valor de alquiler con equipamiento: " + this.valorAlquiler());
        
        this.equipado = false;
        
        System.out.println("Valor de alquiler sin equipamiento: " + this.valorAlquiler());
        
        this.equipado = aux;
    }
}
