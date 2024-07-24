/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
import java.util.Random;

public class Tren {
    //precios:
    //  Primera clase: $47.2
    //  Segudna clase: $18.5
    private Vagon [] vagones;
    private int cantVagones;
    private String partida;
    private String destino;

    public Tren(int cantVagones, String partida, String destino) {
        this.cantVagones = cantVagones;
        this.vagones = new Vagon[cantVagones];
        this.partida = partida;
        this.destino = destino;
        
        for (int i = 0; i < this.cantVagones; i++) {
            this.vagones[i] = new Vagon();
        }
    }

    public Tren(int cantVagones) {
        this.cantVagones = cantVagones;
        this.vagones = new Vagon[cantVagones];
        this.partida = new String();
        this.destino = new String();
        
        for (int i = 0; i < this.cantVagones; i++) {
            this.vagones[i] = new Vagon();
        }
    }

    public Vagon[] getVagones() {
        return vagones;
    }

    public void setVagones(Vagon[] vagones) {
        this.vagones = vagones;
    }

    public int getCantVagones() {
        return cantVagones;
    }

    public void setCantVagones(int cantVagones) {
        this.cantVagones = cantVagones;
    }

    public String getPartida() {
        return partida;
    }

    public void setPartida(String partida) {
        this.partida = partida;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }
    
    
    public void llenaTren()
    {
        Random rand = new Random();
        
        for (int i = 0; i < this.cantVagones; i++) {
            if(rand.nextBoolean())
                this.vagones[i].setClase(1);
            else
                this.vagones[i].setClase(2);
                
            this.vagones[i].llenaVagon();
        }
    }
    
    public int ticketsVendidos()
    {
        int tickets = 0;
        for (int i = 0; i < this.cantVagones; i++) {
            tickets += this.vagones[i].asientosOcupados();
        }
        
        return tickets;
    }
    
    public double ventas()
    {
        //precios:
        //  Primera clase: $47.2
        //  Segudna clase: $18.5
        
        double venta = 0;
        for (int i = 0; i < this.cantVagones; i++) {
            
            if(this.vagones[i].getClase() == 1)
            {
                venta += 47.2 * this.vagones[i].asientosOcupados();
            }else{
                venta += 18.5 * this.vagones[i].asientosOcupados();
            }
        }
        
        return venta;
    }
    
    public void mostrarTren()
    {
        for (int i = 0; i < this.cantVagones; i++) {
            System.out.println("\nVagon: " + (i+1));
            this.vagones[i].muestraVagon();
        }
    }
}
