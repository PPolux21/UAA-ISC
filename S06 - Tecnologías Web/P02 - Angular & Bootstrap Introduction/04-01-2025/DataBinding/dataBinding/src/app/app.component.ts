import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { usuario } from '../modelo/usuario';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'dataBinding';

  user1: usuario = {
    nombre: "Kirby",
    apellido: "Estrella",
    telefono: "456-6548-135",
    correo: "kirby@popstar.com",
    image: "image/kirby.webp"
  };
  user2: usuario = {
    nombre: "Waddle",
    apellido: "Dee Marcha",
    telefono: "513-1563-134",
    correo: "waddle.dee@popstar.com",
    image: "image/waddle_dee.png"
  };
  user3: usuario = {
    nombre: "King",
    apellido: "Dedede Realhammer",
    telefono: "784-4561-777",
    correo: "kingdedede@castle.com",
    image: "image/king_dedede.webp"
  };
}
