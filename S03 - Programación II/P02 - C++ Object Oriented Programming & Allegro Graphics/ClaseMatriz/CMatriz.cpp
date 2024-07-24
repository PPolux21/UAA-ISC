#include "CMatriz.h"
#include <iostream>

using namespace std;

//constuctores
CMatriz::CMatriz(void)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat[i][j]=0;
}

CMatriz::CMatriz(int _0_0,int _0_1,int _0_2,int _1_0,int _1_1,int _1_2,int _2_0,int _2_1,int _2_2)
{
	mat[0][0] = _0_0;
	mat[0][1] = _0_1;
	mat[0][2] = _0_2;
	mat[1][0] = _1_0;
	mat[1][1] = _1_1;
	mat[1][2] = _1_2;
	mat[2][0] = _2_0;
	mat[2][1] = _2_1;
	mat[2][2] = _2_2;
}
CMatriz::CMatriz(const CMatriz& obj)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat[i][j] = obj.mat[i][j];
}

//sets & gets
void CMatriz::setNum(int _row,int _colum,int _data)
{
	if(_row<3 && _colum<3)
		mat[_row][_colum] = _data;
}

int CMatriz::getNum(int _row,int _colum)
{
	if(_row<3 && _colum<3)
		return mat[_row][_colum];
	else
		return -1;
}


//operadores 
CMatriz CMatriz::operator+ (const CMatriz& obj)
{
	CMatriz res;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			res.mat[i][j] = this->mat[i][j] + obj.mat[i][j];
			
	return res;
}

CMatriz CMatriz::operator- (const CMatriz& obj)
{
	CMatriz res;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			res.mat[i][j] = this->mat[i][j] - obj.mat[i][j];
			
	return res;
}

CMatriz CMatriz::operator= (const CMatriz& obj)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			this->mat[i][j] = obj.mat[i][j];
			
	return (*this);
}

bool operator== (CMatriz& a,CMatriz& b)
{
	bool ban=true;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a.mat[i][j] != b.mat[i][j])
				ban=false;
	
	return ban;
}

bool operator!= (CMatriz& a,CMatriz& b)
{
	bool ban=false;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a.mat[i][j] != b.mat[i][j])
				ban=true;
	
	return ban;
}
ostream& operator<< (ostream& co,const CMatriz& obj)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			co<<obj.mat[i][j]<<"\t";
		co<<endl;
	}
	return co;
}

istream& operator>> (istream& in,CMatriz& obj)
{
	cout<<"Llenar matriz: "<<endl;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"Posicion ["<<i<<"]["<<j<<"]: ";
			cin>> obj.mat[i][j];
		}
		cout<<endl;
	}
	return in;
}