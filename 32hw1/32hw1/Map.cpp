#include "Map.h"
#include <iostream>

Map::Map()
:m_data()
{
    m_size = 0;
}
    // Create an empty map (i.e., one with no key/value pairs)


bool Map::empty() {
    // Return true if the map is empty, otherwise false.
    if (m_size == 0) {
        return true;
    }
    return false;
}

int Map::size() const{
    // Return the number of key/value pairs in the map.
    return m_size;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
      // If key is not equal to any key currently in the map, and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that either the key is already in the map, or the map has a fixed
      // capacity and is full).
    
    if (m_size == DEFAULT_MAX_ITEMS) {
        return false;
    }
    
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].m_key == key) {
            return false;
        }
    }
    
    m_data[m_size].m_key = key;
    m_data[m_size].m_val = value;
    m_size++;
    
    return true;
    
}

bool Map::update(const KeyType& key, const ValueType& value) {
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value it currently maps to, but instead map to
      // the value of the second parameter; return true in this case.
      // Otherwise, make no change to the map and return false.
    
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].m_key == key) {
            m_data[i].m_val = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value that it currently maps to, but instead map to
      // the value of the second parameter; return true in this case.
      // If key is not equal to any key currently in the map and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that the key is not already in the map and the map has a fixed
      // capacity and is full).
    
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].m_key == key) {
            m_data[i].m_val = value;
            return true;
        }
    }
    
    if (m_size == DEFAULT_MAX_ITEMS) {
           return false;
    }
    
    m_data[m_size].m_key = key;
    m_data[m_size].m_val = value;
    m_size++;
    return true;
}

bool Map::erase(const KeyType& key) {
      // If key is equal to a key currently in the map, remove the key/value
      // pair with that key from the map and return true.  Otherwise, make
      // no change to the map and return false.
    for (int i = 0; i < m_size; i++) {
        if (key == m_data[i].m_key) {
            for (int j = i; j < m_size-1; j++) {
                m_data[j] = m_data[j+1];
            }
            m_size--;
            return true;
        }
    }
    return false;
}

bool Map::contains(const KeyType& key) const{
      // Return true if key is equal to a key currently in the map, otherwise
      // false.
    
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].m_key == key) {
            return true;
        }
    }
    return false;
}

bool Map::get(const KeyType& key, ValueType& value) const {
      // If key is equal to a key currently in the map, set value to the
      // value in the map which that key maps to, and return true.  Otherwise,
      // make no change to the value parameter of this function and return
      // false.

    for (int i = 0; i <m_size; i++) {
        if (m_data[i].m_key == key) {
            value = m_data[i].m_val;
            return true;
        }
    }
    return false;
}
     
bool Map::get(int i, KeyType& key, ValueType& value) const {
      // If 0 <= i < size(), copy into the key and value parameters the
      // key and value of one of the key/value pairs in the map and return
      // true.  Otherwise, leave the key and value parameters unchanged and
      // return false.  (See below for details about this function.)
    if (i >= m_size) {
        return false;
    }
    
    key = m_data[i].m_key;
    value = m_data[i].m_val;
    return true;
}

void Map::swap(Map& other) {
      // Exchange the contents of this map with the other one
    int maxsize;
    if (m_size > other.m_size) {
        maxsize = m_size;
    }
    else maxsize = other.m_size;
    
    int mysize = m_size;
    int othersize = other.m_size;
    m_size = othersize;
    mapObj placehold;
    
    for (int i=0; i < maxsize; i++) {
        placehold = m_data[i];
        m_data[i]=other.m_data[i];
        other.m_data[i] = placehold;
        
    }
    other.m_size = mysize;
}


