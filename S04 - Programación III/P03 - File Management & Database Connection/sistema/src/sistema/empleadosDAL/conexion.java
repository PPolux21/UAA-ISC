/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistema.empleadosDAL;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
/**
 *
 * @author TUA
 */
public class conexion {
                        //jdbc:sqlite:C:/Users/TUA/Documents/BaseDatos/Agenda4B.s3db
    String strConexionDB="jdbc:sqlite:C:/Users/josel/OneDrive/Documentos/SQLite/Agendas.s3db";
    Connection conn=null; //Clase par hacer la conexión

    public conexion() {
        try {
            Class.forName("org.sqlite.JDBC");//Driver para hacer la conexión
            conn=DriverManager.getConnection(strConexionDB);//DriverManager manipular la conexión
            System.out.println("Conexion establecida");
        } catch (Exception e) {
            System.out.println("Error de conexion a la BD"+e);
        }
    }
    //Agregar driver sqlite-jdbc a la carpeta de librerias de este proyecto
    //revisar que la conexión se establecio.
    //en el main generar un objeto de tipo conexion.
   public int ejecutarSentenciaSQL(String strSentenciaSQL){
        try {
            PreparedStatement pstm=conn.prepareStatement(strSentenciaSQL);
            pstm.execute();
            return 1;
        } catch (SQLException e) {//excepción de las sentenias SQL.
            System.out.println("Error de insercion de los datos "+e);
            return 0;
        }
    }
    
    public ResultSet consultarRegistro(String strSentenciaSQL){
        try {
            PreparedStatement pstm=conn.prepareStatement(strSentenciaSQL);
            ResultSet respuesta=pstm.executeQuery();
            return respuesta;
        } catch (SQLException e) {
            System.out.println("Error de Query "+e);
            return null;
        }   
    }
}
