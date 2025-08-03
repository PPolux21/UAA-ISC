import { TestBed } from '@angular/core/testing';

import { RoomsServiceService } from './rooms-service.service';

describe('RoomsServiceService', () => {
  let service: RoomsServiceService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(RoomsServiceService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
