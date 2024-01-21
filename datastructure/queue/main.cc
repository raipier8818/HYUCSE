#include <vector>
#include "../test/test.h"
#include "queue.h"

typedef test<int> Test;
typedef queue<int> Queue;

int generate_random_int(int start=0, int end=1000){
    srand(time(NULL));
    return start + rand()%(end-start);
}
void queue_push_test(Test t, Queue q)
{
    std::vector<int> inputs;

    int epoch = 10000;
    for (int i = 0; i < epoch; i++)
    {
        inputs.push_back(generate_random_int(0, 1000));
    }

    for (int i = 0; i < epoch; i++)
    {
        q.push(inputs[i]);
        t.assert_eq(q.front(), inputs[i]);
    }

    t.assert_eq<int>(q.size(), epoch);
    q.clear();
    t.assert_eq<int>(q.size(), 0);
    t("push & clear test");
    t.reset_unit_tests();
}

void queue_pop_test(Test t, Queue q)
{
    std::vector<int> inputs;

    int epoch = 10000;
    for (int i = 0; i < epoch; i++)
    {
        inputs.push_back(generate_random_int(0, 1000));
        q.push(inputs[i]);
    }

    for (int i = 0; i < epoch; i++)
    {
        t.assert_eq(q.front(), inputs[i]);
        q.pop();
    }

    t.assert_eq<int>(q.size(), 0);
    q.clear();
    t.assert_eq<int>(q.size(), 0);
    t("push & pop test");
    t.reset_unit_tests();
}

void queue_test(){
    Test t;
    Queue q;

    queue_push_test(t, q);
    queue_pop_test(t, q);
}

int main(){
    queue_test();
}