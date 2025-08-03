import { ComponentFixture, TestBed } from '@angular/core/testing';

import { UnheroeComponent } from './unheroe.component';

describe('UnheroeComponent', () => {
  let component: UnheroeComponent;
  let fixture: ComponentFixture<UnheroeComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [UnheroeComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(UnheroeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
