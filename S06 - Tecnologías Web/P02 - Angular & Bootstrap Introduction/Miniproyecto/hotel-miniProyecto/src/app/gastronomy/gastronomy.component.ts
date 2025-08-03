import { Component } from '@angular/core';
import { Restaurant } from '../model/restaurant';
import { RestaurantServiceService } from '../services/restaurant-service.service';
import { CommonModule } from '@angular/common';
import 'animate.css'
import { ActivatedRoute, RouterModule } from '@angular/router';

@Component({
  selector: 'app-gastronomy',
  imports: [CommonModule, RouterModule],
  templateUrl: './gastronomy.component.html',
  styleUrl: './gastronomy.component.css'
})
export class GastronomyComponent {
  restaurants!: Restaurant[];
  usuario: string = "";

  constructor(private restaurantService: RestaurantServiceService, public activeRoute: ActivatedRoute){
    this.restaurants = restaurantService.getRestaurants();
    this.activeRoute.params.subscribe(params => {
      this.usuario = params['user'];
    });
  }

  getRoutes(destino: string): any[]{
    return this.usuario !== undefined ? ["/" + this.usuario, destino] : ["/" + destino];
  }
}
