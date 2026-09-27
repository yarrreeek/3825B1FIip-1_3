#include "pch.h"
#include <gtest/gtest.h>   
#include "../lab1/TBitset.h"
#include "../lab1/TSet.h"

TEST(TBitFieldTest, Initialization) {
    TBitField bf(8);
    EXPECT_EQ(bf.GetLength(), 8);
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(bf.GetBit(i), 0);
    }
}

TEST(TBitFieldTest, SetAndClear) {
    TBitField bf(8);
    bf.SetBit(3);
    EXPECT_EQ(bf.GetBit(3), 1);
    bf.ClrBit(3);
    EXPECT_EQ(bf.GetBit(3), 0);
}

TEST(TSetTest, AddAndRemove) {
    TSet set(10);
    set.Add(5);
    EXPECT_TRUE(set.Contains(5));
    EXPECT_FALSE(set.Contains(1));

    set.Remove(5);
    EXPECT_FALSE(set.Contains(5));
}

TEST(TSetTest, UnionOperation) {
    TSet a(10);
    TSet b(10);

    a.Add(1); a.Add(2);
    b.Add(2); b.Add(3);

    TSet result = a.Union(b);

    EXPECT_TRUE(result.Contains(1));
    EXPECT_TRUE(result.Contains(2));
    EXPECT_TRUE(result.Contains(3));
    EXPECT_FALSE(result.Contains(4));
}

TEST(TSetTest, EmptyAndFull) {
    TSet set(5);

    EXPECT_TRUE(set.IsEmpty());
    EXPECT_FALSE(set.IsFull());

    for (int i = 0; i <= 5; i++) {
        set.Add(i);
    }

    EXPECT_TRUE(set.IsFull());
}