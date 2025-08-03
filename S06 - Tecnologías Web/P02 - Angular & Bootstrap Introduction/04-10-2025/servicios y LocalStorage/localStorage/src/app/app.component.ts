import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { AltaClienteComponent } from './clientes/alta-cliente/alta-cliente.component';
import { ListadoClientesComponent } from './clientes/listado-clientes/listado-clientes.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,AltaClienteComponent,ListadoClientesComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'localStorage';
}
