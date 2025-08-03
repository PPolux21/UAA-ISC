import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { CochesService } from './coches.service';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'apiBeeceptor';

  array:any = [];

  constructor(public servicioCochesAPI: CochesService) { }

  recuperarDatos():void{
    console.log("Estoy dentro");

    this.servicioCochesAPI.retornar().subscribe({
      next: this.successRequest.bind(this),
      error: (err) => {console.log(err)}
    });
  }

  successRequest(data:any){
    console.log(data);
    this.array = data.cars;
    console.log(this.array);
  }
}
