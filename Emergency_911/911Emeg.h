#ifndef 911EMEG_H
#define 911EMEG_H
#include <string>

class Emergency
{
public:
    explicit Emergency(int , std::string , std::string);
    std::string police(std::string);
    std::string ambulance(std::string);
    std::string fire_department(std::string);


private:
    int ip_address;
    int phone;
    int time;
    std::string nature_of_emergency;
    std::string type_of_response;
    std::string nature_of_response;
};



#endif // 911EMEG_H_INCLUDED
