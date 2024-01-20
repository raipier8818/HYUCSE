#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <vector>
#include <stdio.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

struct _result{
    unsigned long success_cnt;
    unsigned long failed_cnt;
    unsigned long error_cnt;
};

template<typename T>
struct _unit_test{
    bool (*func_ptr)(T, T);
    T A;
    T B;
};

template<typename T>
bool assert_eq(T A, T B){
    if(A != B) throw A;
    return A == B;
}

template<typename T>
bool assert_ne(T A, T B){
    if(A == B) throw A;
    return A != B;
}

template<typename T>
bool expect_eq(T A, T B){
    return A == B;
}

template<typename T>
bool expect_ne(T A, T B){
    return A != B;
}


template<typename T>
class test{
    private:
    std::string test_name;
    std::vector<_unit_test<T>> unit_tests;
    _result test_result;
    void result(){
        printf( "[%s Result]\n" ANSI_COLOR_RESET, test_name.c_str());
        printf(ANSI_COLOR_GREEN "Success : %ld/%ld" ANSI_COLOR_RESET "\n", test_result.success_cnt, unit_tests.size());
        printf(ANSI_COLOR_MAGENTA "Failed : %ld/%ld" ANSI_COLOR_RESET "\n", test_result.failed_cnt, unit_tests.size());
        printf(ANSI_COLOR_RED "Error : %ld/%ld" ANSI_COLOR_RESET "\n", test_result.error_cnt, unit_tests.size());
        printf(ANSI_COLOR_GREEN "Success Rate : %.2lf" ANSI_COLOR_RESET "\n", (float)(test_result.success_cnt*100/unit_tests.size()));
    }

    public:
    void operator()(const std::string test_name){
        this->test_name = test_name;
        int test_idx = 0;
        for(; test_idx < unit_tests.size(); test_idx++){
            _unit_test t = unit_tests[test_idx];
            
            try{
                bool (*test_func)(T, T) = t.func_ptr;
                bool unit_test_result = test_func(t.A, t.B);

                if(unit_test_result) test_result.success_cnt++;
                else test_result.failed_cnt++;
            }catch(int assert_value){
                result();
                printf("Asserted at %d (value : %d)\n", test_idx, assert_value);
                return;
            }catch(...){
                printf("Error occured at %d\n", test_idx);
                test_result.error_cnt++;
            }
        }

        result();
    }
    void reset_unit_tests(){
        this->unit_tests.clear();
    }

    _unit_test<T> unit_test(bool (*func_ptr)(T,T), T A, T B){
        _unit_test<T> t = {func_ptr, A, B};
        unit_tests.push_back(t);
        return t;
    }
};


/*

*/


#endif