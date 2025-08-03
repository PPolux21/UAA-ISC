import { Component, Input } from '@angular/core';
import { Libro } from '../libro';
import { LibroService } from '../libro.service';

@Component({
  selector: 'app-libros',
  imports: [],
  templateUrl: './libros.component.html',
  styleUrl: './libros.component.css'
})
export class LibrosComponent {
  @Input() search:string ="";

  misLibros:Libro[] = [];

  constructor(public miservicio:LibroService){ }

  ngOnInit():void{
    this.misLibros = this.miservicio.getLibros();
  }

  ngOnChanges(){
    this.misLibros = this.miservicio.searchLibros(this.search);
  }
}
