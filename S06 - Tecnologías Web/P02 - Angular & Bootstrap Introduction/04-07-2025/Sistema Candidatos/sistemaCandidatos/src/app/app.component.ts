import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { CandidatoComponent } from './components/candidato/candidato.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, CandidatoComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'sistemaCandidatos';

   candidatos:string[] = [];

   constructor(){
    this.candidatos[0] = "José Espinoza";
    this.candidatos[1] = "Luis Sánchez";
    this.candidatos[2] = "Juan Pérez"
   }
}
