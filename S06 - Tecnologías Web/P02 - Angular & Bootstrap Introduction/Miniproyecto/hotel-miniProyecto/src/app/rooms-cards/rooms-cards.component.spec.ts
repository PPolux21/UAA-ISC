import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RoomsCardsComponent } from './rooms-cards.component';

describe('RoomsCardsComponent', () => {
  let component: RoomsCardsComponent;
  let fixture: ComponentFixture<RoomsCardsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [RoomsCardsComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(RoomsCardsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
