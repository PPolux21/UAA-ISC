/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package set_get_data;

/**
 *
 * @author luisa
 */
public class Data_information {
    long codigo_barras;
    String nombre, marca, tipo, fecha;
    double precio;
    int stock, ventasDia, ventasMes, descuento;

    public int getDescuento() {
        return descuento;
    }

    public void setDescuento(int descuento) {
        this.descuento = descuento;
    }

    public long getCodigo_barras() {
        return codigo_barras;
    }

    public void setCodigo_barras(long codigo_barras) {
        this.codigo_barras = codigo_barras;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }
    
    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public int getVentasDia() {
        return ventasDia;
    }

    public void setVentasDia(int ventasDia) {
        this.ventasDia = ventasDia;
    }

    public int getVentasMes() {
        return ventasMes;
    }

    public void setVentasMes(int ventasMes) {
        this.ventasMes = ventasMes;
    }
    
    
}
