import { Component } from '@angular/core';
import { Observable } from 'rxjs';
import { PersonModel } from '../../models/person.model';
import { PersonsService } from '../../services/persons.service';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-list-persons',
  imports: [CommonModule],
  templateUrl: './list-persons.component.html',
  styleUrl: './list-persons.component.css'
})
export class ListPersonsComponent {
  _persons!:Observable<PersonModel[]>;

  constructor(private personsService:PersonsService){
    this._persons = this.personsService._persons;
  }

  fnEditPerson(person:PersonModel){
    this.personsService.fnLoadPerson(person);
  }

  fnNewPerson(){
    this.personsService.fnResetLoadPerson();
  }

  fnDeletePerson(person:PersonModel){
    this.personsService.fnDeletePerson(person);
  }
}
