import { Injectable } from '@angular/core';
import { Room } from "../model/rooms";
import { rooms } from '../objects/rooms';

@Injectable({
  providedIn: 'root'
})
export class RoomsServiceService {

  private myRooms: Room[] = rooms;

  constructor() { }

  getRooms():Room[] {
    return this.myRooms;
  }
}
