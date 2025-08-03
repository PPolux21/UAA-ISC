import { Routes } from '@angular/router';
import { RoomsComponent } from './rooms/rooms.component';
import { HomeComponent } from './home/home.component';
import { GastronomyComponent } from './gastronomy/gastronomy.component';
import { AboutComponent } from './about/about.component';
import { LoginComponent } from './login/login.component';
import { HotelServicesComponent } from './hotel-services/hotel-services.component';
import { ReservationComponent} from './reservation/reservation.component';
import { AdminLayoutComponent } from './admin-layout/admin-layout.component';
import { UserLayoutComponent } from './user-layout/user-layout.component';
import { AdminControlComponent } from './admin-control/admin-control.component';
import { SaucersComponent } from './saucers/saucers.component';

export const routes: Routes = [
    {path: '', component: UserLayoutComponent, children: [
        {path: 'home', component: HomeComponent},
        {path: 'rooms', component: RoomsComponent},
        {path: 'gastronomy', component: GastronomyComponent},
        {path: 'about', component: AboutComponent},
        {path: 'login', component: LoginComponent},
        {path: 'hotel-services', component: HotelServicesComponent},
        {path: 'reservation', component: ReservationComponent},
        {path: 'reservation/:room', component: ReservationComponent},
        {path: 'saucer', component: SaucersComponent}
    ]},
    {path: ':user', component: AdminLayoutComponent, children: [
        {path: 'home', component: HomeComponent},
        {path: 'rooms', component: RoomsComponent},
        {path: 'gastronomy', component: GastronomyComponent},
        {path: 'about', component: AboutComponent},
        {path: 'admincontrol', component: AdminControlComponent},
        {path: 'hotel-services', component: HotelServicesComponent},
        {path: 'reservation', component: ReservationComponent},
        {path: 'reservation/:room', component: ReservationComponent},
        {path: 'saucer', component: SaucersComponent}
        // {path: '**', redirectTo: 'home'}
    ]},
    {path: '**', redirectTo: 'home'}
];
