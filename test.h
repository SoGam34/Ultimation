#pragma once

#include <vector>
#include <string>
#include <iostream>


class Testclass
{
private:
    std::vector<std::vector<char>> Spielfeld_vector;
    std::string Spielfeld_string = "0|0|0/0|0|0/0|0|0";
    std::vector<std::vector<char>> to_2Dvector (std::vector<std::vector<char>>,std::string,size_t);
public:
    Testclass(std::string);
    ~Testclass();
    std::string to_string(std::vector<std::vector<char>>,std::string);
    std::vector<std::vector<char>> to_2Dvector(std::string);
    void print_string_field();
    void print_vector_field();
    void setSpielfeld_vector(std::vector<std::vector<char>> vector);
    std::string getSpielfeld_string();
};

Testclass::Testclass(std::string Spielfeld)
{
    this->Spielfeld_string = Spielfeld;
}

Testclass::~Testclass()
{
}

std::string Testclass::to_string(std::vector<std::vector<char>> field_vector, std::string field_string = ""){
    if(field_vector.empty()){
        return field_string;
    }
    else{
        field_string.append(std::to_string(field_vector.front().front()));
        field_vector.front().erase(field_vector.front().begin());
        if(field_vector.front().empty()){
            field_vector.erase(field_vector.begin());
        }
        return to_string(field_vector,field_string);
    }
}


std::vector<std::vector<char>> Testclass::to_2Dvector(std::string field_string){
    std::vector<std::vector<char>> field_vector{{}};
    return to_2Dvector(field_vector,field_string,0);
}

std::vector<std::vector<char>> Testclass::to_2Dvector(std::vector<std::vector<char>> field_vector, std::string field_string,size_t row = 0){

    if(field_string.empty()){return field_vector;}

    else if(field_string[0] == '|'){
        field_string.erase(0,1);// pops '|'
        field_vector[row].push_back(field_string[0]); //adds new character to the current row
        field_string.erase(0,1); // pops the inserted character
        return to_2Dvector(field_vector,field_string,row);
    }

    else if(field_string[0] == '/'){// pop first character and add a new row to the vector and insert the first character
        field_string.erase(0,1);// pops '/'
        field_vector.push_back({field_string[0]}); //appends character in new row
        field_string.erase(0,1); // pops the inserted character
        return to_2Dvector(field_vector,field_string,row++);
    }
    else{return {{}};}
}

void Testclass::print_string_field(){
    std::cout<<Spielfeld_string<<std::endl;
    return;
}
void Testclass::print_vector_field(){
    for(std::vector<char> row : Spielfeld_vector){
        std::cout<<"|";
        for (char character : row){
            std::cout<<character<<"|";
        }
        std::cout<<std::endl;
    }
    return;
}
void Testclass::setSpielfeld_vector(std::vector<std::vector<char>> vector){
    this->Spielfeld_vector=vector;
}
std::string Testclass::getSpielfeld_string(){
    return Spielfeld_string;
}
