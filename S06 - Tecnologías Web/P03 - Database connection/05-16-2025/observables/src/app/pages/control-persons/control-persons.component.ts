import { Component } from '@angular/core';
import { FormPersonsComponent } from '../form-persons/form-persons.component';
import { ListPersonsComponent } from '../list-persons/list-persons.component';

@Component({
  selector: 'app-control-persons',
  imports: [FormPersonsComponent,ListPersonsComponent],
  templateUrl: './control-persons.component.html',
  styleUrl: './control-persons.component.css'
})
export class ControlPersonsComponent {

}
