import { CommonModule } from '@angular/common';
import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import 'animate.css'

@Component({
  selector: 'app-header',
  imports: [CommonModule],
  templateUrl: './header.component.html',
  styleUrl: './header.component.css'
})
export class HeaderComponent {
  usernames = ["Jose Luis", "Luis Alberto", "Brandon"];
  userString: string = "";
  nombreUsuario: string = "";
  userIndex!: number;
  iconLogged: boolean = false;

  constructor(private router: Router, public activatedRoute: ActivatedRoute){
    this.activatedRoute.params.subscribe(params => {
      this.userString = params['user'];
      if(!this.userString){
        this.nombreUsuario = "Iniciar Sesión";
      }else{
        this.userIndex = parseInt(this.userString.replace(/\D/g, ''), 10);
        this.nombreUsuario = this.usernames[this.userIndex];
        this.iconLogged = true;
      }
    });
  }

  toLogin(){
    if(!this.iconLogged){
      this.router.navigate(['/login']);
    }else{
      this.router.navigate(['/' + this.userString + '/admincontrol']);
    }
  }
}
