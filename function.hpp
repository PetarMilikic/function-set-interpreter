#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__ 1

#include<iostream>
#include<cmath>
using namespace std;

class Function{
public:
   Function(){}
   virtual ~Function(){}
   virtual double vrednost(double x)const=0;
   virtual void ispisi(ostream& izlaz)const=0;
  // virtual Function* klon()const=0;
};

class Const:public Function{
public:
    Const(double x):_x(x)
    {
        
    }
    ~Const(){}
    double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
    
private:
    double _x;
};

class BinOP:public Function
{
public:
    BinOP(Function* levi,Function* desni):_levi(levi),_desni(desni)
    {
    }
    ~BinOP();
protected:
    Function* _levi;
    Function* _desni;
};

class UnOP:public Function
{
public:
    UnOP(Function*unutra):_unutra(unutra)
    {
    }
    ~UnOP();
protected:
    Function* _unutra;
};

class IdFun:public Function
{
public:
    IdFun(){}
    ~IdFun(){}
    double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
};

class Plus:public BinOP
{
public:
    Plus(Function* levi,Function* desni):BinOP(levi,desni)
    {
    }
    double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
};

class Minus:public BinOP
{
public:
    Minus(Function* levi,Function* desni):BinOP(levi,desni)
    {
    }
   double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
};

class Puta:public BinOP
{
public:
    Puta(Function* levi,Function* desni):BinOP(levi,desni)
    {
    }
    double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
};

class Sin:public UnOP
{
public:
    Sin(Function* unutra):UnOP(unutra)
    {
    }
    double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
};

class Cos:public UnOP
{
public:
    Cos(Function* unutra):UnOP(unutra)
    {
    }
    double vrednost(double x)const;
    void ispisi(ostream& izlaz)const;
};

ostream& operator <<(ostream& ostr,const Function& f);


#endif
