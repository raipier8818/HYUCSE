#include "linked_list.h"
#include <iostream>

using namespace std;





int main(){
    linked_list list;
    
    list.insert(0,1);
    list.push(11);
    list.print();
    list.remove(11);
    list.print();
    list.remove(1);
    list.print();

    // cout << list.find(11) << endl;   
}