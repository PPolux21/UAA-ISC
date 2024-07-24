
package reloj;

/**
 *
 * @author josel
 */
public class Reloj {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       
        CReloj reloj = new CReloj(15,56,10);
        
        reloj.mostrar24H();
        reloj.mostrar12H();
        
        reloj.tic_tac();
        
       
    }
    
}
