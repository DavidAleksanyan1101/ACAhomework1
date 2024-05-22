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
    std::cout<<__func__<<std::endl;
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
    int arrSize = 0;
    std::string s1;
    while(getline(inputFile , s1)){
        ++arrSize;
    }
    inputFile.clear();
    inputFile.seekg(0);

    Data** arr = new Data * [arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = nullptr;
    }
    if (inputFile.is_open())
    {
        int count = 0;
        while (std::getline(inputFile , s1))
        {
            arr[count] = new Data;
            
            switch (checkType(s1))
            {
            case dataType::INT:
                arr[count]->_type = dataType::INT;
                arr[count]->v_int = stoi(s1);
                break;
            case dataType::FLOAT:
                arr[count]->_type = dataType::FLOAT;
                arr[count]->v_float = stof(s1);
                break;
            case dataType::STRING:
                arr[count]->_type = dataType::STRING;
                arr[count]->v_string = new std::string(s1);
                break;
            default:
                break;
            }
            ++count;
        }
    }
    printData(arr , arrSize);


    return 0;
}