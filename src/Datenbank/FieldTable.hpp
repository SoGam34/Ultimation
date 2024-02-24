#include <string>

class FieldTable
{

public:

    FieldTable();

    std::string getField(int FieldID);

    void setField(std::string Field, int FieldID);

    int createNewField(std::string Field);

    void deleteField(int FieldID);
};

