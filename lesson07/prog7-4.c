 /*********************************************
  prog7-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int check(char *text)
{
    return 0;
}

/*=============================================*/

void test1()
{
    assert(check("{ a [ ( xyz) ] }"));

    printf("Success: %s\n", __func__);
}

void test2()
{
    assert(check("{{( )}}"));

    printf("Success: %s\n", __func__);
}

void test3()
{
    assert(!check("{"));

    printf("Success: %s\n", __func__);
}

void test4()
{
    assert(!check("{{{}}}}"));

    printf("Success: %s\n", __func__);
}

void test5()
{
    assert(!check("{{ ]}"));

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
