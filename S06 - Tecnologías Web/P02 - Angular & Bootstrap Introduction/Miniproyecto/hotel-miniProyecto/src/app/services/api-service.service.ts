import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { take } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class ApiServiceService {
  constructor(private http: HttpClient) { }

  retornar(){
    return this.http.get("https://apipropia.free.beeceptor.com/todos").pipe(take(1));
  }
}
