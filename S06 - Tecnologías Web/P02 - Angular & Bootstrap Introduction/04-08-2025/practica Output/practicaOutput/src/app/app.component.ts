import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { LibreriaComponent } from './libreria/libreria.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, LibreriaComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'practicaOutput';
}
