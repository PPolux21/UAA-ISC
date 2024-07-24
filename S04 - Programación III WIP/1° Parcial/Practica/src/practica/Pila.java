/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica;

import java.util.ArrayList;

/**
 *
 * @author josel
 */
public class Pila <T> {
    
    private ArrayList<T> array;

    public Pila() {
        this.array = new ArrayList<>();
    } 
    
    public void push(T elemento)
    {
        this.array.add(elemento);
    }
    
    public T pop()
    {
        T aux = this.array.get(this.array.size()-1);
        this.array.remove(this.array.size()-1);
        return aux;
    }
    
    public boolean isEmpty()
    {
        return this.array.isEmpty();
    }
    
    public int size()
    {
        return this.array.size();
    }
    
    public void mostrar()
    {
        for (int i = 0; i < this.array.size(); i++) {
            System.out.print("[" + this.array.get(i)+ "] ");
        }
        System.out.println();
    }
    
    public void sort()
    {
        
    }
}
