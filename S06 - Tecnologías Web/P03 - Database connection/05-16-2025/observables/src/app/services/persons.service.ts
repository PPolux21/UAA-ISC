import { Injectable } from '@angular/core';
import { PersonModel } from '../models/person.model';
import { BehaviorSubject, Observable } from 'rxjs';
import { v4 as uuidv4 } from 'uuid';

@Injectable({
  providedIn: 'root'
})
export class PersonsService {

  aux:PersonModel = {
    _uid:"",
    _name:"",
    _lastname:"",
    _contact:""
  } 

  private $persons: BehaviorSubject<PersonModel[]> = new BehaviorSubject<PersonModel[]>([]);

  _persons: Observable<PersonModel[]> = this.$persons.asObservable();

  private $person: BehaviorSubject<PersonModel> = new BehaviorSubject<PersonModel>(this.aux);

  _person: Observable<PersonModel> = this.$person.asObservable();

  constructor() { 
    let data:any=localStorage.getItem('data');
    if(data){
      this.$persons.next(JSON.parse(data));
    }
  }

  fnAddPerson(person:PersonModel):void{
    let aux:PersonModel[] = this.$persons.getValue();
    person._uid = uuidv4();
    aux.push(person);
    this.$persons.next(aux);
    this.fnSaveLocalStorage();
  }

  fnSaveLocalStorage(){
    let aux:PersonModel[] = this.$persons.getValue();
    let strAux:string = JSON.stringify(aux);
    localStorage.setItem('data',strAux);
  }

  fnLoadPerson(person:PersonModel):void{
    this.$person.next(person);
  }

  fnEditPerson(person:PersonModel):void{
    console.log(person);
    let aux:PersonModel[] = this.$persons.getValue();
    let indexDelete:number = -1;

    aux.forEach((savePerson,index)=>{
      if (savePerson._uid == person._uid) {
        indexDelete = index;
      }
    });

    if (indexDelete != -1) {
      aux[indexDelete] = person;
    }

    this.$persons.next(aux);
    this.fnSaveLocalStorage();
  }

  fnResetLoadPerson():void{
    this.$person.next(null!);
  }

  fnDeletePerson(person:PersonModel):void{
    let aux:PersonModel[] = this.$persons.getValue();
    let indexDelete:number = aux.indexOf(person);
    if (indexDelete!=-1) {
      let loadPerson:PersonModel = this.$person.getValue();
      if (loadPerson) {
        if(loadPerson._uid == person._uid)
          this.fnResetLoadPerson();
      }
      aux.splice(indexDelete,1);
    }
    this.$persons.next(aux);
    this.fnSaveLocalStorage();
  }
  
}
