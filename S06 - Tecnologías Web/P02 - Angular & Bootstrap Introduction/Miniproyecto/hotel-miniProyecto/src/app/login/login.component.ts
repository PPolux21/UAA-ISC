import { Component, signal } from '@angular/core';
import { FormBuilder, FormControl, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { MatButtonModule } from '@angular/material/button';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatIconModule } from '@angular/material/icon';
import { MatInputModule } from '@angular/material/input';
import { Router } from '@angular/router';
import { SweetAlert2Module } from '@sweetalert2/ngx-sweetalert2';
import Swal from 'sweetalert2';

@Component({
  selector: 'app-login',
  imports: [MatButtonModule, MatFormFieldModule, MatInputModule, MatIconModule, ReactiveFormsModule, SweetAlert2Module],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})
export class LoginComponent {
  form: FormGroup;
  readonly email = new FormControl('', [Validators.required, Validators.email]);

  errorMessage = signal('');
  hide = signal(true);

  admins = [
    {
      email: 'jose_luis@tresvagos.com',
      password: 'wenas'
    },
   {
      email: 'luis_alberto@tresvagos.com',
      password: 'wenas'
    },
    {
      email: 'brandon@tresvagos.com',
      password: 'wenas'
    }
  ];
  succesLogIn = true;

  constructor(private fb: FormBuilder, private router: Router){
    this.form = this.fb.group({
      email: ['', Validators.required],
      password: ['', Validators.required]
    });
  }
  
  clickEvent(event: MouseEvent) {
    this.hide.set(!this.hide());
    event.stopPropagation();
  }
  
  showAlert(){
    if(this.form.valid){
      Swal.fire({
        title: '¡Éxito!',
        text: 'Datos Registrados',
        icon: 'success',
        confirmButtonText: 'Aceptar'
      });
    }
  }

  logIn(){
    let aux = false;
    let user = "user";
    this.admins.forEach((admin, index) => {
      if (admin.email == this.form.value.email 
        && admin.password == this.form.value.password) {
        aux = true;
        localStorage.setItem('admin', JSON.stringify(admin));

        this.showAlert();

        user = user + index.toString();
        console.log(index);
        
        this.router.navigate([user, 'home']);
      }
    });

    this.succesLogIn = aux;
  }
}
