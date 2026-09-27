#pragma once
#include "TBitset.h"

class TSet {
private:
    TBitField bf;

public:

    TSet(int maxPower);

    void Add(int elem);         
    void Remove(int elem);      
    bool IsFull() const;        
    bool IsEmpty() const;     
    bool Contains(int elem) const; 
    int GetMaxPower() const;

    TSet Union(const TSet& other) const;        
    TSet Intersection(const TSet& other) const; 
    TSet Difference(const TSet& other) const;  
    TSet Complement() const;                   

    bool operator==(const TSet& other) const;
    bool operator!=(const TSet& other) const;


    friend std::ostream& operator<<(std::ostream& os, const TSet& set);
};