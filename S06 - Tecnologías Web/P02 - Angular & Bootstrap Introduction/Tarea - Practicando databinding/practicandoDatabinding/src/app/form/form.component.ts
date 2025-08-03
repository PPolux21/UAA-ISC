import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import Swal from 'sweetalert2'

@Component({
  selector: 'app-form',
  imports: [FormsModule],
  templateUrl: './form.component.html',
  styleUrl: './form.component.css'
})
export class FormComponent {
  huespedNum:number =1;
  nochesNum:number=1;
  extras = [
    { nombre: "+ Mascota $250 MXN", precio: 250, marcado: false },
    { nombre: "+ Calefacción $500 MXN", precio: 500, marcado: false },
    { nombre: "+ Ruta de Montañas $150 MXN", precio: 150, marcado: false },
    { nombre: "+ Senderismo $200 MXN", precio: 200, marcado: false },
    { nombre: "+ Visita la cascada $50 MXN", precio: 50, marcado: false }
  ];  
  total:number=1500;

  menosHuesped(){
    if (this.huespedNum>1) {
      this.huespedNum--;
      this.total-=500;
    }
  }

  masHuesped(){
    this.huespedNum++;
    this.total+=500;
  }

  menosNoche(){
    if (this.nochesNum>1) {
      this.nochesNum--;
      this.total-=1000;
    }
  }

  masNoche(){
    this.nochesNum++;
    this.total+=1000;
  }

  extraAction(action:string){
    for (let i = 0; i < this.extras.length; i++) {
      if (this.extras[i].nombre == action) {
        if (this.extras[i].marcado) {
          this.total -= this.extras[i].precio; 
        }else{
          this.total += this.extras[i].precio; 
        }
      }
    }
  }

  reserv(){
    Swal.fire({
      title: 'Reservación exitosa',
      html: 'Reservación para <strong>' + this.huespedNum + '</strong> huesped(es) ' +
        'y <strong>' + this.nochesNum + '</strong> noche(s). <br>' + 'Costo total: <strong>$' + this.total + '.00 MXN</strong>.',
      icon: 'success',
      confirmButtonText: 'Okay'
    })
    this.huespedNum = 1;
    this.nochesNum = 1;
    this.total = 1500;
    for (let i = 0; i < this.extras.length; i++) {
      this.extras[i].marcado = false;
    }
  }
}
