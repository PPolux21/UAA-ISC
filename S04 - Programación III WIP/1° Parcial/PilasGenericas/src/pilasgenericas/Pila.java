/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pilasgenericas;

import java.util.ArrayList;

/**
 *
 * @author josel
 */
public class Pila<E> {
    
    private ArrayList<E> pila;

    public Pila() {
        pila = new ArrayList<>();
    }

    public Pila(ArrayList<E> pila) {
        this.pila = pila;
    }
    
    public void push(E s)
    {
        pila.add(s);
    }
    
    public E pop()
    {
        E aux = pila.getLast();
        pila.remove(pila.size()-1);
        return aux;
    }
    
    
}
