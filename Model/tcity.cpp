#include "tcity.h"

TCity::TCity(const string CityName,const unsigned long  CityPopulation, const int CityYear)
{
    this->CityName=CityName;
    this->CityPopulation=CityPopulation;
    this->CityYear=CityYear;
}

string TCity::GetName() const {
    return this->CityName;
}

unsigned long  TCity::GetCityPopulation() const
{
    return this->CityPopulation;
}
int TCity::GetYear() const
{
    return this->CityYear;
}

istream& operator>>(istream &stream, TCity* &obj)
{
    //cout << "Enter x y z values, separating each with a space: ";
    string name;
    unsigned long population;
    int year;
    stream >> name >> population >>year;
    obj->SetName(name);
    obj->SetCityPopulation(population);
    obj->SetYear(year);
    return stream;
}

ostream& operator<<(ostream &stream, TCity &obj)

{
    stream << obj.CityName <<" " << obj.CityPopulation <<" "<< obj.CityYear;
    return stream;
}
