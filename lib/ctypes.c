int isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

int islower(int c) {
    return c >= 'a' && c <= 'z';
}

int isupper(int c) {
    return c >= 'A' && c <= 'Z';
}

int isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int isalpha(int c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int isalnum(int c) {
    return (isalpha(c) || isdigit(c));
}

int tolower(int c) {
    if (isalpha(c)) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
    }
    return c;
}

int toupper(int c) {
    if (islower(c))
        return c - 'a' + 'A';
    return c;
}
