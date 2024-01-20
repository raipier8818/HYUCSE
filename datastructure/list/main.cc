#include <vector>
#include "../test/test.h"
#include "linked_list.h"
#include "circular_linked_list.h"

typedef test<int> Test;
typedef linked_list<int> Linked_list;
typedef circular_linked_list<int> Circular_linked_list;

int generate_random_int(int start=0, int end){
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
        l.insert(generate_random_int(0, l.size()), inputs[i]);
        
    }

}

void linked_list_push_test(Test t){

}


void linked_list_test(){
    Test t;
    Linked_list l;
    
}



int main(){
    
}