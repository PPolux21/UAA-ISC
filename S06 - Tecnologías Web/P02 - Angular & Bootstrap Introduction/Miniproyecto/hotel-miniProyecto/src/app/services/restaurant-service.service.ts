import { Injectable } from '@angular/core';
import { Restaurant } from '../model/restaurant';
import { restaurants } from '../objects/restaurants';

@Injectable({
  providedIn: 'root'
})
export class RestaurantServiceService {

  private myRestaurants: Restaurant[] = restaurants;

  constructor() { }

  getRestaurants(): Restaurant[]{
    return this.myRestaurants;
  }
}
