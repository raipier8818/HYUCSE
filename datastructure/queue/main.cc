#include <vector>
#include "../test/test.h"

typedef test<int> Test;

int generate_random_int(int start=0, int end=1000){
    srand(time(NULL));
    return start + rand()%(end-start);
}

int main(){
    
}