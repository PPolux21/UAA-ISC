import { ComponentFixture, TestBed } from '@angular/core/testing';

import { LibreriaComponent } from './libreria.component';

describe('LibreriaComponent', () => {
  let component: LibreriaComponent;
  let fixture: ComponentFixture<LibreriaComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [LibreriaComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(LibreriaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
