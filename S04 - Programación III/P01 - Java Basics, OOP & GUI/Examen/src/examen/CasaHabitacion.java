/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package examen;

/**
 *
 * @author josel
 */
public class CasaHabitacion extends BienInmueble implements Habitacional{
    
    private String tipo;
    private int numHabit;

    public CasaHabitacion(String tipo, int numHabit, double costoActual, double costoMax) {
        super(costoActual, costoMax);
        this.tipo = tipo;
        this.numHabit = numHabit;
    }
    public CasaHabitacion()
    {
        super();
        this.tipo = "Residencia";
        this.numHabit = 5;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public int getNumHabit() {
        return numHabit;
    }

    public void setNumHabit(int numHabit) {
        this.numHabit = numHabit;
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
        System.out.println("Tipo de casa: " + this.tipo);
        System.out.println("Numero de habitaciones: " + this.numHabit);
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
            double mtsRecom = mtsCuadrados / this.numHabit;
            mtsRecom *= habitRecom;
            
            System.out.println("Cantidad de habitaciones recomendadas: " + habitRecom); 
            System.out.println("Cantidad de metros recomendados: " + mtsRecom); 
        }else
            System.out.println("Cantidad de habitaciones adecuadas"); 
        
        
        return flag;        
    }
    
    
}
