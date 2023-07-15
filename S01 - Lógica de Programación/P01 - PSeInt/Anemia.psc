Algoritmo Anemia
	Escribir 'Introduce la edad en años'
	Leer años
	Escribir 'Introduce tu nivel de Hemoglobina'
	Leer nivelHG
	Si años>1 Entonces
		Si años>5 Entonces
			Si años>10 Entonces
				Si años>15 Entonces
					Escribir 'Introduce tu sexo'
					Leer sexo
					Segun sexo  Hacer
						'H':
							Si nivelHG<14.0 Entonces
								Escribir 'Tienes anemia'
							SiNo
								Escribir 'No tienes anemia'
							FinSi
						'M':
							Si nivelHG<12.0 Entonces
								Escribir 'Tienes anemia'
							SiNo
								Escribir 'No tienes anemia'
							FinSi
						De Otro Modo:
							Escribir 'Sexo inválido'
					FinSegun
				SiNo
					Si nivelHG<13.0 Entonces
						Escribir 'Tienes anemia'
					SiNo
						Escribir 'No tienes anemia'
					FinSi
				FinSi
			SiNo
				Si nivelHG<12.6 Entonces
					Escribir 'Tienes anemia'
				SiNo
					Escribir 'No tienes anemia'
				FinSi
			FinSi
		SiNo
			Si nivelHG<11.5 Entonces
				Escribir 'Tienes anemia'
			SiNo
				Escribir 'No tienes anemia'
			FinSi
		FinSi
	SiNo
		Escribir 'Introduce la edad en meses'
		Leer meses
		Si meses==0 O meses==1 Entonces
			Si nivelHG<13.0 Entonces
				Escribir 'Tienes anemia'
			SiNo
				Escribir 'No tienes anemia'
			FinSi
		SiNo
			Si meses>1 Y meses<=6 Entonces
				Si nivelHG<10.0 Entonces
					Escribir 'Tienes anemia'
				SiNo
					Escribir 'No tienes anemia'
				FinSi
			SiNo
				Si meses>6 Y meses<=12 Entonces
					Si nivelHG<11.0 Entonces
						Escribir 'Tienes anemia'
					SiNo
						Escribir 'No tienes anemia'
					FinSi
				SiNo
					Escribir 'Datos de edad inválidos'
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
