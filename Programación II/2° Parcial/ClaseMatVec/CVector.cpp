#include "CVector.h"

CVector::CVector(void)
{
	for(int i=0;i<3;i++)
		vec[i]=0;
}

CVector::CVector(int _0,int _1,int _2)
{
	vec[0]=_0;
	vec[0]=_1;
	vec[0]=_2;
}

CVector::CVector(const CVector &obj)
{
	for(int i=0;i<3;i++)
		vec[i] = obj.vec[i];
}

CVector CVector::multiplicar(CVector& obj)
{
	CVector res;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			res.vec[i] = this->mat[i][j] * obj.vec[j];
	
	return res;
}