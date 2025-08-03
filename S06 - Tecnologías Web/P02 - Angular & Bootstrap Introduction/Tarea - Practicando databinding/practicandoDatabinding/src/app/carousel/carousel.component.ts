import { Component } from '@angular/core';

@Component({
  selector: 'app-carousel',
  imports: [],
  templateUrl: './carousel.component.html',
  styleUrl: './carousel.component.css'
})
export class CarouselComponent {
  imagenHigh:string = "/monaco.jpg";

  cambiarImg(lugar:string){
    switch (lugar) {
      case 'monaco':
        this.imagenHigh = "/monaco.jpg";
        break;
      case 'suzuka':
        this.imagenHigh = "/suzuka.webp";
        break;
      case 'spa':
        this.imagenHigh = "/spa.jpg";
        break;
      default:
        break;
    }
  }
}
