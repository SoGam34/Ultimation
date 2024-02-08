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

    std::string getAndereSpieler();

    std::string getSpielfeldID(int SpielID);

    std::string getSpielUEbersicht(int SpielID);

    void aktualiesieren(int SpielID, std::vector<std::vector<char>> Spielfeld);

    int neuesSpiel(int Spielart, int Schwierigkeitsgrad, std::string Spieler, std::string SpielfeldID);

    void deleteSpiel(int SpielID);
};


