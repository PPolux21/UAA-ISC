import { Component, Input } from '@angular/core';

@Component({
  selector: 'app-goten',
  imports: [],
  templateUrl: './goten.component.html',
  styleUrl: './goten.component.css'
})
export class GotenComponent {
  @Input() mensajeGoten!:string;
}
