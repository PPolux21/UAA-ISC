/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package empleado;
import java.util.Date;
/**
 *
 * @author josel
 */
public class CEmpleado {
    protected String nombre;
    protected double salario;
    protected Date nacimeinto;

    public CEmpleado(String nombre, double salario, Date nacimeinto) {
        this.nombre = nombre;
        this.salario = salario;
        this.nacimeinto = nacimeinto;
    }
    
    public CEmpleado(CEmpleado persona)
    {
        this.nombre = persona.nombre;
        this.salario = persona.salario;
        this.nacimeinto = persona.nacimeinto;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public Date getNacimeinto() {
        return nacimeinto;
    }

    public void setNacimeinto(Date nacimeinto) {
        this.nacimeinto = nacimeinto;
    }

    @Override
    public String toString() {
        return "nombre=" + nombre + ", salario=" + salario + ", nacimeinto=" + nacimeinto.getDate() + "/" + (nacimeinto.getMonth()+1) + "/" + (nacimeinto.getYear()+1900);
    }
    
    
}
