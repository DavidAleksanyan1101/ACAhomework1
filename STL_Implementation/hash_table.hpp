#ifndef __Hash_table__
#define __Hash_table__
#include"list.hpp"
#include"vector.hpp"

namespace mySTL
{
    template<typename K , typename V>
    class hash_table
    {
    public:
        hash_table() = default;
        hash_table(const int&);
    public:
        void insert(std::pair<K , V>);
        void remove(const K&);
        V& find(const K&);
    private:
        vector<list<std::pair<K , V>>> table;
        int hash(const K&);
    };

    template<typename K , typename V>
    hash_table<K,V>::hash_table(const int& size){
        table.resize(size);
    }
    
    
    template<typename K , typename V>
    int hash_table<K,V>::hash(const K& key){
        return std::hash<K>(key);
    }
    
    
    template<typename K , typename V>
    int hash_table<K,V>::insert(const K& key){
        return std::hash<K>{}(key) ;
    }











}



#endif // __Hash_table__