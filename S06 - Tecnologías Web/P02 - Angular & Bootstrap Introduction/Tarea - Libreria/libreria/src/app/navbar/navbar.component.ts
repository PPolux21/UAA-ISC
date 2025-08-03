import { Component } from '@angular/core';
import { Router, RouterModule } from '@angular/router';

@Component({
  selector: 'app-navbar',
  imports: [RouterModule],
  templateUrl: './navbar.component.html',
  styleUrl: './navbar.component.css'
})
export class NavbarComponent {

  constructor(private router:Router) { }

  recargarPagina(event: Event): void {

    if (this.router.url !== '/cuenta'){
      event.preventDefault(); // Evita el comportamiento por defecto del <a>
      window.location.reload();
    }
  }
  
}
