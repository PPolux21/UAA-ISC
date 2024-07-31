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

public class Vagon {
    
    private boolean [] asientos = new boolean[50];
    private int clase;

    public Vagon() {
        for (int i = 0; i < 50; i++) {
            this.asientos[i] = false;
        }
        
        this.clase = 1;
    }

    
    public Vagon(Vagon obj) {
        this.asientos = obj.asientos;
        this.clase = obj.clase;
    }

    public boolean[] getAsientos() {
        return asientos;
    }

    public void setAsientos(boolean[] asientos) {
        this.asientos = asientos;
    }

    public int getClase() {
        return clase;
    }

    public void setClase(int clase) {
        if(clase == 1 || clase == 2)
        {
            this.clase = clase;
        }
    }
    
    public void ocupaAsiento(int numeroAsiento)
    {
        if(!this.asientos[numeroAsiento-1])
        {
            this.asientos[numeroAsiento-1] = true;   
        }
    }
    
    public void desocupaAsiento(int numeroAsiento)
    {
        if(this.asientos[numeroAsiento-1])
        {
            this.asientos[numeroAsiento-1] = false;   
        }
    }
    
    public void llenaVagon()
    {
        Random rand = new Random();
        
        switch (this.clase) {
            case 1 -> {
                for (int i = 0; i < 50; i++) 
                {
                    if(rand.nextInt(100) >= 89)
                    {
                        this.ocupaAsiento(i+1);
                    }
                }
            }
            case 2 -> {
                for (int i = 0; i < 50; i++) 
                {
                    if(rand.nextInt(100) >= 59)
                    {
                        this.ocupaAsiento(i+1);
                    }
                }
            }
        }
    }
    
    public void muestraVagon()
    {
        System.out.println("\nClase: " + this.clase);
        
        for (int i = 0; i < 50; i++) 
        {
            if(i%5 == 0)
                System.out.println();
            
            if(this.asientos[i])
            {
                System.out.print("[1] ");
            }else{
                System.out.print("[0] ");
            }
        }
        
        System.out.println("\nAsientos ocupados: " + this.asientosOcupados());
        System.out.println();
    }
    
    public int asientosOcupados()
    {
        int cant = 0;
        
        for (int i = 0; i < 50; i++) 
        { 
            if(this.asientos[i])
            {
                cant++;
            }
        }
         return cant;
    }
}