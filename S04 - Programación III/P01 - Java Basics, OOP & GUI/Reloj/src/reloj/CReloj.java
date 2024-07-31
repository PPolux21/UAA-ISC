
package reloj;

/**
 *
 * @author josel
 */
public class CReloj {
    private int hh,mm,ss,bb;

    public CReloj(int hh, int mm, int ss) {
        this.hh = hh;
        this.mm = mm;
        this.ss = ss;
        this.bb = 100;
        
        if(this.ss >= 60)
        {
            this.mm += this.ss/60;
            this.ss += this.ss%60;
        }
        if(this.mm >= 60)
        {
            this.hh += this.mm/60;
            this.mm += this.mm%60;
        }
        if(this.hh >= 24)
            this.hh %= 24;
    }

    public int getHh() {
        return hh;
    }

    public void setHh(int hh) {
        this.hh = hh;
    }

    public int getMm() {
        return mm;
    }

    public void setMm(int mm) {
        this.mm = mm;
    }

    public int getSs() {
        return ss;
    }

    public void setSs(int ss) {
        this.ss = ss;
    }

    public int getBb() {
        return bb;
    }

    public void setBb(int bb) {
        this.bb = bb;
    }
    
    
    
    public void mostrar12H ()
    {        
        if(this.hh > 12)
        {
            System.out.println(this.hh%12 + ":" + this.mm%60 + ":" + this.ss%60 + " p.m.");
        }else{
            System.out.println(this.hh + ":" + this.mm%60 + ":" + this.ss%60 + " a.m.");
        }
        this.bb -= 1;
    }
    
    public void mostrar24H ()
    {
        System.out.println(this.hh%24 + ":" + this.mm%60 + ":" + this.ss%60);
        
        this.bb -= 1;
    }
    
    public void tic_tac()
    {
        System.out.println("tic tac . . .");
        this.bb -= 1;
    }
    
    public void avanza (int h, int m, int s)
    {
        this.hh = h;
        this.mm = m;
        this.ss = s;
        
        if(this.ss >= 60)
        {
            this.mm += this.ss/60;
            this.ss += this.ss%60;
        }
        if(this.mm >= 60)
        {
            this.hh += this.mm/60;
            this.mm += this.mm%60;
        }
        if(this.hh >= 24)
            this.hh %= 24;
        
        this.bb -= 3;
    }
    
    public void atrasa (int h, int m, int s)
    {
        this.hh = h;
        this.mm = m;
        this.ss = s;
        
        if(this.ss >= 60)
        {
            this.mm += this.ss/60;
            this.ss += this.ss%60;
        }
        if(this.mm >= 60)
        {
            this.hh += this.mm/60;
            this.mm += this.mm%60;
        }
        if(this.hh >= 24)
            this.hh %= 24;
        
        this.bb -= 3;
    }
    
    public boolean isStopped ()
    {
        return this.bb <= 0;
    }
    
    public void recargaBateria (int b)
    {
        if(this.bb <= 0)
        {
            this.bb = b;
        }else
        {
            this.bb += b;
        }
    }
    
    public void sincronizar (CReloj r)
    {
        this.hh = r.hh;
        this.mm = r.mm;
        this.ss = r.ss;
    }
}
