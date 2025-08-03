import { Component } from '@angular/core';
import { Heroe } from '../heroe';
import { HeroeService } from '../shared/heroe.service';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-heroes',
  imports: [RouterModule],
  templateUrl: './heroes.component.html',
  styleUrl: './heroes.component.css'
})
export class HeroesComponent {

  misHeroes:Heroe[]=[];

  constructor(public miservicio: HeroeService){
    console.log("Constructor de heroes");
  }

  ngOnInit():void{
    console.log("ngOnInit de Heroes");
    this.misHeroes=this.miservicio.getHeroes();
    console.log(this.miservicio);
  }
}
