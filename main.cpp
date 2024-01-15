#include <iostream>
#include <vector>
#include <string>
#include <memory>

class SQLAbfragen
{
    std::string to_string(std::vector<std::vector<char>>& Spielfeld, std::string& finaler_string, int zeile, int spalte)
    {
        if(Spielfeld.size()-1 == zeile && Spielfeld[zeile].size()-1 == spalte)
        {
            finaler_string.push_back(Spielfeld[zeile][spalte]);
            return finaler_string;
        }

        if(Spielfeld[zeile].size()-1 == spalte)
        {
            finaler_string.push_back(Spielfeld[zeile][spalte]);
            finaler_string.push_back('U');
            return to_string(Spielfeld, finaler_string, zeile+1, 0);
        }

        finaler_string.push_back(Spielfeld[zeile][spalte]);
        return to_string(Spielfeld,finaler_string , zeile, spalte+1);
    }

    std::vector<std::vector<char>> to_vector(std::string& Spielfeld, std::vector<std::vector<char>>& finaler_vector, size_t zeile)
    {
        if(Spielfeld.empty())
        {
            return finaler_vector;
        }

        if(Spielfeld.front() == 'U')
        {
            Spielfeld.erase(Spielfeld.begin()); // entfernen von U
            finaler_vector.push_back({Spielfeld.front()}); //erstellen der neuen Zeile im Vector
            Spielfeld.erase(Spielfeld.begin());        //entfernen des ersten Zeichens
            return to_vector(Spielfeld, finaler_vector, zeile+1);
        }

        finaler_vector[zeile].push_back(Spielfeld.front());
        Spielfeld.erase(Spielfeld.begin());
        return to_vector(Spielfeld, finaler_vector, zeile);
    }
public:
    std::vector<std::vector<char>> getSpielfeld(int ID)
    {
        std::vector<std::vector<char>> Spielfeld{{}};
        std::string s{"fffUfffUfff"}; //Normallerweise wird hier der String aus der Datenbank geholt

        return to_vector(s, Spielfeld, 0);
    }

    void setSpielfeld(int ID, std::vector<std::vector<char>> Spielfeld)
    {
        std::string s2 ="";// Damit wir eine Speicheradresse haben
        s2 = to_string(Spielfeld, s2, 0,0);

        //TODO: hier in der Datenbank speichern
    }
};

int main()
{
    std::unique_ptr<SQLAbfragen> db{std::make_unique_ptr<SQLAbfragen>()};

    std::vector<std::vector<char>> Spielfeld{db->getSpielfeld(1)};

    Spielfeld.push_back({'f', 'x'});

    db->setSpielfeld(1, Spielfeld);

    return 0;
}
