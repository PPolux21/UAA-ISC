/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class Libro {
    private String titulo;
    private String autor;
    private int ejemplares;
    private int prestados;

    public Libro() {
        this.titulo = new String();
        this.autor = new String();
        this.ejemplares = 0;
        this.prestados = 0;
    }
    

    public Libro(String titulo, String autor, int ejemplares, int prestados) {
        this.titulo = titulo;
        this.autor = autor;
        this.ejemplares = ejemplares;
        this.prestados = prestados;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getEjemplares() {
        return ejemplares;
    }

    public void setEjemplares(int ejemplares) {
        this.ejemplares = ejemplares;
    }

    public int getPrestados() {
        return prestados;
    }

    public void setPrestados(int prestados) {
        this.prestados = prestados;
    }
   
    public boolean prestamo()
    {
        if(this.ejemplares > this.prestados)
        {
            this.prestados++;
            return true;
        }else{
            return false;
        }
    }
    
    public boolean devolucion()
    {
        if(this.prestados > 0)
        {
            this.prestados--;
            return true;
        }else{
            return false;
        }
    }
    
    public void mostrar()
    {
        System.out.println("\n" + this.titulo + ", " + this.autor);
        System.out.println("Total de libros: " + this.ejemplares);
        System.out.println("Libros prestados: " + this.prestados);
    }
}
