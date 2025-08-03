import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { take } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class CochesService {

  constructor(private http: HttpClient) { }

  retornar() {
    return this.http.get("https://racing.free.beeceptor.com/todos").pipe(take(1));
  }
}
