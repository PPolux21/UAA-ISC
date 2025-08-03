import { CurrencyPipe, DatePipe, JsonPipe, LowerCasePipe, SlicePipe, UpperCasePipe } from '@angular/common';
import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, DatePipe, JsonPipe, SlicePipe, CurrencyPipe, LowerCasePipe, UpperCasePipe],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'pipesAngular';

  nombre = 'Juan Carlos';
  saldo = 1000.50;
  dias = ['domingo','lunes','martes','miércoles','jueves','viernes','sábado'];
  articulos = [{
      codigo: 1,
      descripcion: "papas",
      precio: 12.33
    },{
      codigo: 2,
      descripcion: "manzanas",
      precio: 54
    }];
  fechaActual = new Date();
}
