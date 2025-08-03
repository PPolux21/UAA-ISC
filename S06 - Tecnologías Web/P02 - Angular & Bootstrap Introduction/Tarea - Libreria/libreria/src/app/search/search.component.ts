import { Component, EventEmitter, Output } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-search',
  imports: [FormsModule],
  templateUrl: './search.component.html',
  styleUrl: './search.component.css'
})
export class SearchComponent {
  busqueda:string = "";

  @Output() busquedaEvent = new EventEmitter<string>();

  emitirBusqueda(){
    this.busquedaEvent.emit(this.busqueda)
  }
}
