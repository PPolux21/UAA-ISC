#include <iostream>

using namespace std;

class ClaseMadre
{
private:
//	float nA;
protected:
//	float nA;
public:
	float nA;
	ClaseMadre(float _nA):nA(_nA){};
	virtual void mostrarNumeros();
};

void ClaseMadre::mostrarNumeros()
{
	cout<<"el numero flotante es "<< nA<<endl;
}



class ClasePadre
{
private:
//	int n1,n2,n3;	//para que no sean accesibles para otras clases
protected: //para que sean atributos privados de otras clases
//	int n1,n2,n3;
public:
	int n1,n2,n3; 	//para que sean atributos publios de otras clases
	ClasePadre(int _n1,int _n2,int _n3):n1(_n1),n2(_n2),n3(_n3){};
	virtual void mostrarNumeros();
	virtual void saluda()=0;
};

void ClasePadre::mostrarNumeros()
{
	cout<<"los numeros son: "<<n1<<", "<<n2<<", "<<n3<<endl;
}



class ClaseHija: public ClasePadre, public ClaseMadre
{
private:
//	int n4;
protected:
//	int n4;
public:
	int n4;
	ClaseHija(int _n1,int _n2,int _n3,int _n4, float _nA);
	virtual void mostrarNumeros();
	virtual void saluda();
};

ClaseHija::ClaseHija(int _n1,int _n2,int _n3,int _n4,float _nA):ClasePadre(_n1,_n2,_n3),ClaseMadre(_nA)
{
	n4=_n4;
}

void ClaseHija::mostrarNumeros()
{
	cout<<"los numeros son: "<<n1<<", "<<n2<<", "<<n3<<", "<<n4<<", "<<nA<<endl;
}

void ClaseHija::saluda()
{
	cout<<"Wenas Atte. Hija"<<endl;
}



class ClaseNieta: public ClaseHija
{
private:
//	int n5;
protected:
//	int n5;
public:
	int n5;
	ClaseNieta(int _n1,int _n2,int _n3,int _n4,int _n5,float _nA);
	virtual void mostrarNumeros();
	
	virtual void saluda();
};

ClaseNieta::ClaseNieta(int _n1,int _n2,int _n3,int _n4,int _n5,float _nA):ClaseHija(_n1,_n2,_n3,_n4,_nA)
{
	n5=_n5;
}

void ClaseNieta::mostrarNumeros()
{
	cout<<"los numeros son: "<<n1<<", "<<n2<<", "<<n3<<", "<<n4<<", "<<n5<<", "<<nA<<endl;
}

void ClaseNieta::saluda()
{
	cout<<"Wenas Atte. Nieta"<<endl;
}



class ClaseHijo: public ClasePadre
{
private:
//	char c1;
protected:
//	char c1;
public:
	char c1;
	ClaseHijo(int _n1,int _n2,int _n3,char _c1);
	void mostrarContenido();
};

ClaseHijo::ClaseHijo(int _n1,int _n2,int _n3,char _c1):ClasePadre(_n1,_n2,_n3)
{
	c1=_c1;
}

void ClaseHijo::mostrarContenido()
{
	cout<<"los numeros son "<<n1<<", "<<n2<<", "<<n3<<"\n el caracter es "<<c1<<endl;
}



class ClaseNieto: public ClaseHijo
{
private:
//	char c2;
protected:
//	char c2;
public:
	char c2;
	ClaseNieto(int _n1,int _n2,int _n3,char _c1,char _c2);
	virtual void mostrarContenido();	
};

ClaseNieto::ClaseNieto(int _n1,int _n2,int _n3,char _c1,char _c2):ClaseHijo(_n1,_n2,_n3,_c1)
{
	c2=_c2;
}

void ClaseNieto::mostrarContenido()
{
	cout<<"los numeros son "<<n1<<", "<<n2<<", "<<n3<<"\n los caracteres son "<<c1<<", "<<c2<<endl;
}



int main()
{
/*	ClaseMadre madre=ClaseMadre(0.5);
	madre.mostrarNumero();
//	cout<<madre.nA<<endl<<endl;
	
	ClasePadre padre=ClasePadre(1,2,3);
	padre.mostrarNumeros();
//	cout<<padre.n1<<endl<<endl;
	
	
	ClaseHija hija=ClaseHija(1,2,3,4,0.5);
	hija.mostrarNumeros();
//	cout<<hija.n1<<endl;
//	cout<<hija.n2<<endl;
//	cout<<hija.n4<<endl;
//	cout<<hija.nA<<endl<<endl;
	
	
	ClaseNieta nieta=ClaseNieta(1,2,3,4,5,0.5);
	nieta.mostrarNumeros();
//	cout<<nieta.n1<<endl;
//	cout<<nieta.n3<<endl;
//	cout<<nieta.n5<<endl;
//	cout<<nieta.nA<<endl;
	
	ClaseHijo hijo=ClaseHijo(3,2,1,':');
	hijo.mostrarContenido();
	
	ClaseNieto nieto=ClaseNieto(9,8,7,':',')');
	nieto.mostrarContenido();
*/	
	/*
	ClaseHija *ch = new ClaseHija(1,2,3,4,1.1);
	ch->mostrarNumeros();
	
	ClaseNieta *cn = new ClaseNieta(1,2,3,4,5,2.2);
	cn->mostrarNumeros();
	
	ClaseHija *ch2 = new ClaseNieta(1,2,3,4,5,1.1);
	ch2->mostrarNumeros();
	*/
	ClaseHija hija=ClaseHija(1,2,3,4,2.2);
	ClaseNieta nieta(1,2,3,4,5,3.3);
	
	ClaseHija *ptrCH1=&hija;
	ClaseHija *ptrCH2=&nieta;
	
	ptrCH1->mostrarNumeros();
	ptrCH2->mostrarNumeros();
	
	ClaseHija *hijas[]={new ClaseNieta(1,2,3,4,5,1.1),new ClaseHija(1,2,3,4,1.1),new ClaseHija(1,2,3,4,1.1)};
	
	for(int i=0;i<3;i++)
	{
		cout<<endl;
		hijas[i]->saluda();
		hijas[i]->mostrarNumeros();
	}
	
	return 0;
}