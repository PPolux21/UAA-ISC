#include <iostream>
#include <string>

using namespace std;

class CEmpleado {
protected:
    string nombre;
    int id;

public:
    CEmpleado(string _nombre, int _id) : nombre(_nombre), id(_id) {}
    virtual void calcularSalario() const = 0;
};

void CEmpleado::calcularSalario() const {
    cout << "Nombre: " << nombre << endl;
    cout << "ID: " << id << endl;
}

class CEmpRegular : public CEmpleado {
private:
    float salarioBase;

public:
    CEmpRegular(string _nombre, int _id, float _salarioBase)
        : CEmpleado(_nombre, _id), salarioBase(_salarioBase) {}

    void calcularSalario() const override;
};

void CEmpRegular::calcularSalario() const {
    CEmpleado::calcularSalario();
    cout << "El salario Base es: " << salarioBase << endl;
}

class CEmpTemp : public CEmpleado {
private:
    int horasTrabajadas;
    float tarifa;

public:
    CEmpTemp(string _nombre, int _id, int _horasTrabajadas, float _tarifa)
        : CEmpleado(_nombre, _id), horasTrabajadas(_horasTrabajadas), tarifa(_tarifa) {}

    void calcularSalario() const override;
};

void CEmpTemp::calcularSalario() const {
    CEmpleado::calcularSalario();
    cout << "Horas laboradas: " << horasTrabajadas << " Tarifa: " << tarifa << endl;
    cout << "Tu salario es: " << horasTrabajadas * tarifa << endl;
}

int main() {
    const int numEmpleados = 2;
    CEmpleado *empleados[numEmpleados];

    empleados[0] = new CEmpRegular("Rene", 260866, 20000);
    empleados[1] = new CEmpTemp("Amalia Bonita", 134679, 8, 5000);

    for (int i = 0; i < numEmpleados; i++) {
        empleados[i]->calcularSalario();
        cout << "------------------------" << endl;
    }

    // Liberar memoria
    for (int i = 0; i < numEmpleados; i++) {
        delete empleados[i];
    }

    return 0;
}


/*#include <iostream>
#include <string>



class CEmpleado {
protected:
    string nombre;
    int id;

public:
    CEmpleado(string _nombre, int _id) : nombre(_nombre), id(_id) {}
    virtual void calcularSalario() const = 0;
};

void CEmpleado::calcularSalario(){
	cout << "Nombre: " << nombre << endl;
	cout << "ID: " << id << endl;
}

class CEmpRegular : public CEmpleado{
	private:
		float salario_Base;
	public:
		CEmpRegular(string _nombre, int _id, float _salario_Base) : CEmpleado(_nombre,_id), salario_Base(_salario_Base){}
		virtual void calcularSalario() const override;
};

void CEmpRegular::calcularSalario(){
	CEmpleado::calcularSalario();
	cout << "El salario Base es: " << salario_Base << endl;
}

class CEmpTemp : public CEmpleado{
	private:
		int horasTrabajadas;
		float tarifa;
	public:
		CEmpTemp(string _nombre, int _id, int  _horasTrabajadas, float _tarifa) : CEmpleado(_nombre,_id), 
		horasTrabajadas(_horasTrabajadas), tarifa(_tarifa)){}		
		virtual void calcularSalario()  override;
};

void CEmpTemp::calcularSalario(){
	CEmpleado::calcularSalario();
	cout << "Horas laboradas: " horasTrabajadas << " Tarida: " << tarifa << endl;
	cout << "Tu salario es: " << horasTrabajadas * tarifa;
}


int main(){
	CEmpleado *empleados[2];
	empleados[0] = new CEmpRegular("Rene", 260866, 20000);
	empleados[1] = new  CEmpTemp("Amalia Bonita", 134679, 8,5000);
	
	for(int i=0;i<2;i++){
		empleado[i]->calcularSalario();
	}
	
	for(int i=0;i<2; i++){
		delete empleados[i];
	}
}*/