import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GotenComponent } from './goten.component';

describe('GotenComponent', () => {
  let component: GotenComponent;
  let fixture: ComponentFixture<GotenComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [GotenComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(GotenComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
