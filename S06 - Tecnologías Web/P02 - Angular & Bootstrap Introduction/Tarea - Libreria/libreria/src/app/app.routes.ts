import { Routes } from '@angular/router';
import { LibreriaComponent } from './libreria/libreria.component';
import { CuentaComponent } from './cuenta/cuenta.component';

export const routes: Routes = [
    {path: 'libreria', component: LibreriaComponent},
    {path: 'cuenta', component: CuentaComponent},
    { path: '**', pathMatch:'full' , redirectTo: 'libreria'},
];
