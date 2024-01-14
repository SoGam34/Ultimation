#include <iostream>
#include <vector>
#include <string>
#include <memory>

class SQLAbfragen
{
    std::string to_string(std::vector<std::vector<char>>& map, std::string& finaler_string, int zeile, int spalte)
    {
        if(map.size()-1 == zeile && map[zeile].size()-1 == spalte)
        {
            finaler_string.push_back(map[zeile][spalte]);
            return finaler_string;
        }

        if(map[zeile].size()-1 == spalte)
        {
            finaler_string.push_back(map[zeile][spalte]);
            finaler_string.push_back('U');
            return to_string(map, finaler_string, zeile+1, 0);
        }

        finaler_string.push_back(map[zeile][spalte]);
        return to_string(map,finaler_string , zeile, spalte+1);
    }

    std::vector<std::vector<char>> to_vector(std::string& map, std::vector<std::vector<char>>& finaler_vector, size_t zeile)
    {
        if(map.empty())
        {
            return finaler_vector;
        }

        if(map.front() == 'U')
        {
            map.erase(map.begin()); // entfernen von U
            finaler_vector.push_back({map.front()}); //erstellen der neuen Zeile im Vector
            map.erase(map.begin());        //entfernen des ersten Zeichens
            return to_vector(map, finaler_vector, zeile+1);
        }

        finaler_vector[zeile].push_back(map.front());
        map.erase(map.begin());
        return to_vector(map, finaler_vector, zeile);
    }
public:
    std::vector<std::vector<char>> getSpielfeld(int ID)
    {
        std::vector<std::vector<char>> map{{}};
        std::string s = "fffUfffUfff"; //Normallerweise wird hier der String aus der Datenbank geholt

        return to_vector(s, map, 0);
    }

    void setSpielfeld(int ID, std::vector<std::vector<char>> map)
    {
        std::string s2 ="";// Damit wir eine Speicheradresse haben
        s2 = to_string(map, s2, 0,0);

        //TODO: hier in der Datenbank speichern
    }
};

int main()
{
    std::unique_ptr<SQLAbfragen> db(new SQLAbfragen());

    std::vector<std::vector<char>> map = db->getSpielfeld(1);

    map.push_back({'f', 'x'});

    db->setSpielfeld(1, map);

    return 0;
}
