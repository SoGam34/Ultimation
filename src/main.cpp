#include <iostream>
#include <vector>
#include <string>
#include <memory>



int main()
{
    std::unique_ptr<SQLAbfragen> db{std::make_unique_ptr<SQLAbfragen>()};

    std::vector<std::vector<char>> Spielfeld{db->getSpielfeld(1)};

    Spielfeld.push_back({'f', 'x'});

    db->setSpielfeld(1, Spielfeld);

    return 0;
}
