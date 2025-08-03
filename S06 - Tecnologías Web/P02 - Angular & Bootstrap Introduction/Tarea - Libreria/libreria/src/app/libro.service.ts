import { Injectable } from '@angular/core';
import { Libro } from './libro';
import { LIBROS } from './mislibros';

@Injectable({
  providedIn: 'root'
})
export class LibroService {

  private libros:Libro[] = LIBROS

  constructor() { }

  getLibros():Libro[] {
    return this.libros;
  }

  searchLibros(busqueda:string):Libro[]{
    let resultado = this.libros.filter(item =>
      item.title.toLowerCase().includes(busqueda) ||
      item.author.toLowerCase().includes(busqueda)
    );

    return resultado;
  }
}
