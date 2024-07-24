/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package examen;

/**
 *
 * @author josel
 */
public class Departamento extends BienInmueble implements Habitacional,Soltero{
    private int numHabit;
    private int numPisos;
    private boolean tipo;//soltero = true | casado = false

    public Departamento(int numHabit, int numPisos, boolean tipo, double costoActual, double costoMax) {
        super(costoActual, costoMax);
        this.numHabit = numHabit;
        this.numPisos = numPisos;
        this.tipo = tipo;
    }
    
    public Departamento()
    {
        super();
        this.numHabit = 15;
        this.numPisos = 2;
        this.tipo = true;
    }
    
    public int getNumHabit() {
        return numHabit;
    }

    public void setNumHabit(int numHabit) {
        this.numHabit = numHabit;
    }

    public int getNumPisos() {
        return numPisos;
    }

    public void setNumPisos(int numPisos) {
        this.numPisos = numPisos;
    }

    public boolean isTipo() {
        return tipo;
    }

    public void setTipo(boolean tipo) {
        this.tipo = tipo;
    }
    
    @Override
    public void vender(double costoPorcent)
    {
        double costoFinal = this.costoActual * costoPorcent / 100 ; 
        
        costoFinal += this.costoActual;
        
        if(costoFinal >= this.costoMax)
        {
            costoFinal = costoMax;
        }
        
        this.costoActual = costoFinal;
    }
    
    @Override
    public void comprar(double costoPorcent)
    {
        if(costoPorcent < 30)
        {   
            double costoFinal = this.costoActual * costoPorcent / 100 ;
            
            costoFinal = this.costoActual - costoFinal;

            if(costoFinal < 0)
            {
                costoFinal = 0;
            }

            this.costoActual = costoFinal;
        }
    }
    
    @Override
    public void imprimir()
    {
        System.out.println("Costo actual: " + this.costoActual);
        System.out.println("Costo Maximo: " + this.costoMax);
    }

    @Override
    public void mostrarDatos() {
        System.out.println("Numero de habitaciones: "+ this.numHabit);
        System.out.println("Numero de pisos: "+ this.numPisos);
        if(tipo)
            this.soltero();
        else
            this.casado();
        System.out.println("Costo actual: " + this.costoActual);
    }
    

    @Override
    public boolean recomendarAgrandarCasa(double mtsCuadrados, int personas) {
        boolean flag = false;
        int relacionPerHabit = personas / this.numHabit;
        
        if(relacionPerHabit != 2)
        {
            flag = relacionPerHabit > 2;
            
            int habitRecom = personas/relacionPerHabit;
            int pisosRecom = this.numHabit/this.numPisos;
            pisosRecom *= habitRecom;
            
            System.out.println("Cantidad de habitaciones recomendadas: " + habitRecom); 
            System.out.println("Cantidad de pisos recomendados: " + pisosRecom); 
        }else
            System.out.println("Cantidad de habitaciones adecuadas"); 
        
        
        return flag;        
    }

    @Override
    public void casado() {
        this.tipo = true;
        System.out.println("Departamento de soltero");
    }

    @Override
    public void soltero() {
        this.tipo = false;
        System.out.println("Departamento de casado");
    }
    
    
}
