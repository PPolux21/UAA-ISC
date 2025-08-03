import { Component } from '@angular/core';
import { GohanComponent } from '../gohan/gohan.component';
import { GotenComponent } from '../goten/goten.component';

@Component({
  selector: 'app-goku',
  imports: [GohanComponent,GotenComponent],
  templateUrl: './goku.component.html',
  styleUrl: './goku.component.css'
})
export class GokuComponent {
  enviarAGoten:string = "";
  
  mensajeParaGoten(mensaje:string){
    this.enviarAGoten = mensaje;
  }
}
