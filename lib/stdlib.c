#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

static int rand_state[256];
static int rand_count = 0;

double strtod(const char *str, char **endptr){
  double result = 0.0;
  int sign = 1;
  int i = 0;

   while (isspace(str[i])) {
        i++;
    }

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    while (isdigit(str[i])) {
        result = result * 10.0 + (str[i++] - '0');
    }

    if (str[i] == '.') {
        double factor = 0.1;
        i++;
        while (isdigit(str[i])) {
            result = result + (factor * (str[i] - '0'));
            factor *= 0.1;
            i++;
        }
    }

    if (str[i] == 'e' || str[i] == 'E') {
        int expSign = 1;
        int expValue = 0;
        i++;
        if (str[i] == '-' || str[i] == '+') {
            expSign = (str[i++] == '-') ? -1 : 1;
        }
        while (isdigit(str[i])) {
            expValue = expValue * 10 + (str[i++] - '0');
        }
        double expFactor = 1.0;
        while (expValue > 0) {
            expFactor *= 10.0;
            expValue--;
        }
        result = (expSign > 0) ? result * expFactor : result / expFactor;
    }

    if (endptr != NULL) {
        *endptr = (char*)&str[i];
    }

    return result * sign;
}

long int strtol(const char *str, char **endptr, int base)
{
    long int result = 0;
    bool negative = false;
    size_t i = 0;

    while (isspace(str[i]))
    {
        i++;
    }

    if (str[i] == '-')
    {
        negative = true;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    if (base == 0)
    {
        if (str[i] == '0')
        {
            if (str[i + 1] == 'x' || str[i + 1] == 'X')
            {
                base = 16;
                i += 2;
            }
            else
            {
                base = 8;
                i++;
            }
        }
        else
        {
            base = 10;
        }
    }

    // Converter dígitos numéricos para inteiro
    while (isalnum(str[i]))
    {
        int digit;
        if (isdigit(str[i]))
        {
            digit = str[i] - '0';
        }
        else if (isalpha(str[i]))
        {
            digit = tolower(str[i]) - 'a' + 10;
        }
        else
        {
            break;
        }

        if (digit >= base)
        {
            break;
        }

        result = result * base + digit;
        i++;
    }

    // Definir endptr se necessário
    if (endptr != NULL)
    {
        *endptr = (char *)&str[i];
    }

    // Definir sinal do número
    if (negative)
    {
        result = -result;
    }

    return result;
}

int atoi(const char *str)
{
    return (int)strtol(str, NULL, 10);
}

void srand(unsigned int seed) {
    int i;
    uint32_t r = seed;

    for (i = 0; i < 256; i++) {
        rand_state[i] = r;
        r = (r + 0x9e3779b9) & 0xFFFFFFFF;
    }
}

int rand(void) {
    uint32_t x, y, t;
    static uint32_t isaac_rand_result = 0;

    rand_count++;

    for (int i = 0; i < 256; i++) {
        x = rand_state[i];
        if (i & 1) {
            isaac_rand_result ^= isaac_rand_result << 13;
        } else {
            isaac_rand_result ^= isaac_rand_result >> 6;
        }
        isaac_rand_result ^= x;
        t = rand_state[(i + 128) & 0xFF] + isaac_rand_result;
        rand_state[i] = y = rand_state[(t >> 2) & 0xFF] + t;
        // Store the result in the next round
        rand_state[(t >> 10) & 0xFF] = x = rand_state[(y >> 16) & 0xFF] + (t << 1);
    }

    return isaac_rand_result;
}

void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {
    if (nmemb <= 1) {
        return;
    }

    char* base_ptr = (char*)base;
    char* pivot = base_ptr + (nmemb / 2) * size;
    char* left = base_ptr;
    char* right = base_ptr + (nmemb - 1) * size;

    while (left <= right) {
        while (compar(left, pivot) < 0) {
            left += size;
        }

        while (compar(right, pivot) > 0) {
            right -= size;
        }

        if (left <= right) {
            for (size_t i = 0; i < size; ++i) {
                char temp = left[i];
                left[i] = right[i];
                right[i] = temp;
            }
            left += size;
            right -= size;
        }
    }

    size_t left_size = ((right - base_ptr) / size) + 1;
    size_t right_size = (nmemb - left_size);

    qsort(base_ptr, left_size, size, compar);
    qsort(left, right_size, size, compar);
}

void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {
    const char* base_ptr = (const char*)base;

    size_t left = 0;
    size_t right = nmemb;

    while (left < right) {
        size_t middle = left + (right - left) / 2;
        const void* middle_element = base_ptr + middle * size;
        int comparison = compar(key, middle_element);

        if (comparison < 0) {
            right = middle;
        } else if (comparison > 0) {
            left = middle + 1;
        } else {
            return (void*)middle_element;
        }
    }

    return NULL;
}
