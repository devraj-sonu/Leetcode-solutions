char* longestCommonPrefix(char** strs, int strsSize) {
    static char prefix[201]; // buffer for result
    prefix[0] = '\0';

    if (strsSize == 0) return prefix;  // empty input

    // Start with the first string as initial prefix
    char* first = strs[0];
    int i;

    for (i = 0; first[i]; i++) { // loop through characters of first string
        for (int j = 1; j < strsSize; j++) { // compare with all other strings
            if (strs[j][i] != first[i] || strs[j][i] == '\0') {
                prefix[i] = '\0'; // terminate at mismatch
                return prefix;
            }
        }
        prefix[i] = first[i]; // add matching character
    }

    prefix[i] = '\0'; // terminate string
    return prefix;
}
