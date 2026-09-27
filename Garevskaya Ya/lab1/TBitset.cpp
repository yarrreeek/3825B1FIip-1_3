#include "pch.h"
#include "../lab1/TBitset.h"
#include <stdexcept>


TBitField::TBitField(int len) {
    if (len < 0) throw std::invalid_argument("Length cannot be negative");
    bitLen = len;
    memSize = (len + 31) / 32;
    bits = new uint32_t[memSize];

    for (int i = 0; i < memSize; i++) {
        bits[i] = 0;
    }
}

TBitField::TBitField(const TBitField& other) {
    bitLen = other.bitLen;
    memSize = other.memSize;
    bits = new uint32_t[memSize];
    for (int i = 0; i < memSize; i++) {
        bits[i] = other.bits[i];
    }
}

TBitField::~TBitField() {
    delete[] bits;
}

TBitField& TBitField::operator=(const TBitField& other) {
    if (this == &other) return *this; 

    if (memSize != other.memSize) {
        delete[] bits;
        memSize = other.memSize;
        bits = new uint32_t[memSize];
    }
    bitLen = other.bitLen;
    for (int i = 0; i < memSize; i++) {
        bits[i] = other.bits[i];
    }
    return *this;
}

int TBitField::GetLength() const {
    return bitLen;
}

void TBitField::SetBit(int n) {
    if (n < 0 || n >= bitLen) return; 
    bits[n / 32] |= (1 << (n % 32));
}

void TBitField::ClrBit(int n) {
    if (n < 0 || n >= bitLen) return;
    bits[n / 32] &= ~(1 << (n % 32));
}

int TBitField::GetBit(int n) const {
    if (n < 0 || n >= bitLen) return 0;
    return (bits[n / 32] >> (n % 32)) & 1;
}

TBitField TBitField::operator|(const TBitField& other) const {
    if (bitLen != other.bitLen) throw std::invalid_argument("Sizes must match");
    TBitField res(bitLen);
    for (int i = 0; i < memSize; i++) {
        res.bits[i] = bits[i] | other.bits[i];
    }
    return res;
}

TBitField TBitField::operator&(const TBitField& other) const {
    if (bitLen != other.bitLen) throw std::invalid_argument("Sizes must match");
    TBitField res(bitLen);
    for (int i = 0; i < memSize; i++) {
        res.bits[i] = bits[i] & other.bits[i];
    }
    return res;
}


TBitField TBitField::operator~() const {
    TBitField res(bitLen);
    for (int i = 0; i < memSize; i++) {
        res.bits[i] = ~bits[i];
    }
    int tail = bitLen % 32;
    if (tail != 0 && memSize > 0) {
        uint32_t mask = (1 << tail) - 1;
        res.bits[memSize - 1] &= mask;
    }
    return res;
}

bool TBitField::operator==(const TBitField& other) const {
    if (bitLen != other.bitLen) return false;
    for (int i = 0; i < memSize; i++) {
        if (bits[i] != other.bits[i]) return false;
    }
    return true;
}

bool TBitField::operator!=(const TBitField& other) const {
    return !(*this == other);
}