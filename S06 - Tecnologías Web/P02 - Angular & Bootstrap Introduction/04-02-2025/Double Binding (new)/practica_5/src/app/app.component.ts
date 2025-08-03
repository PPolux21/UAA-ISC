import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,FormsModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'practica_5';
  n1!: number;
  n2!: number;
  resultado!: number;
  op: string = "";

  ejecutar(): void {
      this.op = this.op.trim();

      switch (this.op) {
          case '+': this.resultado = this.n1 + this.n2; break;
          case '-': this.resultado = this.n1 - this.n2; break;
          case '*': this.resultado = this.n1 * this.n2; break;
          default:
              this.resultado = 0;
              alert('error en el operador');
      }
  }

  limpiar(): void {
      this.n1 = 0;
      this.n2 = 0;
      this.op = "";
      this.resultado = 0;
  }
}
