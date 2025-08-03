import { Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { AboutComponent } from './about/about.component';
import { HeroesComponent } from './heroes/heroes.component';
import { UnheroeComponent } from './unheroe/unheroe.component';
import { SearchComponent } from './search/search.component';

export const routes: Routes = [
    {path: 'home', component: HomeComponent},
    {path: 'about', component: AboutComponent},
    {path: 'carros', component: HeroesComponent},
    {path: 'carro/:id', component: UnheroeComponent},
    {path: 'buscador/:nombre', component: SearchComponent},
    { path: '**', pathMatch:'full' , redirectTo: 'home'},
];
 