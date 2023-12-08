#ifndef TICTACTOE_FIELD_H
#define TICTACTOE_FIELD_H
#include <vector>

enum mark {
    NULL,
    X,
    O
};


class Tictactoe_field
{
private:
    int num_col;
    int num_rows;
    std::vector<std::vector<mark>> tictactoe_field;

    // private functions
    mark checkleft(std::size_t,std::size_t);
    mark checkright(std::size_t,std::size_t);
    mark checkup(std::size_t,std::size_t);
    mark checkdown(std::size_t,std::size_t);
    mark checkleftup(std::size_t,std::size_t);
    mark checkleftdown(std::size_t,std::size_t);
    mark checkrightup(std::size_t,std::size_t);
    mark checkrightdown(std::size_t,std::size_t);
    mark checkrow(std::size_t,std::size_t);
    mark checkcol(std::size_t,std::size_t);
    mark checkdiag(std::size_t,std::size_t);

public:

    Tictactoe_field(std::size_t,std::size_t);
    ~Tictactoe_field();
    int get_num_col();
    int get_num_rows();
    void reset_field();
    void init_field();
    mark checkwinn(std::size_t,std::size_t);


};

#endif // TICTACTOE_FIELD_H
