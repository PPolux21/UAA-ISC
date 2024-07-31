/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package examen;

/**
 *
 * @author josel
 */
public abstract class BienInmueble {
    protected double costoActual;
    protected double costoMax;

    public BienInmueble(double costoActual, double costoMax) {
        this.costoActual = costoActual;
        this.costoMax = costoMax;
    }
    
    public BienInmueble()
    {
        this.costoActual = 10000;
        this.costoMax = 50000;
    }
    
    public BienInmueble(BienInmueble obj)
    {
        this.costoActual = obj.costoActual;
        this.costoMax = obj.costoMax;
    }

    public double getCostoActual() {
        return costoActual;
    }

    public void setCostoActual(double costoActual) {
        this.costoActual = costoActual;
    }

    public double getCostoMax() {
        return costoMax;
    }

    public void setCostoMax(double costoMax) {
        this.costoMax = costoMax;
    }
    
    
    abstract public void vender(double costoPorcent);
    abstract public void comprar(double costoPorcent);
    abstract public void imprimir();
    abstract public void mostrarDatos();
    
}
