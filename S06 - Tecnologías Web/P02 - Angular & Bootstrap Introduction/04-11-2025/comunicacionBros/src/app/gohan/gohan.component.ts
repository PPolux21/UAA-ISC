import { Component, EventEmitter, Output } from '@angular/core';

@Component({
  selector: 'app-gohan',
  imports: [],
  templateUrl: './gohan.component.html',
  styleUrl: './gohan.component.css'
})
export class GohanComponent {
  @Output() mensajeDesdeGohan = new EventEmitter<string>();

  enviarMensaje(mensaje:string){
    this.mensajeDesdeGohan.emit(mensaje);
  }
}
