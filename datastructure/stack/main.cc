#include <vector>
#include "../test/test.h"
#include "stack.h"
#include <iostream>

typedef test<int> Test;
typedef stack<int> Stack;


void stack_push_test(Test t, Stack s)
{
    std::vector<int> inputs;

    int epoch = 10000;
    for (int i = 0; i < epoch; i++)
    {
        inputs.push_back(t.generate_random_int(0, 1000));
    }

    for (int i = 0; i < epoch; i++)
    {
        s.push(inputs[i]);
    }

    t.assert_eq<int>(s.size(), epoch);
    s.clear();
    t.assert_eq<int>(s.size(), 0);
    t("push & clear test");
    t.reset_unit_tests();
}

void stack_pop_test(Test t, Stack s)
{
    std::vector<int> inputs;

    int epoch = 10000;
    for (int i = 0; i < epoch; i++)
    {
        inputs.push_back(t.generate_random_int(0, 1000));
        s.push(inputs[i]);
    }

    for (int i = 0; i < epoch; i++)
    {
        t.assert_eq(s.top(), inputs[epoch-1-i]);
        s.pop();
    }

    t.assert_eq<int>(s.size(), 0);
    s.clear();
    t.assert_eq<int>(s.size(), 0);
    t("push & pop test");
    t.reset_unit_tests();
}

void stack_test(){
    Test t;
    Stack s;

    stack_push_test(t, s);
    stack_pop_test(t, s);
}

int main(){
    stack_test();
}