#include <vector>
#include "../test/test.h"
#include "linked_list.h"
#include "circular_linked_list.h"

typedef test<int> Test;
typedef linked_list<int> Linked_list;
typedef circular_linked_list<int> Circular_linked_list;

int generate_random_int(int start=0, int end=1000){
    srand(time(NULL));
    return start + rand()%(end-start);
}


void linked_list_insert_test(Test t, Linked_list l){
    std::vector<int> inputs;
    
    int epoch = 10000;
    for(int i = 0; i < epoch; i++){
        inputs.push_back(generate_random_int(0, 1000));
    }

    for(int i = 0; i < epoch; i++){
        l.insert(i, inputs[i]);
    }

    for(int i = 0; i < epoch; i++){
        t.unit_test(assert_eq, l.find(inputs[i]), inputs[i]);
    }

    t("insert test");
    t.reset_unit_tests();
    l.clear();
}

void linked_list_push_test(Test t, Linked_list l){
    std::vector<int> inputs;

    int epoch = 10000;
    for(int i = 0; i < epoch; i++){
        inputs.push_back(generate_random_int(0, 1000));
    }

    for(int i = 0; i < epoch; i++){
        l.push(inputs[i]);
    }

    for(int i = 0; i < epoch; i++){
        t.unit_test(assert_eq, l.find(inputs[i]), inputs[i]);
    }

    t("push test");
    t.reset_unit_tests();
    l.clear();
}


void linked_list_remove_test(Test t, Linked_list l){
    std::vector<int> inputs;

    int epoch = 10;
    for(int i = 0; i < epoch; i++){
        inputs.push_back(generate_random_int(0, 1000));
    }

    for(int i = 0; i < epoch; i++){
        l.push(inputs[i]);
    }

    for(int i = 0; i < epoch; i++){
        l.remove(inputs[i]);
    }

    t.unit_test(assert_eq, l.empty(), true);

    t("remove test");
    t.reset_unit_tests();
    l.clear();
}


void linked_list_test(){
    Test t;
    Linked_list l;
    
    linked_list_insert_test(t, l);
    linked_list_push_test(t, l);
    linked_list_remove_test(t, l);    
}

void circular_linked_list_test(){
    Test t;
    Circular_linked_list c;

    linked_list_insert_test(t, c);
    linked_list_push_test(t, c);
    linked_list_remove_test(t, c);    
}



int main(){
    linked_list_test();
    circular_linked_list_test();
}