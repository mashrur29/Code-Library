string multiply(string a, int b) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for(int i = 0; i < a.size(); i++) {
        carry += (a[i] - 48) * b;
        a[i] = (carry % 10 + 48);
        carry /= 10;
    }
    while(carry) {
        a += (carry % 10 + 48);
        carry /= 10;
    }
    return a;
}
