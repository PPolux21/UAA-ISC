import { CommonModule } from '@angular/common';
import { Component } from '@angular/core';
import { AbstractControl, FormBuilder, FormControl, FormGroup, ReactiveFormsModule, ValidatorFn, Validators } from '@angular/forms';
import { RouterOutlet } from '@angular/router';

function noCaracteresEspeciales(control: AbstractControl): { [key: string]: any } | null {
     const caracteresEspeciales = /[!@#$%^&*(),.?":{}|<>]/;
     const tieneCaracterEspecial = caracteresEspeciales.test(control.value);
    return tieneCaracterEspecial ? { caracteresEspeciales: true } : null;
}

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, ReactiveFormsModule, CommonModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'validatorCustom';
    formulario!: FormGroup;
    nombreControl!: FormControl;
    emailControl!: FormControl;
    passwordControl!: FormControl;
    passwordRepControl!: FormControl;
    mostrarPassword: boolean = false;
    mostrarPasswordRep: boolean = false;

    constructor(private formBuilder: FormBuilder) { 
      this.nombreControl = new FormControl('', [
      Validators.required,
      Validators.minLength(3),
      Validators.maxLength(50),
      noCaracteresEspeciales // Validador personalizado
    ]);

    this.emailControl = new FormControl('', [
      Validators.required,
      Validators.email,
      Validators.pattern('[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}')
    ]);

    this.passwordControl = new FormControl('', [
      Validators.required, 
      Validators.minLength(12)
    ]);

    this.passwordRepControl = new FormControl('', [
      Validators.required, 
      Validators.minLength(12)
    ]);

    this.formulario = this.formBuilder.group({
      nombre: this.nombreControl,
      email: this.emailControl,
      password: this.passwordControl,
      passwordRepeted: this.passwordRepControl,
    });

    this.passwordRepControl?.setValidators([Validators.required, Validators.minLength(12), this.passwordValidator()]);
  }

  public passwordValidator(): ValidatorFn {
    return () => {

      const password = this.passwordControl?.value;
      const repeat_password = this.passwordRepControl?.value;

      if(!password || !repeat_password) return { isValid: false };

      if(password!==repeat_password) return {isValid:true};      
      
      return null;
    };
  }
  

}
