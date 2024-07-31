/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package conexion;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author josel
 */
public class Conexion {
    
    String strConexionDB="jdbc:sqlite:C:/Users/josel/OneDrive/Documentos/NetBeansProjects/JoseLuisEspinozaSanchez/dataBase/actividades.s3db";
    Connection conn=null;    //clase para hacer la conexion
    
    public Conexion(){
        try{
            Class.forName("org.sqlite.JDBC");   //driver para hacer la conexion
            conn=DriverManager.getConnection(strConexionDB);    //DriverManager manipular
            System.out.println("Conexion establecida");
        }catch(Exception e){
            System.out.println("Error de conexion a la BD"+e);
        }
    }
    
    public int ejecutarSentenciaSQL(String strSentenciaSQL){
        try{
            PreparedStatement pstm = conn.prepareStatement(strSentenciaSQL);
            pstm.execute();
            return 1;
        }catch(SQLException e){ //excepcion de las sentencias SQL
            System.out.println("Error de insercion de los datos "+e);
            return 0;
        }
    }
    
    public ResultSet consultarRegistro(String strSentenciaSQL){
        try{
            PreparedStatement pstm = conn.prepareStatement(strSentenciaSQL);
            ResultSet respuesta = pstm.executeQuery();
            return respuesta;
        }catch(SQLException e){
            System.out.println("Error de Query "+e);
            return null;
        }
    }
}
