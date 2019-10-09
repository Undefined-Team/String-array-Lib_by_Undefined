#include <ud_string.h>
#include <ud_array.h>
#include <ud_string_array.h>
#include <assert.h>

int main(void)
{
    ud_arr *a = ud_arr_set(char, 'a');
    ud_arr *abc = ud_arr_set(char, 'a', 'b', 'c');
    ud_arr *de = ud_arr_set(char, 'd', 'e');
    ud_arr *aaaaa = ud_arr_set(char, 'a', 'a', 'a', 'a', 'a');
    ud_arr *abcde = ud_arr_set(char, 'a', 'b', 'c', 'd', 'e');
    ud_arr *abzde = ud_arr_set(char, 'a', 'b', 'z', 'd', 'e');
    ud_arr *abade = ud_arr_set(char, 'a', 'b', 'a', 'd', 'e');
    ud_arr *null = ud_arr_set(char, 'a');
    null->val = NULL;
    null->len = 0;

    ud_ut_time("%s", "Starting tests...");
    // Basic tests
    assert(ud_stra_cmp(abade, abzde) == 'a' - 'z');
    assert(ud_stra_cmp(abcde, abcde) == 0);
    assert(ud_stra_cmp(null, abcde) == -1);
    assert(ud_stra_cmp(ud_stra_dup(abcde), abcde) == 0);
    assert(ud_stra_chr(null, 'a') == -1);
    assert(ud_stra_chr(abcde, 'a') == 0);
    assert(ud_stra_chr(abcde, 'c') == 2);
    assert(ud_stra_chr(abcde, 'f') == -1);
    assert(!ud_stra_cmp(ud_stra_fill('a', 5), aaaaa));
    assert(!ud_stra_cmp(ud_stra_join(abc, de), abcde));
    assert(!ud_stra_cmp(ud_stra_sub(abcde, 0, 3), abc));
    assert(!ud_stra_cmp(ud_stra_sub(abcde, 3, 2), de));
    assert(!ud_stra_cmp(ud_stra_ctoa('a'), a));
    ud_arr *test = ud_stra_vjoin(",", "test", "b", "mdr", "allo");
    ud_arr_print(test, char, "%c");
    assert(!ud_stra_cmp(ud_stra_vjoin("test", "b", "mdr", "allo"), ud_arr_new(sizeof(char), 13, "testbmdrallo")));
    ud_ut_time("%s", "All tests passed.");

    // printf("%zd\n", UD_ARGS_LEN(int, 1, 2, 3));
    // // return 0;
    // char value[] = ",,2,";
    // ud_arr  *str = ud_arr_new(sizeof(char), 4, value);
    // ud_arr_print(str, char, "%c");
    // ud_arr  *splitted = ud_str_split(str, ",");
    // // printf("splitted len = %zd\n", splitted->len);
    // ud_arr *before_test =  ud_arr_init(sizeof(char), 0);
    // printf("splitted:\n");
    // ud_arr_print(splitted, char, "|%c| ");
    // printf("before_test:\n");
    // ud_arr_print(before_test, char, "|%c| ");
    // // ud_arr *test = ud_arr_init(0, 2);
    // printf("add real = %p\n", splitted);
    // printf("auto:\n");
    // ud_arr *test = ud_arr_set(ud_arr*, splitted, before_test);
    // // printf("auto len = %zd\n", test->len);
    // // ud_arr **val = (ud_arr**)test->val;
    // // printf("elemt1 len = %zd\n", val[0]->len);
    // // ud_arr_print(val[0], char, "|%c| ");

    // ud_arr_print(test, char, "|%c| ");
    // // ud_arr_rfree(test);

    // test = ud_arr_init(0, 2);
    // ud_arr **val = (ud_arr**)test->val;
    // val[0] = before_test;
    // val[1] = splitted;
    // printf("manual:\n");
    // ud_arr_print(test, char, "|%c| ");
    // ud_arr_rfree(test);
    // // ud_arr *test_set = ud_arr_set(int, 2, 3);
    // // ud_arr_print(test_set, int, "%d ");



    // ud_arr_free(str);
    return 0;
}