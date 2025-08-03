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
   result:string = "";

   voto1Candidato:number = 0;
   voto2Candidato:number = 0;
   voto3Candidato:number = 0;


   constructor(){
    this.candidatos[0] = "José Espinoza";
    this.candidatos[1] = "Luis Sánchez";
    this.candidatos[2] = "Juan Pérez"
   }

   sumaVoto(candidato: {value:string}){
    if (candidato.value === this.candidatos[0]) {
      this.voto1Candidato++;
    }
    if (candidato.value === this.candidatos[1]) {
      this.voto2Candidato++;
    }
    if (candidato.value === this.candidatos[2]) {
      this.voto3Candidato++;
    }
   }

   finishVoting() {
    if (this.voto1Candidato === 0 && this.voto2Candidato === 0 && this.voto3Candidato === 0) {
      this.result = 'No se ha registrado ningún voto.';
      return;
    }
  
    const maxVotes = Math.max(this.voto1Candidato, this.voto2Candidato, this.voto3Candidato);
  
    let winners: string = '';
    let countWinners = 0;
  
    if (this.voto1Candidato === maxVotes) {
      winners += (countWinners > 0 ? ', ' : '') + this.candidatos[0]; 
      countWinners++;
    }
  
    if (this.voto2Candidato === maxVotes) {
      winners += (countWinners > 0 ? ', ' : '') + this.candidatos[1];
      countWinners++;
    }
  
    if (this.voto3Candidato === maxVotes) {
      winners += (countWinners > 0 ? ', ' : '') + this.candidatos[2];
      countWinners++;
    }
  
    if (countWinners > 1) {
      this.result = `Empate entre: ${winners} con ${maxVotes} votos cada uno.`;
    } else {
      this.result = `El ganador es ${winners} con ${maxVotes} votos!`;
    }
  }
}
