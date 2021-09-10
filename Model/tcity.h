#ifndef TCITY_H
#define TCITY_H
#include <string>
#include <iostream>

using namespace std;

class TCity
{
public:
    TCity(const string CityName,const unsigned long CityPopulation, const int CityYear);
    string GetName()  const;
    unsigned long  GetCityPopulation() const;
    int GetYear() const;
    void SetName(const string name)
    {
        CityName=name;
        //std::cout<<"Set name";
    }
    void SetYear(const int year)
    {
        CityYear=year;
    }
    void SetCityPopulation(const unsigned long  population)
    {
        CityPopulation=population;
    }
    friend istream& operator>>(istream &stream, TCity* &obj);
    friend ostream& operator<<(ostream &stream, TCity &obj);
private:
  string CityName;
  unsigned long  CityPopulation;
  int CityYear;
};


#endif // TCITY_H
