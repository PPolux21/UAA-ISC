/*
Manejo de estructura FECHA
*/

#include <iostream>

using namespace std;

//declaración de la estructua 
struct Date{
	int day,month,year;
};

//prototipos
Date captura();
void capturaDos(Date *);
void show(Date);


int main()
{
	//declarar una variable de tipo estructura
	Date myBD,vacations;
	Date wedding={3,4,2023};	//inicialización de una struct
	
	myBD=captura();
	capturaDos(&vacations);
	
	show(myBD);
	show(vacations);
}

Date captura()
{
	Date aux;
	cout<<"Birthday date: "<<endl;
	cout<<"Day: ";
	cin>>aux.day;
	cout<<"Month: ";
	cin>>aux.month;
	cout<<"Year: ";
	cin>>aux.year;
	
	// se usa . para las variables estáticas (no dinámicas)
	
	return aux;
}

void capturaDos(Date *vacations)
{
	cout<<"Tell me about your vacations' date: "<<endl;
	cout<<"Day: ";
	cin>>vacations->day;
	cout<<"Month: ";
	cin>>vacations->month;
	cout<<"Year: ";
	cin>>vacations->year;
	
	// se usa -> para las variables dinámicas o en forma de puntero
}

void show(Date oneDate)
{
	cout<<"The date is: "<<oneDate.day<<"/"<<oneDate.month<<"/"<<oneDate.year<<endl;
}