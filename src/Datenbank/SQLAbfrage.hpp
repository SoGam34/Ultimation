#include <iostream>
#include <vector>
#include <string>
#include <memory>

class SQLAbfragen
{
    std::string to_string(std::vector<std::vector<char>>& Spielfeld, std::string& finaler_string, int zeile, int spalte);

    std::vector<std::vector<char>> to_vector(std::string& Spielfeld, std::vector<std::vector<char>>& finaler_vector, size_t zeile);
    
public:
    std::vector<std::vector<char>> getSpielfeld(int ID);

    void setSpielfeld(int ID, std::vector<std::vector<char>> Spielfeld);
};