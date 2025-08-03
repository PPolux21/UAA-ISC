import { Injectable } from '@angular/core';
import { GRUPOS } from '../grupo';
import { Cliente, Grupo } from './cliente.model';

@Injectable({
  providedIn: 'root'
})
export class ClientesService {

  clientes!:Cliente[];
  grupo:Grupo[] = GRUPOS;

  constructor() { 
    this.clientes = JSON.parse(localStorage.getItem("data") || "[]");
  }

  getGrupos(){
    return this.grupo;
  }

  getClientes(){
    return this.clientes;
  }

  agregarClientes(cliente: Cliente){
    this.clientes.push(cliente);
    localStorage.setItem('data',JSON.stringify(this.clientes)); 
  }

  nuevoCliente():Cliente{
    return {
      id: this.clientes.length,
      nombre: '',
      cif: '',
      dierccion:'',
      grupo: 0,
    };
  }
}
