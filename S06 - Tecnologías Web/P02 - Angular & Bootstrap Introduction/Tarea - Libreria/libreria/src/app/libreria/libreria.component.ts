import { Component } from '@angular/core';
import { CarouselComponent } from '../carousel/carousel.component';
import { SearchComponent } from '../search/search.component';
import { LibrosComponent } from '../libros/libros.component';

@Component({
  selector: 'app-libreria',
  imports: [CarouselComponent, SearchComponent, LibrosComponent],
  templateUrl: './libreria.component.html',
  styleUrl: './libreria.component.css'
})
export class LibreriaComponent {

  busqueda:string = "";

  updateBusqueda(texto:string){
    this.busqueda = texto;
  }
}
