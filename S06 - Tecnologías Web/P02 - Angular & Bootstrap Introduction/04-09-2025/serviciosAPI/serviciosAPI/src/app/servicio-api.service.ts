import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { take } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class ServicioAPIService {

  constructor(private http: HttpClient) { }

  retornar() {
    return this.http.get("https://gaia.inegi.org.mx/wscatgeo/mgee/").pipe(take(1));
  }
}
