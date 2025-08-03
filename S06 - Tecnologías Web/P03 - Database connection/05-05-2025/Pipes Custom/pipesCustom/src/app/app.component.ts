import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { CapitalizadoPipe } from './capitalizado.pipe';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, CapitalizadoPipe, CommonModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'pipesCustom';

  clientes: string[] = ["mArÍa lUcÍa gOnZáLeZ rOdRíGuEz", "jUaN dAvId pÉrEz lÓpEz", "cArMeN eStHeR dElGaDo rAmOs", "fErNaNdO aNdRéS rAmÍrEz mEdInA"];
}
