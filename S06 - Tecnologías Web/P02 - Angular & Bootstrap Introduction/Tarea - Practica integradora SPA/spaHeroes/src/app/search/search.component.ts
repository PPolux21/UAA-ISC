import { Component } from '@angular/core';
import { UnheroeComponent } from '../unheroe/unheroe.component';
import { Heroe } from '../heroe';
import { HeroeService } from '../shared/heroe.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-search',
  imports: [UnheroeComponent],
  templateUrl: './search.component.html',
  styleUrl: './search.component.css'
})
export class SearchComponent {

  nombreh:string="";
  indice:number=0;

  miHeroe:Heroe={
    nombre:"",
    bio:"",
    img:"",
    aparicion:"",
    casa:""
  };

  constructor(private heroeService: HeroeService, private acticatedRoute: ActivatedRoute){
    this.acticatedRoute.params.subscribe(params => {
      this.nombreh=params['nombre'];
      this.indice=this.heroeService.searchUnHeroe(this.nombreh);
      console.log(this.indice);

      if(this.indice != -1){
        this.miHeroe=this.heroeService.getUnHeroe(this.indice);
      }
    });
  }
}
