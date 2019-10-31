#ifndef UD_STRING_ARRAY_H
# define UD_STRING_ARRAY_H

// Lib
#include <ud_utils.h>
#include <ud_math.h>
#include <ud_array.h>

// Macro
# define ud_stra_init(input_len)            ({ ud_arr *arr = ud_arr_tinit(ud_arr_type_char(), input_len + 1); --arr->len; ((char*)arr->val)[arr->len] = '\0'; arr; })
# define ud_stra_set(...)                   ({ ud_arr *arr = ud_arr_tset(char, ud_arr_type_char(), __VA_ARGS__, '\0'); --arr->len; arr; })
# define ud_stra_dup(str)                   ud_stra_ndup(str, 0)
# define ud_stra_fdup(str)                  ud_stra_fndup(str, 0)
# define ud_stra_new(str)                   ({ char *tmp = str; ud_arr_tnew(ud_arr_type_char(), ud_str_len(tmp), tmp); )}
# define ud_stra_snew(str)                  ({ char *tmp = str; ud_arr_tnew(ud_arr_type_char(), ud_str_len(tmp), ud_str_dup(tmp)); )}

# define ud_stra_ctrim(arr, trim)           ({ ud_arr *new_arr = ud_arr_cpy(arr); ud_stra_trim(new_arr, trim); new_arr; })

# define ud_stra_vtrim(arr, ...)            ({ char *trim[] = {__VA_ARGS__, NULL}; ud_stra_trim(arr, trim); })
# define ud_stra_vctrim(arr, ...)           ({ char *trim[] = {__VA_ARGS__, NULL}; ud_stra_ctrim(arr, trim); })

# define ud_stra_vrsplit(str, ...)   	    ({ char *sep[] = {__VA_ARGS__, NULL}; ud_stra_rsplit(str, sep); })

# define ud_stra_join(str, sep)             ud_stra_join_ctr(str, sep, false)
# define ud_stra_fjoin(str, sep)            ud_stra_join_ctr(str, sep, true)

# define ud_stra_vjoin(sep, ...)            ud_stra_join(ud_arr_tset(ud_arr*, ud_arr_type_arr(), __VA_ARGS__), sep);
# define ud_stra_vfjoin(sep, ...)           ud_stra_fjoin(ud_arr_tset(ud_arr*, ud_arr_type_arr(), __VA_ARGS__), sep);

# define ud_stra_rjoin(str, sep)            ud_stra_rjoin_ctr(str, sep, false)
# define ud_stra_rfjoin(str, sep)           ud_stra_rjoin_ctr(str, sep, true)

# define ud_stra_vrjoin(str, ...)           ({ char *sep[] = {__VA_ARGS__, NULL}; ud_stra_rjoin(str, sep); })
# define ud_stra_vrfjoin(str, ...)          ({ char *sep[] = {__VA_ARGS__, NULL}; ud_stra_rfjoin(str, sep); })
// Structures  

// Prototypes
ud_arr_type                                 *ud_arr_type_char(void);
int                                         ud_stra_chr(ud_arr_char_a *str, char c);
int                                         ud_stra_cmp(ud_arr_char_a *s1, ud_arr_char_a *s2);
int                                         ud_stra_ncmp(ud_arr_char_a *s1, ud_arr_char_a *s2, size_t n);
ud_arr_char_a                               *ud_stra_ctoa(char c);
ud_arr_char_a                               *ud_stra_ndup(ud_arr_char_a *str, size_t len);
ud_arr_char_a                               *ud_stra_fndup(ud_arr_char_a *str, size_t len);
ud_arr_char_a                               *ud_stra_fill(char c, size_t len);
ud_arr_char_a                               *ud_stra_fcat(ud_arr_char_a *head, ud_arr_char_a *tail);
ud_arr_char_a                               *ud_stra_fsub(ud_arr_char_a *str, size_t start, size_t len);
ud_arr_char_a                               *ud_stra_cat(ud_arr_char_a *head, ud_arr_char_a *tail);
ud_arr_char_a                               *ud_stra_sub(ud_arr_char_a *str, size_t start, size_t len);
size_t                                      ud_stra_len(ud_arr_char_a *str);
ud_arr_str_a                                *ud_stra_split(ud_arr_char_a *str, char *sep);
ud_arr_str_a                                *ud_stra_rsplit(ud_arr *str, char **floor_sep);
ud_arr_char_a                               *ud_stra_join_ctr(ud_arr *str, char *sep, ud_bool need_free);
ud_arr_char_a                               *ud_stra_rjoin_ctr(ud_arr *str, char **sep, ud_bool need_free);
void                                        ud_stra_trim(ud_arr *arr, char **trim);
ud_arr_char_a                               *ud_stra_escape(ud_arr_char_a *str);
ud_arr_char_a                               *ud_stra_whitespace(ud_arr_char_a *str);

#endif