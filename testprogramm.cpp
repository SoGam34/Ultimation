#include "test.h"

int main(){

    Testclass *feld1 = new Testclass("|0|0|0/0|0|0/0|0|0");
    Testclass *feld2 = new Testclass("|X|0|0/0|X|0/0|0|X");
    Testclass *feld3 = new Testclass("|O|0|O/0|0|O/0|O|0");
    Testclass *feld4 = new Testclass("|0|0|0/X|0|O/O|X|0");
    Testclass *feld5 = new Testclass("|0|0|0|0/0|0|0|0/0|0|0|0");
    feld1->print_string_field();
    feld1->setSpielfeld_vector(feld1->to_2Dvector(feld1->getSpielfeld_string()));
    feld1->print_vector_field();
    feld2->print_string_field();
    feld2->setSpielfeld_vector(feld2->to_2Dvector(feld2->getSpielfeld_string()));
    feld2->print_vector_field();
    feld5->print_string_field();
    feld5->setSpielfeld_vector(feld5->to_2Dvector(feld5->getSpielfeld_string()));
    feld5->print_vector_field();
    std::cout<<"end"<<std::endl;
    return 0;
}

