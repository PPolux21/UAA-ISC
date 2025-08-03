import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { ReactiveFormsModule } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import Swal from 'sweetalert2';

@Component({
  selector: 'app-reservation',
  imports: [FormsModule,ReactiveFormsModule],
  templateUrl: './reservation.component.html',
  styleUrl: './reservation.component.css'
})
export class ReservationComponent {
  imagenHabitacion: string | null = null;
  opcionHabitacion: number = -1;

  templateData = {
    nombre: '',
    tipo: '',
    noches: null,
    personas: 1,
    fecha: '',
    extras: {} as { [nombre: string]: boolean }
  };

  serviciosExtras = [
    { nombre: 'Desayuno', precio: 100 },
    { nombre: 'Acceso al spa', precio: 200 },
    { nombre: 'Estacionamiento privado', precio: 50 },
    { nombre: 'Transporte al aeropuerto', precio: 300 },
    { nombre: 'Cena romántica', precio: 400 }
  ];

  tiposHabitacion = [
    { nombre: 'Estándar King', precio: 500, imagen: '/img/Estandar King.jpg' },
    { nombre: 'Estándar Doble', precio: 800, imagen: '/img/Estandar Doble.jpg' },
    { nombre: 'Estándar King con Terraza', precio: 1500, imagen: '/img/Estandar King con Terraza.jpg' },
    { nombre: 'Estándar Doble con Terraza', precio: 1000, imagen: '/img/Estandar Doble con Terraza.jpg' },
    { nombre: 'King vista al mar', precio: 2000, imagen: '/img/King Vista al Mar.jpg' },
    { nombre: 'Doble vista al mar', precio: 3500, imagen: '/img/Doble vista al mar.jpg' },
    { nombre: 'Golden Vista Frontal al Mar', precio: 4000, imagen: '/img/Golden Vista Frontal al Mar.jpg' }
  ];

  constructor(public activatedRoute: ActivatedRoute){
    for (const servicio of this.serviciosExtras) {
      this.templateData.extras[servicio.nombre] = false;
    }

    this.activatedRoute.params.subscribe(params => {
      this.opcionHabitacion = params['room'];
      if(this.opcionHabitacion == undefined){ 
        this.opcionHabitacion = -1 
      }else{
        this.templateData.tipo = this.tiposHabitacion[this.opcionHabitacion].nombre;
      }
    });
  }

  guardarTemplate() {
    let myData = this.templateData;

    const existingDataString = localStorage.getItem('reservacionTemplate');
    let existingData: any[] = [];
    if (existingDataString) {
      try {
        existingData = JSON.parse(existingDataString);
        if (!Array.isArray(existingData)) {
          existingData = [];
        }
      } catch {
        existingData = [];
      }
    }

    existingData.push(myData);

    localStorage.setItem('reservacionTemplate', JSON.stringify(existingData));
    Swal.fire('¡Reservación registrada!', 'Los datos se guardaron correctamente', 'success');
  }

  fechaInvalida(): boolean {
    if (!this.templateData.fecha) return false;
    const hoy = new Date();
    const fechaIngresada = new Date(this.templateData.fecha);
    return fechaIngresada < new Date(hoy.toDateString());
  }

  fechaLejana():boolean {
    if (!this.templateData.fecha) return false;
    const fechaFutura = new Date();
    fechaFutura.setDate(fechaFutura.getDate() + 365);
    const fechaIngresada = new Date(this.templateData.fecha);
    return fechaIngresada > new Date(fechaFutura.toDateString());
  }

  actualizarImagen() {
    const tipo = this.tiposHabitacion.find(t => t.nombre === this.templateData.tipo);
    this.imagenHabitacion = tipo ? tipo.imagen : null;
  }

  get totalEstimado(): number {
    const noches = this.templateData.noches ?? 0;
    const habitacion = this.tiposHabitacion.find(t => t.nombre === this.templateData.tipo);
    if (!habitacion) return 0;

    let total = habitacion.precio * noches;

    if (this.templateData.personas >= 2) {
      total += (this.templateData.personas - 2) * 500; 
    }

    for (const extra of this.serviciosExtras) {
      if (this.templateData.extras[extra.nombre]) {
        total += extra.precio * noches;
      }
    }

    return total;
  }
  
}
