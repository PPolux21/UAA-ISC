/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package setConection;

import java.sql.*;

/**
 *
 * @author luisa
 */
public class Conexion {
    //En la siguiente linea debes reemplazar la ubicación de la DB de tu PC
    String strConexionDB="jdbc:sqlite:data_base/InventarioDB.s3db";
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
    
    public void close(){
        try {
            conn.close();
            System.out.println("Conexion finalizada");
        } catch (SQLException e) {
            System.out.println("Error al cerrar la conexion");;
        }
    }

}
