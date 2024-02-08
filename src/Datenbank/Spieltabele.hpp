#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

class SpielTabele
{
    std::string Benutzername;

public:
    SpielTabele(std::string Benutzername);

    std::string getSpieler();

    std::string getSpielfeldID();

    std::string getUEbersicht();

    void aktualiesieren();

    int neuesSpiel();

    void deleteSpiel();
};


