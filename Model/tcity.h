#ifndef TCITY_H
#define TCITY_H
#include <string>
#include <iostream>

//using namespace std;

class TCity
{
public:
    TCity(const std::string CityName,const unsigned long CityPopulation, const int CityYear);
    std::string GetName()  const;
    unsigned long  GetCityPopulation() const;
    int GetYear() const;
    void SetName(const std::string name)
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
    friend std::istream& operator>>(std::istream &stream, TCity* &obj);
    friend std::ostream& operator<<(std::ostream &stream, TCity &obj);
private:
  std::string CityName;
  unsigned long  CityPopulation;
  int CityYear;
};


#endif // TCITY_H
