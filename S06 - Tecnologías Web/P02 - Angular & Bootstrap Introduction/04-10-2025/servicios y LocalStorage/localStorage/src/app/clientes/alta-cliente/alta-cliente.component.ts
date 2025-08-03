import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { Cliente, Grupo } from '../cliente.model';
import { ClientesService } from '../clientes.service';

@Component({
  selector: 'app-alta-cliente',
  imports: [FormsModule],
  templateUrl: './alta-cliente.component.html',
  styleUrl: './alta-cliente.component.css'
})
export class AltaClienteComponent {
  cliente!:Cliente;
  grupos!:Grupo[];

  constructor(private clientesService:ClientesService){}

  ngOnInit(){ 
    this.cliente = this.clientesService.nuevoCliente();
    this.grupos = this.clientesService.getGrupos();
  }

  nuevoCliente():void{
    this.clientesService.agregarClientes(this.cliente);
    this.cliente = this.clientesService.nuevoCliente();
  }
}
