import { Component, EventEmitter, Output, signal } from '@angular/core';
import { FormBuilder, FormGroup, FormsModule, ReactiveFormsModule, Validators } from '@angular/forms';

@Component({
  selector: 'app-form-libro',
  imports: [ReactiveFormsModule, FormsModule],
  templateUrl: './form-libro.component.html',
  styleUrl: './form-libro.component.css'
})
export class FormLibroComponent {
  form:FormGroup;
  exito = signal(false);

  @Output() libroAgregado = new EventEmitter<{titulo:string; autor:string}>();

  constructor(private fb:FormBuilder){
    this.form = this.fb.group({
      titulo:['',Validators.required],
      autor: ['',Validators.required]
    });
  }

  enviarLibro(){
    if(this.form.valid){
      this.libroAgregado.emit(this.form.value);
      this.exito.set(true);
      this.form.reset();

      setTimeout(() => {
        this.exito.set(false);
      }, 2000);
    }
    console.log(this.form.valid);
    console.log(this.form.value);
  }
}
