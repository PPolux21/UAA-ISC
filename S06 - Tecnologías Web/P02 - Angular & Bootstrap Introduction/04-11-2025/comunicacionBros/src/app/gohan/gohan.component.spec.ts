import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GohanComponent } from './gohan.component';

describe('GohanComponent', () => {
  let component: GohanComponent;
  let fixture: ComponentFixture<GohanComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [GohanComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(GohanComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
