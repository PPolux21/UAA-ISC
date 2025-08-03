import { Component, OnInit } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { ApiServiceService } from '../services/api-service.service';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-saucers',
  imports: [FormsModule, RouterOutlet],
  templateUrl: './saucers.component.html',
  styleUrl: './saucers.component.css'
})
export class SaucersComponent implements OnInit {
  array: any[] = [];
  filtro: string = ''; 

  constructor(public apiServiceService: ApiServiceService) {}

  ngOnInit(): void {
    this.recuperarDatos();
  }

  recuperarDatos(): void {
    this.apiServiceService.retornar().subscribe({
      next: this.successRequest.bind(this),
      error: (err) => { console.log(err); }
    });
  }

  successRequest(data: any): void {
    this.array = data.platillos;
  }

  get filtrados(): any[] {
    const f = this.filtro.trim().toLowerCase();
    if (!f) return this.array;
    return this.array.filter(p => p.name.toLowerCase().includes(f));
  }
}
