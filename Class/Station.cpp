#include<iostream>
#include<string>
using namespace std;

class Station
{
private:
    int number;
    string name;
public:
    Station();
    Station(int, string);
    Station(const Station&);
    ~Station();
    void setName(string);
    void setNo(int);
    string getName();
    int getNo();
    Station& operator=(const Station&);
};


void Station::setName(string name)
{
    this->name = name;
}

void Station::setNo(int number)
{
    this->number = number;
}

int Station::getNo()
{
    return number;
}

string Station::getName()
{
    return name;
}

Station::Station(int number, string name)
{
    this->number = number;
    this->name = name;
}

Station::Station(const Station& s)
{
    this->name = s.name;
    this->number = s.number;
}

Station& Station::operator=(const Station& s)
{    
    this->number = s.number;
    this->name = s.name;
    return *this;
}

Station::Station()
{
}

Station::~Station()
{
}


