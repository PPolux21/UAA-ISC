import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ControlPersonsComponent } from './control-persons.component';

describe('ControlPersonsComponent', () => {
  let component: ControlPersonsComponent;
  let fixture: ComponentFixture<ControlPersonsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [ControlPersonsComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ControlPersonsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
