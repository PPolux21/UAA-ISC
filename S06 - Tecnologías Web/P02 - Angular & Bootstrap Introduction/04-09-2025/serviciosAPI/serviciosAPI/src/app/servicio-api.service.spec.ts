import { TestBed } from '@angular/core/testing';

import { ServicioAPIService } from './servicio-api.service';

describe('ServicioAPIService', () => {
  let service: ServicioAPIService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(ServicioAPIService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
