#ifndef __SET_HPP__
#define __SET_HPP__

#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;
class Set:public set<double>
{
    
public:
    Set() {}
    Set operator +(const Set& s)const;
    Set operator * (const Set& s)const;
    Set operator -(const Set& s)const;
    unsigned card()const;
    bool pripada (const int& d)const;
    set<Set> partitivni ()const;
    void ispisi(ostream& izlaz)const;
    bool operator < (const Set& s)const;
};

ostream& operator << (ostream&ostr,const Set& c);

#endif
