import { Component } from '@angular/core';
import { profesores } from '../../../modelo/profesores';

@Component({
  selector: 'app-cards',
  imports: [],
  templateUrl: './cards.component.html',
  styleUrl: './cards.component.css'
})
export class CardsComponent {
  profe1:profesores ={
    nombre: "Laura Hernández García",
    especializacion: "Inteligencia Artificial",
    materia: "Aprendizaje Automático",
    imagen: "/profe_1.jpeg",
  };

  profe2:profesores ={
    nombre: "Carlos Méndez Torres",
    especializacion: "Redes de Computadoras",
    materia: "Administración de Redes",
    imagen: "/profe_2.jpg",
  };

  profe3:profesores ={
    nombre: "Javier Ramírez López",
    especializacion: "Bases de Datos",
    materia: "Diseño de Bases de Datos",
    imagen: "/profe_3.webp",
  };

  profe4:profesores ={
    nombre: "María Fernanda Soto",
    especializacion: "Desarrollo Web",
    materia: "Programación Frontend",
    imagen: "/profe_4.jpg",
  };
}
