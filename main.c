/*************************************************************************
	> File Name: main.c
	> Author: Jasonhuang
	> Mail: acejasonhuang@163.com
	> Created Time: Sat 31 Oct 2020 08:26:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include"c_test/test.h"

double add(double a, double b){
    return a + b;
}

TEST(testfunc, add){
    EXPECT_EQ(add(2, 3), 5);    
    EXPECT_NE(add(7, 8), 5);
    EXPECT_EQ(add(4, 1), 5);
    EXPECT_EQ(add(0, 1), 1);
}
TEST(testfunc, add2){
    EXPECT_EQ(add(2, 2), 4);    
    EXPECT_GE(add(7, 8), 5);
    EXPECT_EQ(add(4, 1), 5);
    EXPECT_GT(add(0, 1), 1);
}
TEST(testfunc, add3){
    EXPECT_EQ(add(2, 2), 4);    
    EXPECT_LE(add(1, 3), 5);
    EXPECT_LT(add(4, 1), 5);
    EXPECT_EQ(add(0, 1), 1);
}
int main(){
    return RUN_ALL_TESTS();
}

