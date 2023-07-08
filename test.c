#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

typedef struct s_trings {
    char *param1;
    char *param2;
    char *param3;
} t_strings;

static int set_color(char *color, char result[1024]) {
    int color_len;
    int result_idx;

    color_len = 0;
    result_idx = 0;
    if (color) {
        color_len = strlen(color);
        strncpy(result, color, 1023);
        result_idx += color_len;
    }
    return (result_idx);
}

char *mini_printf(char *format, char *color, t_strings strs) {
    static char result[1024] = {0};
    size_t result_idx = 0;
    size_t format_idx = 0;
    size_t param_len = 0;

    result_idx = set_color(color, result);
    while (format[format_idx]) {
        if (format[format_idx] == '%' && format[format_idx + 1] == 's') {
            if (strs.param1) {
                param_len = strlen(strs.param1);
                strncpy(result + result_idx, strs.param1,
                        sizeof(result) - result_idx - 1);
                result_idx += param_len;
                strs.param1 = strs.param2;
                strs.param2 = strs.param3;
                strs.param3 = NULL;
            }
            format_idx += 2;
        } else
            result[result_idx++] = format[format_idx++];
    }
    strncat(result, RESET, strlen(result));
    return (result);
}

int main(void) {
    char *param1;
    char *param2;
    char *param3;
    char *result;

    param1 = "value1";
    param2 = "value2";
    param3 = "value3";
    result = mini_printf("Example %s=%s and %s something %s", CYAN,
                         (t_strings){param1, param2, param3});
    printf("%s\n", result);
    printf("test reset\n");
    return (0);
}
