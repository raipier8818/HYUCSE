#include <vector>
#include "../test/test.h"
#include "stack.h"

typedef test<int> Test;
typedef stack<int> Stack;

int generate_random_int(int start=0, int end=1000){
    srand(time(NULL));
    return start + rand()%(end-start);
}

void stack_push_test(Test t, Stack s)
{
    std::vector<int> inputs;

    int epoch = 10000;
    for (int i = 0; i < epoch; i++)
    {
        inputs.push_back(generate_random_int(0, 1000));
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
        inputs.push_back(generate_random_int(0, 1000));
        s.push(inputs[i]);
    }

    for (int i = 0; i < epoch; i++)
    {
        t.assert_eq(s.top(), inputs[i]);
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