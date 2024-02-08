#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

class UserTabel
{
    std::string Benutzername;

public:
    SQLAbfragen(std::string Benutzername);

    std::string getPassword();

    int getXP();

    int getUserID();

    int createUser(std::string Passwort);

    void deleteUser();

    void setPasswort(std::string Passwort);

    void setXP(int neuXP);

    std::string getUserSkin(std::string);
};