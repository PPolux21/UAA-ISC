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
public class CJefeDep extends CEmpleado {
    private String departamento;
    private double bonificacion;

    public CJefeDep(String nombre, double salario, Date nacimeinto, String departamento, double bonificacion) {
        super(nombre, salario, nacimeinto);
        this.departamento = departamento;
        this.bonificacion = bonificacion;
    }
    
    public CJefeDep(CEmpleado persona, String departamento, double bonificacion) {
        super(persona);
        this.departamento = departamento;
        this.bonificacion = bonificacion;
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public double getBonificacion() {
        return bonificacion;
    }

    public void setBonificacion(double bonificacion) {
        this.bonificacion = bonificacion;
    }

    @Override
    public String toString() {
        return super.toString() + ", departamento=" + departamento + ", bonificacion=" + bonificacion;
    }
    
    
    
    
}
