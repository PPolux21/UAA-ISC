#include <iostream>

using namespace std;



class Punto
{
private:
	double x{}, y{};
public:
	Punto(double x,double y) : x(x),y(y) {}
	
	friend void print(const Punto &p);
};



void print(const Punto &p)
{
	cout<<"("<<p.x<<","<<p.y<<") "<<"["<<&p<<"]"<<endl;
}



int main()
{
	cout<<"Hello World :D\n";
	Punto p1(5,4);
	print(p1);
	return 0;
}