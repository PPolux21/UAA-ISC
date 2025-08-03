import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { GokuComponent } from './goku/goku.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, GokuComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'comunicacionBros';
}
