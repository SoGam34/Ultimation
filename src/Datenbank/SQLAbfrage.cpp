#include "SQLAbfrage.hpp"

std::string SQLAbfrage::to_string(std::vector<std::vector<char>>& Field, std::string& final_string, size_t zeile, size_t spalte) 
{// soll das Field von einem 2-Dimensionalen Vektor in einen std::string nach Schema "fffufffufff" umwandeln. Die Zeitkomplexität ist O(n²).   
    if(Field.size()-1 == zeile && Field[zeile].size()-1 == spalte) // fügt, wenn im letzten feld, dieses an den std::string an und gibt diesen zurück
    {
        final_string.push_back(Field[zeile][spalte]);
        return final_string;
    }

    if(Field[zeile].size()-1 == spalte) // wenn eine zeile zuende ist, wird auch ein 'U' an den std::string angehängt, um dies anzuzeigen
    {
        final_string.push_back(Field[zeile][spalte]); // zeichen wird an std::string angehängt
        final_string.push_back('U'); //signalisiert neue Zeile
        return to_string(Field, final_string, zeile+1, 0); // setzt die Spalte zurück und inkrementiert die Zeile
    }

    else
    { // bei felder, welche nicht am Ende der Zeile sind, wird das Element angehängt und die Spalte inkrementiert
        final_string.push_back(Field[zeile][spalte]);
        return to_string(Field, final_string, zeile, spalte+1);
    }
}

std::vector<std::vector<char>> SQLAbfrage::to_vector(std::string& Field, std::vector<std::vector<char>>& final_vector, size_t zeile)
{
    if(Field.empty())
    {
        return final_vector;
    }

    if(Field.front() == 'U')
    {
        Field.erase(Field.begin()); // entfernen von U
        final_vector.push_back({Field.front()}); //erstellen der neuen Zeile im Vector
        Field.erase(Field.begin());        //entfernen des ersten Zeichens
        return to_vector(Field, final_vector, zeile+1);
    }

    final_vector[zeile].push_back(Field.front());
    Field.erase(Field.begin());
    return to_vector(Field, final_vector, zeile);
}

std::vector<std::vector<char>> SQLAbfrage::getField(int FieldID)
{
    std::vector<std::vector<char>> Spielfeld{{}};
    std::string s{"fffUfffUfff"}; //Normallerweise wird hier der String aus der Datenbank geholt
    return to_vector(s, Spielfeld, 0);
}

void SQLAbfrage::setField(int FieldID, std::vector<std::vector<char>> Field)
{
    std::string s ="";// Damit wir eine Speicheradresse haben
    s = to_string(Field, s, 0, 0);
    //TODO: hier in der Datenbank speichern
}