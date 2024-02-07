#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

class SQLAbfragen
{
    std::string to_string(std::vector<std::vector<char>>& Spielfeld, std::string& finaler_string, int zeile, int spalte);

    std::vector<std::vector<char>> to_vector(std::string& Spielfeld, std::vector<std::vector<char>>& finaler_vector, size_t zeile);

public:
    std::vector<std::vector<char>> getSpielfeld(int ID);

    void setSpielfeld(int ID, std::vector<std::vector<char>> Spielfeld);

    std::string getPassword(std::string Benutzername);

    std::vector<std::string> getUserProfil(std::string Benutzername);

    std::string getUserSkin(std::string Benutzername);

    int neuerUser(std::string Benutzername, std::string Passwort);

    void loescheUser(std::string Benutzername);

    void resetPasswort(std::string Benutzername, std::string neuesPasswort);

    void aktualiesiereUserXP(std::string Benutzername, int draufZuRechnendeXP);

    int getXP(std::string Benutzername);
    
    std::vector<int> getAktuelleSpiele(std::string Benutzername);

    std::map<std::string, std::string> getSpielDetails(int SpielID);

    int neuesSpiel(int Spielart, int Schwierigkeitsgrad, std::string Spieler)
};