/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tarea2_4c;

/**
 *
 * @author josel
 */
public class CuentaAhorroJr {
    private double saldo;
    public static int maximo = 50000;

    public CuentaAhorroJr(double saldo) {
        this.saldo = saldo;
    }
    
    //metodos set y get

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }    
    
    public void deposito(double cantidad){ // no superar la capacidad
        if(this.saldo < CuentaAhorroJr.maximo)
        {
            if((this.saldo + cantidad) <= CuentaAhorroJr.maximo)
            {
                this.saldo += cantidad;
                System.out.println("Deposito completado, cantidad actual de saldo: " + this.saldo);
            }else{
                System.out.println("Transaccion no completada, cantidad supera el maximo !!!");
            }
        }else{
            System.out.println("Transaccion fallida, el saldo ha llegado al tope maximo !!!");
        }
    }
    
    public void retiro(double cantidad){ // no sacar más de lo que hay
        if(this.saldo > 0)
        {
            if(this.saldo >= cantidad)
            {
                this.saldo -= cantidad;
                System.out.println("Retiro completado, cantidad actual de saldo: " + this.saldo);
            }else{
                System.out.println("Transaccion no completada, cantidad insuficiente de saldo !!!");
            }
        }else{
            System.out.println("Transaccion fallida, saldo es 0 !!!");
        }
    }
    
    public void sacaMitad()
    {
        if(this.saldo > 0)
        {
            this.saldo /= 2;
            System.out.println("Retiro completado, cantidad actual de saldo: " + this.saldo);
        }
    }
}
