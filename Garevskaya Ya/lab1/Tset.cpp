#include "pch.h"
#include "../lab1/TSet.h"
#include <iostream>
#include <stdexcept>

TSet::TSet(int maxPower) : bf(maxPower + 1) {
}

void TSet::Add(int elem) {
    if (elem < 0 || elem >= bf.GetLength()) {
        return;
    }
    bf.SetBit(elem);
}

void TSet::Remove(int elem) {
    if (elem < 0 || elem >= bf.GetLength()) {
        return;
    }
    bf.ClrBit(elem);
}

bool TSet::Contains(int elem) const {
    if (elem < 0 || elem >= bf.GetLength()) return false;
    return bf.GetBit(elem) == 1;
}

bool TSet::IsEmpty() const {
    for (int i = 0; i < bf.GetLength(); i++) {
        if (bf.GetBit(i) == 1) return false;
    }
    return true;
}

bool TSet::IsFull() const {
    for (int i = 0; i < bf.GetLength(); i++) {
        if (bf.GetBit(i) == 0) return false;
    }
    return true;
}

int TSet::GetMaxPower() const {
    return bf.GetLength() - 1;
}

TSet TSet::Union(const TSet& other) const {
    if (this->bf.GetLength() != other.bf.GetLength()) {
        throw std::invalid_argument("Sets must be of the same size");
    }
    TSet res(this->GetMaxPower());
    res.bf = this->bf | other.bf;
    return res;
}

TSet TSet::Intersection(const TSet& other) const {
    if (this->bf.GetLength() != other.bf.GetLength()) {
        throw std::invalid_argument("Sets must be of the same size");
    }
    TSet res(this->GetMaxPower());
    res.bf = this->bf & other.bf;
    return res;
}

TSet TSet::Difference(const TSet& other) const {
    if (this->bf.GetLength() != other.bf.GetLength()) {
        throw std::invalid_argument("Sets must be of the same size");
    }
    TSet res(this->GetMaxPower());
    res.bf = this->bf & (~other.bf);
    return res;
}

TSet TSet::Complement() const {
    TSet res(this->GetMaxPower());
    res.bf = ~this->bf;
    return res;
}

bool TSet::operator==(const TSet& other) const {
    return this->bf == other.bf;
}

bool TSet::operator!=(const TSet& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const TSet& set) {
    os << "{ ";
    bool first = true;
    for (int i = 0; i < set.bf.GetLength(); i++) {
        if (set.bf.GetBit(i) == 1) {
            if (!first) os << ", ";
            os << i;
            first = false;
        }
    }
    os << " }";
    return os;
}