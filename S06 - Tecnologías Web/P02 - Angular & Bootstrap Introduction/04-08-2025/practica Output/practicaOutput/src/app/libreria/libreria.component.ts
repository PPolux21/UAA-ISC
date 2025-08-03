import { Component } from '@angular/core';
import { FormLibroComponent } from '../form-libro/form-libro.component';

@Component({
  selector: 'app-libreria',
  imports: [FormLibroComponent],
  templateUrl: './libreria.component.html',
  styleUrl: './libreria.component.css'
})
export class LibreriaComponent {
  libros = [
    {titulo:'La sombra del viento', autor:'Carlos Ruiz Zafón'}
  ];

  agregarLibro(libro: {titulo:string; autor:string}){
    this.libros.push(libro);
  }
}
