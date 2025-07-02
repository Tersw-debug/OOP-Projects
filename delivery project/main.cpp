#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "header1.h"
#include "header2.h"
using namespace std;
Package::Package(const string &na1,const string &cit1,const string &add1,const string &stat1,int zipSender1,int zipRecipient1,double wigh1,
                             double cos1)
{
    name = na1;
    city = cit1;
    address = add1;
    state = stat1;
    zipCodeSender = zipSender1;
    zipCodeRecipient = zipRecipient1;
    setWight(wigh1);
    setCost(cos1);
}
void Package::setName(const string &na2)
{
    name = na2;
}
void Package::setAdress(const string &add2)
{
    address = add2;
}
void Package::setCity(const string &cit2)
{
    city = cit2;
}
void Package::setState(const string &stat2)
{
        state = stat2;
}
void Package::setZipCodeSender(int zip1)
{
    zipCodeSender = zip1;
}
void Package::setZipCodeRecipient(int zip2)
{
    zipCodeRecipient = zip2;
}

void Package::setWight(double wigh2)
{
    wight = wigh2;
}

void Package::setCost(double cos2)
{
    cost = cos2;
}


string Package::getName() const
{
    return name;
}

string Package::getAdress() const
{
    return address;
}

string Package::getState() const
{
    return state;
}

string Package::getCity() const
{
    return city;
}

int Package::getZipCodeRecipient() const
{
    return zipCodeRecipient;
}

int Package::getZipCodeSender() const
{
    return zipCodeSender;
}

double Package::getWight() const
{
    return wight;
}

double Package::getCost() const
{
    return cost;
}


double Package::calculateCost() const
{
    return getWight() * getCost();
}

void Package::printAdress() const
{
    cout << "Information: " << getState() << "/" << getCity() << "/" << getAdress()<<endl;
    cout << "Zip-Sender: " << to_string(getZipCodeSender()) << endl;
    cout << "Zip-Recipient: " << to_string(getZipCodeRecipient()) << endl;

}


TwoDayPackage::TwoDayPackage(const string &na,const string &cit,const string &add,const string &stat,int zipSender,int zipRecipient,double wigh,
                             double cos,double flefee)
    : Package( na , cit ,add , stat , zipSender , zipRecipient , wigh , cos )
{
    setFlyFee(flefee);
}

void TwoDayPackage::setFlyFee(double flet)
{
    flyfee = flet;
}

double TwoDayPackage::getFlyFee() const
{
    return flyfee;
}
double TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + getFlyFee();
}

OverNightPackage::OverNightPackage(const string &na5,const string &cit5,const string &add5,const string &stat5,int zipSender5,int zipRecipient5,double wigh5,
                             double cos5,double flefee5)
    : Package( na5 , cit5 ,add5 , stat5 , zipSender5 , zipRecipient5 , wigh5 , cos5 )
{
    setFlyFee3(flefee5);
}


void OverNightPackage::setFlyFee3(double flat)
{
    flyfee = flat;
}


double OverNightPackage::getFlyFee3() const
{
    return flyfee;
}
double OverNightPackage::calculateCost() const
{
    return Package::calculateCost() + getFlyFee3();
}

void printing(const Package * const ptrert)
{
    cout << "Cost: " <<  ptrert->calculateCost() <<endl;
    ptrert->printAdress();
}


int main()
{
    TwoDayPackage ob1("Mina" , "giza","Hermina","newzlinda", 1235, 3615,300.0,100.0,300.0);
    OverNightPackage ob2("Mina" , "giza","Hermina","newzlinda", 1235, 3615,300.0,100.0,300.0);
    vector<Package * > pack(2);
    pack[0] = &ob1;
    pack[1] = &ob2;
    for(const Package * packptr:pack)
        printing(packptr);

    return 0;
}
