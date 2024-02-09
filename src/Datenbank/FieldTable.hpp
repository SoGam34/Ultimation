#include <string>

class FieldTable
{
    int FieldID;

public:
    FieldTable(int FieldID);

    std::string getField();

    void setField(std::string Field);

    int createNewField(std::string Field);

    void deleteField();
};

