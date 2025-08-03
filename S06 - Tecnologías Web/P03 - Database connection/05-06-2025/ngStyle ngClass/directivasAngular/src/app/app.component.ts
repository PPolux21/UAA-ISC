import { CommonModule } from '@angular/common';
import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,CommonModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'directivasAngular';

  color:string="blue";
  fontSize:number=20;

  changeStyle():void{
    this.color = this.color === "blue" ? 'red' : 'blue';
    this.fontSize = this.fontSize === 20 ? 30 : 20;
  }

  isItalic:boolean=true;
  isHighlighted:boolean=false;

  toggleClass():void{
    this.isHighlighted = !this.isHighlighted;
    this.isItalic = !this.isItalic;
  }
}
