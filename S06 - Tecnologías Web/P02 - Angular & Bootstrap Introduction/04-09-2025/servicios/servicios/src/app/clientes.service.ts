import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class ClientesService {

  constructor() { }

  clientes:any[]=[
    {
      _id: "624c2b1bb73be06308942694",
      age: 25,
      name: "Page Castro",
      gender: "male",
      company: "FLEETMIX",
      email: "pagecastro@fleetmix.com",
      phone: "+1 (947) 422-3612",
      address: "317 Rockwell Place, Brookfield, Colorado, 9852" },
    {
      _id: "624c2b1b160d82ef3db3aa18",
      age: 28,
      name: "Johnnie Hobbs",
      gender: "female",
      company: "APEXTRI",
      email: "johnniehobbs@apextri.com",
      phone: "+1 (917) 467-2062",
      address: "606 Albemarle Terrace, Hall, Wisconsin, 6115" },
      {
      _id: "624c2b1b3be638f688b03b03",
      age: 34,
      name: "Leanne Glass",
      gender: "female",
      company: "TALKALOT",
      email: "leanneglass@talkalot.com",
      phone: "+1 (821) 515-2120",
      address: "308 Dahill Road, Glasgow, Georgia, 2561"
    },
    {
      _id: "624c2b1b64622ff405aded17",
      age: 22,
      name: "Sophia Pacheco",
      gender: "female",
      company: "ROBOID",
      email: "sophiapacheco@roboid.com",
      phone: "+1 (868) 561-3444",
      address: "654 Highlawn Avenue, Westphalia, Palau, 909" },
    {
      _id: "624c2b1bacfd634d37c94ea6", age: 40,
      name: "Manuela Wise",   
      gender: "female",
      company: "SILODYNE",
      email: "manuelawise@silodyne.com",
      phone: "+1 (961) 455-2435",
      address: "685 Harden Street, Grazierville, Arkansas, 3943" },
    {
      _id: "624c2b1b2ed4a857d1f1d863",
      age: 20,
      name: "Beck Roberson",
      gender: "male",
      company: "LUMBREX",
      email: "beckroberson@lumbrex.com",
      phone: "+1 (848) 447-2480",
      address: "278 Henry Street, Beechmont, Vermont, 3717"
    },
    {
      _id: "624c2b1b950093544a208375",
      age: 20,
      name: "Arnold Bates",
      gender: "male",
      company: "DYMI",
      email: "arnoldbates@dymi.com",
      phone: "+1 (934) 489-2543",
      address: "470 Revere Place, Coral, South Carolina, 9123" },
    {
      _id: "624c2b1b1a83bd777f3022b3",
      age: 35,
      name: "José Luis Espinoza Sánchez",
      gender: "male",
      company: "BUZZOPIA",
      email: "owensrutledge@buzzopia.com",
      phone: "+1 (967) 434-3230",
      address: "169 Kossuth Place, Nettie, Massachusetts, 7596" }
    ]
}
