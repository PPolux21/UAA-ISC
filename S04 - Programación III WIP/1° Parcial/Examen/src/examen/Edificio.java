/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package examen;

/**
 *
 * @author josel
 */
public class Edificio extends BienInmueble implements Comercial{
    
    private int cantPisos;
    private String tipoSuelo;

    public Edificio(int cantPisos, String tipoSuelo, double costoActual, double costoMax) {
        super(costoActual, costoMax);
        this.cantPisos = cantPisos;
        this.tipoSuelo = tipoSuelo;
    }
    
    public Edificio()
    {
        super();
        this.cantPisos = 5;
        this.tipoSuelo = "Residencial";        
    }
    
    public Edificio(Edificio obj)
    {
        super(obj.costoActual,obj.costoMax);
        this.cantPisos = obj.cantPisos;
        this.tipoSuelo = obj.tipoSuelo;
    }

    public int getCantPisos() {
        return cantPisos;
    }

    public void setCantPisos(int cantPisos) {
        this.cantPisos = cantPisos;
    }

    public String getTipoSuelo() {
        return tipoSuelo;
    }

    public void setTipoSuelo(String tipoSuelo) {
        this.tipoSuelo = tipoSuelo;
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
        System.out.println("Tipo de suelo: " + this.tipoSuelo);
        System.out.println("Cantidad de pisos: " + this.cantPisos);
        System.out.println("Costo actual: " + this.costoActual);
    }
    

    @Override
    public int calcularNumeroComercios(int personas, int locales) {
        return personas/locales;
    }
    
    
}
