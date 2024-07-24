/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package empleado;
import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author josel
 */
public class Empleado {

    /**
     * @param args the command line arguments
     */
    static Scanner in = new Scanner(System.in);
    
    public static void main(String[] args) {
        String nombre,dep;
        double salario,bonno;
        int anno, mes, dia;
        Date nacimiento = new Date();
        
        System.out.print("Introduce tu nombre: ");
        nombre = in.nextLine();
        
        System.out.print("Introduce tu salario: ");
        salario = in.nextDouble();
        
        System.out.println("Introduce tu fecha de nacimiento: ");
        System.out.print("\tAño: ");
        anno = in.nextInt();
        System.out.print("\tMes: ");
        mes = in.nextInt();
        System.out.print("\tDia: ");
        dia = in.nextInt();
        
        nacimiento.setYear(anno-1900);
        nacimiento.setMonth(mes-1);
        nacimiento.setDate(dia);
        
        CEmpleado persona1 = new CEmpleado(nombre,salario,nacimiento);
        
        System.out.println(persona1.toString());
        
        in.nextLine();
        
        System.out.print("Introduce tu Departamento: ");
        dep = in.nextLine();
        
        System.out.print("Introduce tu bonificacion del salario: ");
        bonno = in.nextDouble();
        
        CJefeDep jefe1 = new CJefeDep(persona1, dep, bonno);
        
        System.out.println(jefe1.toString());
        
        CEmpleado vec []= new CEmpleado[3];
        
        vec[0] = new CEmpleado("wenas",5000,new Date());
        vec[1] = new CJefeDep("Sip",5000,new Date(),"RRHH",500);
        vec[2] = new CJefeDep(new CEmpleado("Rodrigo",5999,new Date()), "Torre", 800);
        
        for(CEmpleado x : vec)
        {
            System.out.println(x.toString());
        }
        
        
        
    }
    
}
