#ifndef newMap_h
#define newMap_h

#include <iostream>

using KeyType = std::string;
using ValueType = double;

const int DEFAULT_MAX_ITEMS = 240;

class Map
{
  public:
    Map();
    Map(int length);
    ~Map();
    Map &operator= (const Map &src);
    Map(const Map& src);
    bool empty();
    int size() const;
    bool insert(const KeyType& key, const ValueType& value);
    bool update(const KeyType& key, const ValueType& value);
    bool insertOrUpdate(const KeyType& key, const ValueType& value);
    bool erase(const KeyType& key);
    bool contains(const KeyType& key) const;
    bool get(const KeyType& key, ValueType& value) const;
    bool get(int i, KeyType& key, ValueType& value) const;
    void swap(Map& other);
    
  private:
    struct mapObj   {
        KeyType m_key;
        ValueType m_val;
    };
    mapObj * m_data;
    int m_size;
    int m_maxsize;
};


#endif




