#include "documentation_module.h"

#include <stdio.h>
#include <stdlib.h>
int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
