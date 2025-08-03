import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GastronomyComponent } from './gastronomy.component';

describe('GastronomyComponent', () => {
  let component: GastronomyComponent;
  let fixture: ComponentFixture<GastronomyComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [GastronomyComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(GastronomyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
