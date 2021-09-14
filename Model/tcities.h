#ifndef TCITIES_H
#define TCITIES_H
#include "tcity.h"
#include <vector>
#include <map>


class TCities
{
private:
    std::vector<TCity*> list;
public:
    TCities();
    ~TCities();
    std::vector<TCity*> GetList();//!!!
    void Add(TCity* city);
    void Remove(TCity* city);
    void RemoveAt(int index);
    void Save(std::string filename);//std::ostream &outstream);
    void Load(std::string filename);
    void ShowListContents();
    std::vector<std::string> GetCityNames();
    void Init();
    std::vector<TCity*>::iterator GetBegin();
    std::vector<TCity*>::iterator GetEnd();
    int Count();
    int FindByCityName(std::string CityName);
    TCities* CitiesByYear(int year);
    int CitiesCensuses(std::string name);
    std::map<std::string, TCity*> CitiesMillionaire();
};

#endif // TCITIES_H
