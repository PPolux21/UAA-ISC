Algoritmo Relación_Presión_Volumen_Temperatura
	Mostrar "Introduce la presión en Pascales"
	Leer pres
	Mostrar "Introduce el volumen en m^3"
	Leer vol
	Mostrar "Introduce la temperatura en Kelvin"
	Leer temp
	masa=(pres*vol)/(0.37*(temp+460))
	Mostrar "La cantidad de masa es ", masa, " kg"
FinAlgoritmo
