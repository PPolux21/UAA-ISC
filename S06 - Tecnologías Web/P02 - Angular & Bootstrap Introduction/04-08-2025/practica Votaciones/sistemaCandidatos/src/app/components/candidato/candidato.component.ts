import { Component, EventEmitter, Input, Output } from '@angular/core';

@Component({
  selector: 'app-candidato',
  imports: [],
  templateUrl: './candidato.component.html',
  styleUrl: './candidato.component.css'
})
export class CandidatoComponent {
  @Input() value:string="";
  @Output() votoRegistrado = new EventEmitter<{value:string}>();

  enviarCandidato(){
    this.votoRegistrado.emit({value: this.value});
  }
}
