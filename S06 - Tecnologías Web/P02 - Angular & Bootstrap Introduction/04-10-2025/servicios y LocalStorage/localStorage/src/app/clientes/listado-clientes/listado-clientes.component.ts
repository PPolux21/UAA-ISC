import { Component } from '@angular/core';
import { Cliente } from '../cliente.model';
import { ClientesService } from '../clientes.service';

@Component({
  selector: 'app-listado-clientes',
  imports: [],
  templateUrl: './listado-clientes.component.html',
  styleUrl: './listado-clientes.component.css'
})
export class ListadoClientesComponent {
  clientes!:Cliente[];

  constructor(private clientesService: ClientesService){}

  ngOnInit(){
    this.clientes = this.clientesService.getClientes();
  }
}
