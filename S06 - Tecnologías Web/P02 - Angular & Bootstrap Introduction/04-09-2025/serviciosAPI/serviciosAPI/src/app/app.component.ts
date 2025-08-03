import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { ServicioAPIService } from './servicio-api.service';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'serviciosAPI';

  array:any = [];

  constructor(public servicioAPIService: ServicioAPIService){ }

  recuperarDatos():void{
    console.log("Estoy dentro");

    this.servicioAPIService.retornar().subscribe({
      next: this.successRequest.bind(this),
      error: (err) => {console.log(err)}
    });
  }

  successRequest(data:any){
    console.log(data);
    this.array = data.datos;
    console.log(this.array);
  }
}
