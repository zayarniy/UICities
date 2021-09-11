#ifndef TCITIES_H
#define TCITIES_H
#include "tcity.h"
#include <vector>
#include <map>

class TCities
{
private:
    vector<TCity*> list;
public:
    TCities();
    ~TCities();
    vector<TCity*> GetList();//!!!
    void Add(TCity* city);
    void Remove(TCity* city);
    void RemoveAt(int index);
    void Save(string filename);//std::ostream &outstream);
    void Load(string filename);
    void ShowListContents();
    void Init();
    int Count();
    int FindByCityName(string CityName);
    TCities* CitiesByYear(int year);
    int CitiesCensuses(string name);
    map<string, TCity*> CitiesMillionaire();
};

#endif // TCITIES_H
