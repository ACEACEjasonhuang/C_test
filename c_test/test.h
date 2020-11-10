/*************************************************************************
	> File Name: test.h
	> Author: Jasonhuang
	> Mail: acejasonhuang@163.com
	> Created Time: Fri 06 Nov 2020 03:26:20 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include<c_test/linklist.h>
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a,32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a,34)
#define YELLO(a) COLOR(a,33)
#define PURPLE(a) COLOR(a,35)

#define GREEN_HL(a) COLOR_HL(a,32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a,34)
#define YELLO_HL(a) COLOR_HL(a,33)
#define PURPLE_HL(a) COLOR_HL(a,35)

#define TEST(a, b) \
void a##_##b();\
__attribute__((constructor))\
void add##_##a##_##b(){\
    add_function(a##_##b, #a "." #b);\
}\
void a##_##b()

#define Type(a) _Generic((a),\
    int : "%d", \
    double : "%lf", \
    float : "%f", \
    long long : "%lld", \
    const char* : "%s", \
    char * : "%s" \
)
#define P(a, color) {\
    char str_temp[100];\
    sprintf(str_temp, color("%s"), Type(a));\
    printf(str_temp, a);\
}

#define EXPECT(a, b, comp) {\
    c_test_info.total++;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if (_a comp _b) c_test_info.success++;\
    else{\
        printf("\n");\
        printf(YELLO_HL("\t%s:%d: failure\n"), __FILE__, __LINE__);\
        printf(YELLO_HL("\t\texpect : " #a " " #comp " " #b "\n\t\t" "actual : " ));\
        P(_a, YELLO_HL);\
        printf(YELLO_HL(" vs "));\
        P(_b, YELLO_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------] "));\
    printf("%s %s %s  %s\n" ,#a, #b, #comp, _a comp _b? GREEN("True") : RED("False"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)

typedef void(*TestFuncT)();

typedef struct Function{
    TestFuncT func;
    const char* str;
    struct LinkNode p;
}Function;
struct FunctionInfo{
    int total, success;
}; 
extern struct FunctionInfo c_test_info;
int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
#endif
