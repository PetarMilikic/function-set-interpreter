#include<iostream>
#include<cmath>
#include "function.hpp"
using namespace std;

double Const:: vrednost(double x)const
{
    return _x;
}
    
void Const::ispisi(ostream& izlaz)const
{
    izlaz << "(" << _x << ")";
}
    
double IdFun::vrednost(double x)const
{
    return x;   
}

void IdFun::ispisi(ostream& izlaz)const
{
    izlaz<<"x";   
}

UnOP:: ~UnOP()
{
    delete _unutra;
}

BinOP:: ~BinOP()
{
    delete _levi;
    delete _desni;
}
    
double Plus::vrednost(double x)const
{
    return _levi->vrednost(x)+_desni->vrednost(x);
}

void Plus::ispisi(ostream& izlaz)const
{
    izlaz << "( ";
    _levi -> ispisi(izlaz);
    izlaz << " + ";
    _desni -> ispisi(izlaz);
    izlaz << ") ";
}

double Minus:: vrednost(double x)const
{
    return _levi->vrednost(x)-_desni->vrednost(x);
}
  
void Minus:: ispisi(ostream& izlaz)const
{
    izlaz << "( ";
    _levi -> ispisi(izlaz);
    izlaz << " - ";
    _desni -> ispisi(izlaz);
    izlaz << ") ";
}

double Puta:: vrednost(double x)const
{
        return _levi -> vrednost(x) * _desni -> vrednost(x);
}
    
void Puta:: ispisi(ostream& izlaz)const
{
    izlaz << "( ";
    _levi -> ispisi(izlaz);
    izlaz << " * ";
    _desni -> ispisi(izlaz);
    izlaz << " )";       
}

double Sin::vrednost(double x)const
{
    return sin(_unutra -> vrednost(x));
}
    
void Sin:: ispisi(ostream& izlaz)const
{
    izlaz<<"sin( ";
    _unutra->ispisi(izlaz);
    izlaz<<" )";
}

double Cos::vrednost(double x)const
{
    return cos(_unutra->vrednost(x));
}
  
void Cos:: ispisi(ostream& izlaz)const
{
    izlaz<<"cos( ";
    _unutra->ispisi(izlaz);
    izlaz<<" )";
}

ostream& operator <<(ostream& ostr, const Function& f)
{
    f.ispisi(ostr);
    return ostr;
}

//proba:

/*
int main()
{
    
    Sin* sinus=new Sin(new Puta(new IdFun(),new Cos(new Const(55))));
    cout<<*sinus<<endl;
    delete sinus;
    
    return 0;
}
*/
