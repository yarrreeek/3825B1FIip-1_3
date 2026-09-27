#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

class TBitField {
private:
    uint32_t* bits;    
    int memSize;    
    int bitLen;     

public:

    TBitField(int len);
    TBitField(const TBitField& other);
    ~TBitField();

    TBitField& operator=(const TBitField& other);

    int GetLength() const;
    void SetBit(int n);
    void ClrBit(int n);
    int GetBit(int n) const;

    TBitField operator|(const TBitField& other) const; // or
    TBitField operator&(const TBitField& other) const; // and
    TBitField operator~() const;                       // not

    bool operator==(const TBitField& other) const;
    bool operator!=(const TBitField& other) const;

    friend std::ostream& operator<<(std::ostream& os, const TBitField& bf) {
        for (int i = 0; i < bf.bitLen; i++) {
            os << bf.GetBit(i);
        }
        return os;
    }
};