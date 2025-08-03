import { Component } from '@angular/core';
import { ActivatedRoute, RouterModule } from '@angular/router';

@Component({
  selector: 'app-navbar',
  imports: [RouterModule],
  templateUrl: './navbar.component.html',
  styleUrl: './navbar.component.css'
})
export class NavbarComponent {
  usuario: string = "";

  constructor(public activatedRoute: ActivatedRoute){
    this.activatedRoute.params.subscribe(params => {
      this.usuario = params['user'];
    });
  }
  
  getRoutes(destino: string): any[]{
    return this.usuario !== undefined ? ["/" + this.usuario, destino] : ["/" + destino];
  }
}
