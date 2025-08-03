import { Routes } from '@angular/router';
import { ControlPersonsComponent } from './pages/control-persons/control-persons.component';

export const routes: Routes = [
    {path:'home', component:ControlPersonsComponent},
    {path:'**',pathMatch:'full', redirectTo:'home'}
];
