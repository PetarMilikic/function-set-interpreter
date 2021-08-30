#include<iostream>
#include<cstdlib>
#include<set>
#include "Set.hpp"
using namespace std;

Set Set:: operator +(const Set& s)const
{
    //unija
    Set skup;
    set<double>::const_iterator it1= begin();
    for( ; it1!=end(); it1++)
        skup.insert(*it1);
    it1=s.begin();
    for( ; it1 != s.end(); it1++)
        skup.insert(*it1);
    return skup;
}

Set Set::operator * (const Set& s)const
{
    //presek
    Set skup;
    set<double>::const_iterator it1 = begin();
    for( ; it1 != end(); it1++)
    {
        if(s.find(*it1) != s.end())
            skup.insert(*it1);
    }
    return skup;
}

Set Set::operator - (const Set& s)const
{
    Set skup;
    set<double>::const_iterator it1 = begin();
    for(; it1 != end(); it1++)
    {
        if(s.find(*it1) == s.end())
            skup.insert(*it1);
    }
    return skup;
}

unsigned Set::card()const
{
    return size();
}

bool Set::pripada (const int& d)const
{
    set<double>::const_iterator it1 = find(d);
    if(it1 == end())
        return false;
    return true;

}

set<Set> Set::partitivni ()const
{
  set<Set> result;
  // ubacujemo prazan skup
  result.insert(Set());
  set<Set>::iterator i = result.begin();
  while (i->size() < size()) {
    // u svaki vec napravljeni skup dodajemo po jedan element
    for (set<double>::iterator j = begin(); j!=end(); j++) {
      Set next = *i;
      next.insert(*j);
      result.insert(next);
    }
    i++;
  }
  return result;
}

void Set::ispisi(ostream& izlaz)const
{
    unsigned brojac=  0;
    izlaz << "{";
    set<double>::const_iterator it1 = begin();
    for(; it1 != end(); it1++)
    {
        brojac++;
        if(brojac == size())
            izlaz << *it1;
        else
        {
            izlaz<< *it1 <<", ";
        }
    }
    izlaz<<"}";
}

bool Set::operator < (const Set& s) const {
  if (size() < s.size())
    return true;
  if (s.size() < size())
    return false;
  for (set<double>::iterator i = begin(), j = s.begin(); i != end(); i++, j++)
    if (*i < *j)
      return true;
    else if (*i > *j)
      return false;
  return false;
}

//proba
/*
int main()
{
    Set A;
    A.insert(1);
    A.insert(2); A.insert(3);
    cout<<A;
    Set B;
    B.insert(1);B.insert(5); B.insert(3);
    cout<<A*B;
    cout<<A-B;
    cout<<A.card()<<"\n";
    cout<< A.pripada(3);
    cout<< A.pripada(55);
    set<Set>rez=A.partitivni();
    cout<<"\n--------\n{\n";
    for(auto x: rez)
    {
        cout<<x;
    }
    cout<<"}\n";
    return 0;
}*/

ostream& operator << (ostream& ostr,const Set& c)
{
    c.ispisi(ostr);
    return ostr;
}
