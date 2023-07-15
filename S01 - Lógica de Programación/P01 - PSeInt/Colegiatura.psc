Algoritmo Colegiatura
	Leer alum
	Leer prom
	Leer matRep
	Segun alum  Hacer
		'Preparatoria':
			Si prom>=9.5 Entonces
				costo <- 180*11
				costo <- costo*0.75
			SiNo
				Si prom<9.5 Y prom>=9 Entonces
					costo <- 180*10
					costo <- costo*0.90
				SiNo
					Si prom<9 Y prom>7 Entonces
						costo <- 180*10
					SiNo
						Si prom<=7 Entonces
							Si matRep>=4 Entonces
								costo <- 180*8
							SiNo
								costo <- 180*9
							FinSi
						FinSi
					FinSi
				FinSi
			FinSi
			Escribir costo
		'Profesional':
			costo <- 300*11
			Si prom>=9.5 Entonces
				costo <- costo*0.80
			FinSi
			Escribir costo
		De Otro Modo:
			Escribir 'Valor de Alumno inválido'
	FinSegun
FinAlgoritmo
