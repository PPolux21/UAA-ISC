import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { DadoComponent } from './componets/dado/dado.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,DadoComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'juegoAzar';
  valor1:number;
  valor2:number;
  valor3:number;
  resultado:string="";
  constructor(){
    this.valor1 = this.retornarAleatorio();
    this.valor2 = this.retornarAleatorio();
    this.valor3 = this.retornarAleatorio();
  }

  retornarAleatorio(){
    return Math.trunc(Math.random()*6)+1;
  }

  sleep(ms: number): Promise<void> {
    return new Promise(resolve => setTimeout(resolve, ms));
  }

  async tirar(){
    const intervalId = setInterval(() => {
      this.valor1 = this.retornarAleatorio();
      this.valor2 = this.retornarAleatorio();
      this.valor3 = this.retornarAleatorio();
    }, 70);

    await this.sleep(3000);
    clearInterval(intervalId);

    this.valor1 = this.retornarAleatorio();
    this.valor2 = this.retornarAleatorio();
    this.valor3 = this.retornarAleatorio();
    if (this.valor1==this.valor2 && this.valor1==this.valor3) {
      this.resultado="Ganó";
    } else {
      this.resultado="Perdió";
    }
  }
}
