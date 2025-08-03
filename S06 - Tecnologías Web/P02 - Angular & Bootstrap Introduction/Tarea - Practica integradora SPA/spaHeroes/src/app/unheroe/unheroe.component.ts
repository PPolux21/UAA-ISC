import { Component, Input } from '@angular/core';
import { Heroe } from '../heroe';
import { HeroeService } from '../shared/heroe.service';
import { ActivatedRoute, RouterModule } from '@angular/router';

@Component({
  selector: 'app-unheroe',
  imports: [RouterModule],
  templateUrl: './unheroe.component.html',
  styleUrl: './unheroe.component.css'
})
export class UnheroeComponent {
  @Input() heroe!:Heroe;
  
  constructor(public heroeService:HeroeService, public activaredRoute: ActivatedRoute){
    this.activaredRoute.params.subscribe(params => {
      this.heroe = heroeService.getUnHeroe(params['id']);
    });
  }
}
