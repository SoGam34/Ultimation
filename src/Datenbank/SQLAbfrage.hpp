#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

class SQLAbfragen
{
    std::string Benutzername;

    std::string to_string(std::vector<std::vector<char>>& Spielfeld, std::string& finaler_string, int zeile, int spalte);

    std::vector<std::vector<char>> to_vector(std::string& Spielfeld, std::vector<std::vector<char>>& finaler_vector, size_t zeile);

public:
    SQLAbfragen(std::string Benutzername);
    
    std::vector<std::vector<char>> getSpielfeld(int ID);

    void setSpielfeld(int ID, std::vector<std::vector<char>> Spielfeld);

    std::string getPassword();

    std::vector<std::string> getUserProfil();

    std::string getUserSkin();

    int neuerUser(std::string Passwort);

    void loescheUser();

    void resetPasswort(std::string neuesPasswort);

    void aktualiesiereUserXP(int draufZuRechnendeXP);

    int getXP();
    
    std::vector<int> getAktuelleSpiele();

    std::map<std::string, std::string> getSpielDetails(int SpielID);

    int neuesSpiel(int Spielart, int Schwierigkeitsgrad, std::string Spieler)
};