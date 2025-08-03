import { Component, Input } from '@angular/core';

@Component({
  selector: 'app-candidato',
  imports: [],
  templateUrl: './candidato.component.html',
  styleUrl: './candidato.component.css'
})
export class CandidatoComponent {
  @Input() value:string="";
}
