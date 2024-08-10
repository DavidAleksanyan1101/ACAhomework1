#ifndef __Hash_table__
#define __Hash_table__
#include"list.hpp"
#include"vector.hpp"
#include<bits/stdc++.h>

namespace mySTL
{
    template<typename K , typename V>
    class hash_table
    {
    public:
        hash_table() = default;
        hash_table(const int&);
    public:
        int insert(std::pair<K , V>);
        void remove(const K&);
        V* find(const K&);
    private:
        vector<list<std::pair<K , V>>> table;
        int hash(const K&);
    };

    template<typename K , typename V>
    hash_table<K , V>::hash_table(const int& size)
    {
        table.resize(size);
    }

    template<typename K , typename V>
    int hash_table<K , V>::hash(const K& key)
    {
        return std::hash<K>(key) % table.size();
    }

    template<typename K , typename V>
    int hash_table<K , V>::insert(std::pair<K , V> element)
    {
        int index = hash(element.first);
        for (auto& pair : table[index])
        {
            if (pair.first == element.first)
            {
                pair.second = element.second;
                return index;
            }
        }
        table[index].push_back(element);
        return index;
    }

    template<typename K , typename V>
    V* hash_table<K , V>::find(const K& key)
    {
        int index = hash(key);
        for (auto& pair : table[index])
        {
            if (pair.first == key)
            {
                return &pair.second; 
            }
        }
        return nullptr; 
    }


    // template<typename K , typename V>
    // V& hash_table<K , V>::find(const K& key)
    // {
    //     int index = hash(key);
    //     for (auto& pair : table[index])
    //     {
    //         if (pair.first == key)
    //         {
    //             return pair.second; 
    //         }
    //     }
    //     throw std::runtime_error("Key not found");
    // }








}



#endif // __Hash_table__