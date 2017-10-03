void preKMP(char *pattern, int f[]) {
    const int m = strlen(pattern);
    int i = 0, j = -1;

    f[i] = -1;
    while(i < m) {
        while(j >= 0 && pattern[i] != pattern[j]) j = f[j];

        i++;
        j++;

        f[i] = j;
    }
}


int kmp(char *target, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(target);
    int f[m];

    preKMP(pattern, f);

    int cnt = 0;
    int i = 0;
    int k = 0;

    while(i < n) {
        while(k>=0 && pattern[k] != target[i]) k = f[k];

        i++;
        k++;

        if(k == m) {
            cnt++;
            k = f[k];
        }
    }

    return cnt;
}
