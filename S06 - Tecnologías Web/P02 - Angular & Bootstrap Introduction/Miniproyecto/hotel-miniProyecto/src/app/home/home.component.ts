import { Component } from '@angular/core';
import { MatExpansionModule } from '@angular/material/expansion';
import { DomseguroPipe } from '../pipes/domseguro.pipe';
import { FormBuilder, FormControl, FormGroup, FormsModule, ReactiveFormsModule, Validators } from '@angular/forms';
import { MatInputModule } from '@angular/material/input';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatCheckboxModule } from '@angular/material/checkbox';
import { MatSelectModule } from '@angular/material/select';
import { Room } from '../model/rooms';
import { RoomsServiceService } from '../services/rooms-service.service';
import { MatDatepickerModule } from '@angular/material/datepicker';
import { provideNativeDateAdapter } from '@angular/material/core';
import { MatButtonModule } from '@angular/material/button';
import Swal from 'sweetalert2';
import { SweetAlert2Module } from '@sweetalert2/ngx-sweetalert2';

@Component({
  selector: 'app-home',
  providers: [provideNativeDateAdapter()],
  imports: [MatExpansionModule, DomseguroPipe, MatInputModule, MatFormFieldModule, MatCheckboxModule, MatSelectModule, MatDatepickerModule, MatButtonModule, FormsModule, ReactiveFormsModule, SweetAlert2Module],
  templateUrl: './home.component.html',
  styleUrl: './home.component.css'
})
export class HomeComponent {
  preguntas = [
    {pregunta: "¿A qué hora es el check-in y check-out?", respuesta: "El check-in es a partir de las 3:00 PM y el check-out a las 12:00 PM."},
    {pregunta: "¿Se admiten mascotas?", respuesta: "No se admiten mascotas en el hotel."},
    {pregunta: "¿Cuál es el código de vestimenta de los restaurantes?", respuesta: "El código de vestimenta de los restaurantes es casual. Se permite pantalones o bermudas, camisas de vestir y sandalias formales. No está permitido el uso de ropa mojada, bañador ni chanclas"},
    {pregunta: "¿A qué distancia está el hotel del aeropuerto?", respuesta: "El hotel se encuentra a 15 minutos del Aeropuerto Internacional de Puerto Vallarta."},
    {pregunta: "¿Se puede fumar en las habitaciones?", respuesta: "No se puede fumar dentro de las habitaciones, ya que se le cobrará una sanción económica. Puede fumar en los espacios designados."},
    {pregunta: "¿Qué sucede si se presenta algún accidente en la piscina?", respuesta: "Dependiendo del nivel del accidente se realizarán acciones para mantener la integridad y la salud de las personas involucradas. En caso de algún daño al área de la piscina puede repercutir en una sanción económica."},
  ]
  videoCode:string = "0980RPeZUwg?playlist=0980RPeZUwg&loop=1&autoplay=1&mute=1&controls=0&showinfo=0";
  habitaciones!: Room[];
  subsForm: FormGroup;

  tomorrowOnwards = (d: Date | null): boolean => {
    if (!d) {
      return false;
    } 
    const today = new Date();
    const future = new Date(today);
    future.setDate(today.getDate() + 365);
    return (d >= today) && (d < future); 
  }

  nameControl:FormControl = new FormControl('', [Validators.required, Validators.maxLength(20)]);
  emailControl:FormControl = new FormControl('', [Validators.required, Validators.email]);
  enableRoomsControl:FormControl = new FormControl(false);
  roomsControl:FormControl = new FormControl({ value: '', disabled: true });
  enableDateControl:FormControl = new FormControl(false);
  dateStartControl:FormControl = new FormControl({ value: '', disabled: true });
  dateEndControl:FormControl = new FormControl({ value: '', disabled: true });

  constructor(public roomservice: RoomsServiceService, private fb: FormBuilder){
    this.subsForm = this.fb.group({
      nameField: this.nameControl,
      emailField: this.emailControl,
      enableRoomsField: this.enableRoomsControl,
      roomsField: this.roomsControl,
      enableDateField: this.enableDateControl,
      dateStartField: this.dateStartControl,
      dateEndField: this.dateEndControl
    });
  }

  ngOnInit(){
    this.habitaciones = this.roomservice.getRooms();

    this.enableRoomsControl.valueChanges.subscribe((checked: boolean) => {
      if (checked) {
        this.roomsControl.enable();
        this.roomsControl.setValidators([Validators.required]);
      } else {
        this.roomsControl.disable();
        this.roomsControl.clearValidators();
      }
      this.roomsControl.updateValueAndValidity();
    });
    this.enableDateControl.valueChanges.subscribe((checked: boolean) => {
      if (checked) {
        this.dateStartControl.enable();
        this.dateEndControl.enable();
        this.dateStartControl.setValidators([Validators.required]);
        this.dateEndControl.setValidators([Validators.required]);
      } else {
        this.dateStartControl.disable();
        this.dateEndControl.disable();
        this.dateStartControl.clearValidators();
        this.dateEndControl.clearValidators();
      }
      this.dateStartControl.updateValueAndValidity();
      this.dateEndControl.updateValueAndValidity();
    });
  }

  guardaInfo(){
    let myData = {
      name:this.nameControl.value,
      email:this.emailControl.value,
      room:this.roomsControl.value,
      start:this.dateStartControl.value.substring(0, 10),
      end:this.dateEndControl.value.substring(0, 10)
    };

    const existingDataString = localStorage.getItem('subsReactive');
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
    
    localStorage.setItem('subsReactive', JSON.stringify(existingData));

    Swal.fire({
      title: '¡Éxito!',
      text: 'Datos Registrados',
      icon: 'success',
      confirmButtonText: 'Aceptar'
    });
  }

}
