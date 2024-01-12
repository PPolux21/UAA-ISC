#ifndef enemigo_hpp
#define enemigo_hpp

class CPersonaje
{    
public:
    float xVPer, yVPer;
    int xPer, yPer;
    float dt;
    int direction;
    void setPosicion(int _xPer,int _yPer);
    CPersonaje(float, float, int, int, float, int);
    virtual void fisicaNivel1()=0;
    virtual void fisicaNivel2()=0;
    virtual void fisicaNivel3()=0;
};

CPersonaje::CPersonaje(float _xVPer, float _yVPer, int _xPer, int _yPer, float _dt, int _direction)
{
    xVPer = _xVPer;
    yVPer = _yVPer;
    xPer = _xPer;
    yPer = _yPer;
    dt = _dt;
    direction = _direction;
}

void CPersonaje::setPosicion(int _xPer,int _yPer)
{
    xPer = _xPer;
    yPer = _yPer;
}

class CEnemigo : public CPersonaje
{
public:
    bool sentido;// true = horario      false = antihorario
    CEnemigo(float, float, int, int, float, int, bool);
    virtual void fisicaNivel1();
    virtual void fisicaNivel2();
    virtual void fisicaNivel3();
};

CEnemigo::CEnemigo(float _xVPer, float _yVPer, int _xPer, int _yPer, float _dt, int _direction,bool _sentido)
:CPersonaje(_xVPer, _yVPer,  _xPer,  _yPer,  _dt, _direction)
{
    sentido = _sentido;
}

void CEnemigo::fisicaNivel1()
{
// chocar con 3,4,5,6
    iMat = (xPer+3)/TAM;
    jMat = (yPer+3)/TAM;
    kMat = (xPer+22)/TAM;
    hMat = (yPer+22)/TAM;
    if (sentido)
    {//sentido horario
        switch (direction)
        {
        case ARRIBA:
            if(mat[hMat-1][iMat] == 1 || mat[hMat-1][kMat] == 1)
            {
                yPer = hMat *TAM;
                if((mat[hMat][iMat+1] == 2 || mat[hMat][iMat+1] == 0) 
                && (mat[hMat][kMat+1] == 2 || mat[hMat][kMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }else if((mat[hMat-1][iMat] == 2 || mat[hMat-1][iMat] == 0) 
                && (mat[hMat-1][kMat] == 2 || mat[hMat-1][kMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }else if((mat[hMat][iMat-1] == 2 || mat[hMat][iMat-1] == 0) 
                && (mat[hMat][kMat-1] == 2 || mat[hMat][kMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }else if((mat[hMat+1][iMat] == 2 || mat[hMat+1][iMat] == 0) 
                && (mat[hMat+1][kMat] == 2 || mat[hMat+1][kMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }
            }else{
                yPer -= vYPer * dt;
            }
            break;
        case ABAJO:
            if(mat[jMat+1][iMat] == 1 || mat[jMat+1][kMat] == 1)
            {
                yPer = jMat *TAM;
                if((mat[jMat][iMat-1] == 2 || mat[jMat][iMat-1] == 0) 
                && (mat[jMat][kMat-1] == 2 || mat[jMat][kMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }else if((mat[jMat+1][iMat] == 2 || mat[jMat+1][iMat] == 0) 
                && (mat[jMat+1][kMat] == 2 || mat[jMat+1][kMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }else if((mat[jMat][iMat+1] == 2 || mat[jMat][iMat+1] == 0) 
                && (mat[jMat][kMat+1] == 2 || mat[jMat][kMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }else if((mat[jMat-1][iMat] == 2 || mat[jMat-1][iMat] == 0) 
                && (mat[jMat-1][kMat] == 2 || mat[jMat-1][kMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }
            }else{
                yPer += vYPer * dt;
            }
            break;
        case IZQUIERDA:
            if( mat[jMat][iMat-1] == 1 || mat[hMat][iMat-1] == 1)
            {
                xPer = iMat *TAM;
                if((mat[jMat-1][iMat] == 2 || mat[jMat-1][iMat] == 0) 
                && (mat[hMat-1][iMat] == 2 || mat[hMat-1][iMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }else if((mat[jMat][iMat-1] == 2 || mat[jMat][iMat-1] == 0) 
                && (mat[hMat][iMat-1] == 2 || mat[hMat][iMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }else if((mat[jMat+1][iMat] == 2 || mat[jMat+1][iMat] == 0) 
                && (mat[hMat+1][iMat] == 2 || mat[hMat+1][iMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }else if((mat[jMat][iMat+1] == 2 || mat[jMat][iMat+1] == 0) 
                && (mat[hMat][iMat+1] == 2 || mat[hMat][iMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }
            }else{
                xPer -= xVPer * dt;
            }
            break;
        case DERECHA:
            if(mat[jMat][kMat+1] == 1 || mat[hMat][kMat+1] == 1)
            {
                xPer = kMat *TAM;
                if((mat[jMat+1][kMat] == 2 || mat[jMat+1][kMat] == 0) 
                && (mat[hMat+1][kMat] == 2 || mat[hMat+1][kMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }else if((mat[jMat][kMat+1] == 2 || mat[jMat][kMat+1] == 0) 
                && (mat[hMat][kMat+1] == 2 || mat[hMat][kMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }else if((mat[jMat-1][kMat] == 2 || mat[jMat-1][kMat] == 0) 
                && (mat[hMat-1][kMat] == 2 || mat[hMat-1][kMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }else if((mat[jMat][kMat-1] == 2 || mat[jMat][kMat-1] == 0) 
                && (mat[hMat][kMat-1] == 2 || mat[hMat][kMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }
            }else{
                xPer += xVPer * dt;
            }
            break;
        }
    }else{
        switch (direction)
        {
        case ARRIBA:
            if(mat[hMat-1][iMat] == 1 || mat[hMat-1][kMat] == 1)
            {
                yPer = hMat *TAM;
                if((mat[hMat][iMat-1] == 2 || mat[hMat][iMat-1] == 0) 
                && (mat[hMat][kMat-1] == 2 || mat[hMat][kMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }else if((mat[hMat-1][iMat] == 2 || mat[hMat-1][iMat] == 0) 
                && (mat[hMat-1][kMat] == 2 || mat[hMat-1][kMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }else if((mat[hMat][iMat+1] == 2 || mat[hMat][iMat+1] == 0) 
                && (mat[hMat][kMat+1] == 2 || mat[hMat][kMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }else if((mat[hMat+1][iMat] == 2 || mat[hMat+1][iMat] == 0) 
                && (mat[hMat+1][kMat] == 2 || mat[hMat+1][kMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }
            }else{
                yPer -= vYPer * dt;
            }
            break;
        case ABAJO:
            if(mat[jMat+1][iMat] == 1 || mat[jMat+1][kMat] == 1)
            {
                yPer = jMat *TAM;
                if((mat[jMat][iMat+1] == 2 || mat[jMat][iMat+1] == 0) 
                && (mat[jMat][kMat+1] == 2 || mat[jMat][kMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }else if((mat[jMat+1][iMat] == 2 || mat[jMat+1][iMat] == 0) 
                && (mat[jMat+1][kMat] == 2 || mat[jMat+1][kMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }else if((mat[jMat][iMat-1] == 2 || mat[jMat][iMat-1] == 0) 
                && (mat[jMat][kMat-1] == 2 || mat[jMat][kMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }else if((mat[jMat-1][iMat] == 2 || mat[jMat-1][iMat] == 0) 
                && (mat[jMat-1][kMat] == 2 || mat[jMat-1][kMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }
            }else{
                yPer += vYPer * dt;
            }
            break;
        case IZQUIERDA:
            if( mat[jMat][iMat-1] == 1 || mat[hMat][iMat-1] == 1)
            {
                xPer = iMat *TAM;
                if((mat[jMat+1][iMat] == 2 || mat[jMat+1][iMat] == 0) 
                && (mat[hMat+1][iMat] == 2 || mat[hMat+1][iMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }else if((mat[jMat][iMat-1] == 2 || mat[jMat][iMat-1] == 0) 
                && (mat[hMat][iMat-1] == 2 || mat[hMat][iMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }else if((mat[jMat-1][iMat] == 2 || mat[jMat-1][iMat] == 0) 
                && (mat[hMat-1][iMat] == 2 || mat[hMat-1][iMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }else if((mat[jMat][iMat+1] == 2 || mat[jMat][iMat+1] == 0) 
                && (mat[hMat][iMat+1] == 2 || mat[hMat][iMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }
            }else{
                xPer -= xVPer * dt;
            }
            break;
        case DERECHA:
            if(mat[jMat][kMat+1] == 1 || mat[hMat][kMat+1] == 1)
            {
                xPer = kMat *TAM;
                if((mat[jMat-1][kMat] == 2 || mat[jMat-1][kMat] == 0) 
                && (mat[hMat-1][kMat] == 2 || mat[hMat-1][kMat] == 0))
                {
                    yPer -= vYPer * dt;
                    direction = ARRIBA;
                }else if((mat[jMat][kMat+1] == 2 || mat[jMat][kMat+1] == 0) 
                && (mat[hMat][kMat+1] == 2 || mat[hMat][kMat+1] == 0))
                {
                    xPer += xVPer * dt;
                    direction = DERECHA;
                }else if((mat[jMat+1][kMat] == 2 || mat[jMat+1][kMat] == 0) 
                && (mat[hMat+1][kMat] == 2 || mat[hMat+1][kMat] == 0))
                {
                    yPer += vYPer * dt;
                    direction = ABAJO;
                }else if((mat[jMat][kMat-1] == 2 || mat[jMat][kMat-1] == 0) 
                && (mat[hMat][kMat-1] == 2 || mat[hMat][kMat-1] == 0))
                {
                    xPer -= xVPer * dt;
                    direction = IZQUIERDA;
                }
            }else{
                xPer += xVPer * dt;
            }
            break;
        }
    }  
}

void CEnemigo::fisicaNivel2()
{

}

void CEnemigo::fisicaNivel3()
{

}

#endif