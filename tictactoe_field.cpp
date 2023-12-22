#include "tictactoe_field.h"


Tictactoe_field::Tictactoe_field( std::size_t num_rows, std::size_t num_col)
{
    this->num_rows = num_rows;
    this->num_col = num_col;
    init_field();
}
Tictactoe_field::~Tictactoe_field(){}

int Tictactoe_field::get_num_col()
{
    return this->num_col;
}

int Tictactoe_field::get_num_rows()
{
    return this->num_rows;
}

void Tictactoe_field::reset_field() // loops through every bracket of the field and sets it to NULL
{
    for(std::vector<mark>& colum : tictactoe_field){
        for(mark& single_bracket : colum){
            single_bracket = NULL;
        }
    }
}

void Tictactoe_field::init_field() //initializes an empty tictactoe field
{
    tictactoe_field.resize(num_col); // set the number of rows
    for (std::size_t i = 0 ; i < tictactoe_field.size() ; ++i) // set number of colums for each row
    {
        tictactoe_field[i].resize(num_rows);
    }
    
    reset_field();
}

mark Tictactoe_field::checkleft(std::size_t x_pos , std::size_t y_pos)
{
    if(x_pos == 0)
    {
        return tictactoe_field[x_pos][y_pos];
    } // returns if no more left fields
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos-1][y_pos])
    { 
        return checkleft(x_pos-1,y_pos);
    } // goes left recursively
    
    return NULL;
}

mark Tictactoe_field::checkright(std::size_t x_pos , std::size_t y_pos)
{
    if(x_pos == tictactoe_field.size()-1)
    {
        return tictactoe_field[x_pos][y_pos];
    } // returns value of field if no more left fields
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos+1][y_pos])
    { 
        return checkright(x_pos+1,y_pos);
    } // goes recursively to the right
    
    return NULL;
}

mark Tictactoe_field::checkup(std::size_t x_pos , std::size_t y_pos)
{
    if(y_pos == 0)
    {
        return tictactoe_field[x_pos][y_pos];
    } // returns value of field if no more upper fields
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos][y_pos-1])
    { 
        return checkright(x_pos,y_pos-1);
    } // goes recursively up
    
    return NULL;
}

mark Tictactoe_field::checkdown(std::size_t x_pos , std::size_t y_pos)
{
    if(y_pos == tictactoe_field.size()-1)
    {
        return tictactoe_field[x_pos][y_pos];
    } // returns value of field if no more lower fields
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos][y_pos+1])
    {
        return checkright(x_pos,y_pos+1);
    } // goes recursively down
    
    return NULL;
}

mark Tictactoe_field::checkleftup(std::size_t x_pos , std::size_t y_pos)
{
    if(y_pos == 0 && x_pos == 0)
    {
        return tictactoe_field[x_pos][y_pos];
    }
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos-1][y_pos-1])
    { 
        return checkright(x_pos-1,y_pos-1);
    }
    
    return NULL;
}

mark Tictactoe_field::checkleftdown(std::size_t x_pos , std::size_t y_pos)
{
    if(y_pos == tictactoe_field.size()-1 && x_pos == 0)
    {
        return tictactoe_field[x_pos][y_pos];
    }
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos-1][y_pos+1])
    { 
        return checkright(x_pos-1,y_pos+1);
    }
    
    return NULL;
}

mark Tictactoe_field::checkrightup(std::size_t x_pos , std::size_t y_pos)
{
    if(y_pos == 0 && x_pos == tictactoe_field.size()-1)
    {
        return tictactoe_field[x_pos][y_pos];
    }
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos+1][y_pos-1])
    { 
        return checkright(x_pos+1,y_pos-1);
    }
    
    return NULL;
}

mark Tictactoe_field::checkrightdown(std::size_t x_pos , std::size_t y_pos)
{
    if(y_pos == tictactoe_field.size()-1 && x_pos == tictactoe_field.size()-1)
    {
        return tictactoe_field[x_pos][y_pos];
    }
    
    if(tictactoe_field[x_pos][y_pos] == tictactoe_field[x_pos+1][y_pos+1])
    { 
        return checkright(x_pos+1,y_pos+1);
    }
    
    return NULL;
}

mark Tictactoe_field::checkrow(std::size_t x_pos , std::size_t y_pos)
{
    mark result_checkup = checkup(x_pos , y_pos);
    if(result_checkup == NULL){
     return NULL;
    }
    
    if(result_checkup == checkdown(x_pos , y_pos)){
    return result_checkup;
    }
    
    return NULL;
}
mark Tictactoe_field::checkcol(std::size_t x_pos , std::size_t y_pos)
{
    mark result_checkleft = checkleft(x_pos , y_pos);
    if(result_checkleft == NULL){
        return NULL;
    }
    
    if(result_checkleft == checkright(x_pos , y_pos)){
    return result_checkleft;
    }
    
    return NULL;
}
mark Tictactoe_field::checkdiag(std::size_t x_pos , std::size_t y_pos)
{
    mark result_checkleftup = checkleftup(x_pos , y_pos);
    if (result_checkleftup == NULL){
        return NULL;
    }
    
    if(result_checkleftup == checkrightdown(x_pos , y_pos)){
        return result_checkleftup;
    }
    
    mark result_checkleftdown = checkleftdown(x_pos , y_pos);
    if(result_checkleftdown == NULL){
        return NULL;
    }
    if(result_checkleftdown == checkrightup(x_pos , y_pos)){
        return result_checkleftdown;
    }
    
        return NULL;
}
mark Tictactoe_field::checkwinn(std::size_t x_pos , std::size_t y_pos)
{
    mark result = checkcol(x_pos , y_pos);
    if (result != NULL){
        return result;
    }
    
    result = checkrow(x_pos , y_pos);
    if(result != NULL){
        return result;
    }
    
    return checkdiag(x_pos , y_pos);
}




