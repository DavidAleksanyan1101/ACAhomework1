#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>

enum class dataType
{
    INT ,
    FLOAT ,
    STRING
};

struct Data
{
    dataType _type;
    union
    {
        int v_int;
        float v_float;
        std::string* v_string;
    };
};

dataType checkType(const std::string& s)
{
    std::istringstream checkStr(s);
    int i;
    if (checkStr >> i && checkStr.eof())
    {
        return dataType::INT;
    }

    checkStr.clear();
    checkStr.str(s);
    float f;
    if (checkStr >> f && checkStr.eof())
    {
        return dataType::FLOAT;
    }

    else
    {
        return dataType::STRING;
    }
}

void printData(Data** arr , const int& size)
{
    for (int i = 0; i < size;++i)
    {
        switch (arr[i]->_type)
        {
        case dataType::INT:
            std::cout << "int " << arr[i]->v_int << std::endl;
            break;
        case dataType::FLOAT:
            std::cout << "flt " << arr[i]->v_float << std::endl;
            break;
        case dataType::STRING:
            std::cout << "str " << *arr[i]->v_string << std::endl;
            break;
        default:
            break;
        }
    }

}


int main()
{
    std::ifstream inputFile("input.txt");
    Data** arr = new Data * [30];
    int arrSize = 0;
    for (int i = 0; i < 30; i++)
    {
        arr[i] = nullptr;
    }
    std::string s1;
    if (inputFile.is_open())
    {
        while (std::getline(inputFile , s1))
        {
            arr[arrSize] = new Data;

            switch (checkType(s1))
            {
            case dataType::INT:
                arr[arrSize]->_type = dataType::INT;
                arr[arrSize]->v_int = stoi(s1);
                break;
            case dataType::FLOAT:
                arr[arrSize]->_type = dataType::FLOAT;
                arr[arrSize]->v_float = stof(s1);
                break;
            case dataType::STRING:
                arr[arrSize]->_type = dataType::STRING;
                arr[arrSize]->v_string = new std::string(s1);
                break;
            default:
                break;
            }
            ++arrSize;
        }
    }

    printData(arr , arrSize);


    return 0;
}