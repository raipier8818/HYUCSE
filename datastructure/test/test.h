#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <vector>
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

struct _result
{
    unsigned long success_cnt;
    unsigned long failed_cnt;
    unsigned long error_cnt;
};

template <typename T>
class test
{
private:
    bool asserted;
    unsigned long asserted_idx;
    std::string test_name;
    _result test_result;
    unsigned long test_size;
    unsigned long test_idx;
    void result()
    {
        test_size += test_result.success_cnt + test_result.error_cnt + test_result.failed_cnt;

        printf("[%s Result]\n" ANSI_COLOR_RESET, test_name.c_str());
        printf(ANSI_COLOR_GREEN "Success : %ld/%ld" ANSI_COLOR_RESET "\n", test_result.success_cnt, test_size);
        printf(ANSI_COLOR_MAGENTA "Failed : %ld/%ld" ANSI_COLOR_RESET "\n", test_result.failed_cnt, test_size);
        printf(ANSI_COLOR_RED "Error : %ld/%ld" ANSI_COLOR_RESET "\n", test_result.error_cnt, test_size);
        printf(ANSI_COLOR_GREEN "Success Rate : %.2lf" ANSI_COLOR_RESET "\n", (float)(test_result.success_cnt * 100 / test_size));

        if(asserted)
        {
            printf(ANSI_COLOR_RED "Test Asserted at : %ld" ANSI_COLOR_RESET "\n", test_idx);
        }
    }

    void set_asserted(){
        asserted = true;
        asserted_idx = test_idx;
    }

    void test_result_update(unsigned long success, unsigned long failed, unsigned long error){
        if(asserted){
            test_size++;
            return;
        }
        test_result.success_cnt += success;
        test_result.failed_cnt += failed;
        test_result.error_cnt += error;
    }

public:
    test(){
        asserted = false;
        asserted_idx = 0;
        test_idx = 0;
        test_size = 0;
    }

    void operator()(const std::string test_name)
    {
        this->test_name = test_name;
        result();
    }
    void reset_unit_tests()
    {
        test_result = {0, 0, 0};
    }

    template <typename K>
    void assert_eq(K A, K B)
    {
        test_idx++;
        try{
            if(A != B)
                set_asserted();
            test_result_update(A == B, A != B, 0);
        }
        catch (...)
        {
            test_result_update(0, 0, 1);
        }
    }

    template <typename K>
    void assert_ne(K A, K B)
    {
        test_idx++;
        try
        {
            if (A == B)
                set_asserted();
            test_result_update(A != B, A == B, 0);
        }
        catch (...)
        {
            test_result_update(0, 0, 1);
        }
    }

    template <typename K>
    void expect_eq(K A, K B)
    {
        test_idx++;
        try
        {
            test_result_update(A == B, A != B, 0);
        }
        catch (...)
        {
            test_result_update(0, 0, 1);
        }
    }

    template <typename K>
    void expect_ne(K A, K B)
    {
        test_idx++;
        try
        {
            if (A == B)
                set_asserted();
            test_result_update(A != B, A == B, 0);
        }
        catch (...)
        {
            test_result_update(0, 0, 1);
        }
    }
};

/*

*/

#endif