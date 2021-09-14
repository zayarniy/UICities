#include "tcity.h"

TCity::TCity(const std::string CityName,const unsigned long  CityPopulation, const int CityYear)
{
    this->CityName=CityName;
    this->CityPopulation=CityPopulation;
    this->CityYear=CityYear;
}

std::string TCity::GetName() const {
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

std::istream& operator>>(std::istream &stream, TCity* &obj)
{
    //cout << "Enter x y z values, separating each with a space: ";
    std::string name;
    unsigned long population;
    int year;
    stream >> name >> population >>year;
    obj->SetName(name);
    obj->SetCityPopulation(population);
    obj->SetYear(year);
    return stream;
}

std::ostream& operator<<(std::ostream &stream, TCity &obj)

{
    stream << obj.CityName <<" " << obj.CityPopulation <<" "<< obj.CityYear;
    return stream;
}
