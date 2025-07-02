#ifndef HEADER2_H
#define HEADER2_H

class Package
{
public:
    Package(const std::string &,const std::string &,const std::string &,
            const std::string &,int = 0,int = 0,double = 0.0,double = 0.0);
    void setWight(double);
    void setCost(double);
    void setName(const std::string &);
    void setAdress(const std::string &);
    void setCity(const std::string &);
    void setState(const std::string &);
    void setZipCodeSender(int);
    void setZipCodeRecipient(int);

    double getWight() const;
    double getCost() const;
    std::string getName()const;
    std::string getAdress()const;
    std::string getCity()const;
    std::string getState()const;
    int getZipCodeSender()const;
    int getZipCodeRecipient()const;

    virtual double calculateCost() const;
    virtual void printAdress() const;

private:
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    int zipCodeSender;
    int zipCodeRecipient;
    double wight;
    double cost;
};

#endif // HEADER2_H_INCLUDED
