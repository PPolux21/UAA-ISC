import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-editor',
  imports: [FormsModule],
  templateUrl: './editor.component.html',
  styleUrl: './editor.component.css'
})
export class EditorComponent {

  isTextareaEnabled: boolean = false;
  bgColor: string = "#ddd";

  blogText: string = "";

  // Valores seleccionados
  selectedFont: string = "Arial";
  selectedSize: number = 12;
  selectedColor: string = "black";

  // Habilitar textarea
  enableTextarea(): void {
    this.isTextareaEnabled = true;
    this.bgColor = "white";
  }

  clearText(): void{
    this.blogText = "";
    this.selectedFont = "Arial";
    this.selectedSize = 12;
    this.selectedColor = "black";
  }
}
