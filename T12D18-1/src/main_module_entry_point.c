#include <stdio.h>
#ifdef print_module
#include "print_module.h"
#endif

int main() {
#ifdef print_module
    print_log(print_char, Module_load_success_message);
#endif
    return 0;
}
