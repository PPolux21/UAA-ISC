import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { DomseguroPipe } from './domseguro.pipe';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, DomseguroPipe],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'pipeVideo';
  
  video:string = "fGTZtTE9-Do";
}
