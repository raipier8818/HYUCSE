#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <vector>
#include <stdio.h>

struct _result{
    unsigned long long success_cnt;
    unsigned long long failed_cnt;
    unsigned long long error_cnt;
};

template<typename T>
struct _unit_test{
    bool (*fun_ptr)(T, T);
    T A;
    T B;
};

template<typename T>
void assert_eq(T A, T B){
    return A == B;
}

template<typename T>
void assert_ne(T A, T B){
    return A != B;
}

template<typename T>
void expect_eq(T A, T B){
    return A == B;
}

template<typename T>
void expect_ne(T A, T B){
    return A != B;
}


template<typename T>
_unit_test<T> unit_test(bool (*fun_ptr)(), T A, T B);

template<typename T>
_unit_test<T> unit_test(bool (*fun_ptr)(T,T), T A, T B){
    _unit_test t = {fun_ptr, A, B};

    return t;
}


template<typename T>
class test{
    private:
    std::string test_name;
    std::vector<_unit_test<T>> unit_tests;
    _result test_result;
    void result(){
        printf("[%s Result]\n", test_name);
        printf("Success : %d/%d\n", test_result.success_cnt, unit_tests.size());
        printf("Failed : %d/%d\n", test_result.failed_cnt, unit_tests.size());
        printf("Error : %d/%d\n", test_result.error_cnt, unit_tests.size());
        printf("Success Rate : %.2f\n", (float)test_result.success_cnt*100/(float)unit_tests.size());
    }

    public:
    void operator()(const std::string test_name){
        this->test_name = test_name;
        int test_idx = 0;
        for(; test_idx < unit_tests.size(); test_idx++){
            _unit_test t = unit_tests[test_idx];
            
            try{
                bool unit_test_result = t.fun_ptr(t.A, t.B);
                if(t.fun_ptr == assert_eq || t.fun_ptr == assert_ne){
                    throw test_idx;
                }

                if(unit_test_result) test_result.success_cnt++;
                else test_result.failed_cnt++;
            }catch(int assert_idx){
                result();
                printf("Asserted at %d\n", assert_idx);
                return;
            }catch(...){
                printf("Error occured at %d\n", test_idx);
                test_result.error_cnt++;
            }
        }

        result();
    }
    void set_test(std::vector<_unit_test<T>>& unit_tests){
        this->unit_tests = unit_tests;
    }
    void reset_test(){
        this->unit_tests.clear();
    }

};


/*

*/


#endif