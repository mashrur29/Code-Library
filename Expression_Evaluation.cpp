string InfixPostfix(string s) {
    stack<char> stk;
    string ret = "";

    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') stk.push(s[i]);
        else if(s[i]==')') {
            while(!stk.empty() && stk.top()!='(') {
                ret += stk.top();
                stk.pop();
            }
            if(!stk.empty()) stk.pop();
        }
        if(s[i]>='a' && s[i]<='z') ret += s[i];
        if(s[i]=='*') stk.push(s[i]);
        else if(s[i]=='+') {
            while(!stk.empty() && stk.top()!='+' && stk.top()!='(') {
                ret += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }

    while(!stk.empty()) {
        ret += stk.top();
        stk.pop();
    }

    return ret;
}

long long PostfixValue(string s) {
    stack<long long> stk;
    //cout<<s<<endl;

    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a' && s[i]<='z') stk.push(mp_res[s[i]]);
        else {
            long long res;
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            if(s[i]=='+') res = a + b;
            else res = a * b;
            stk.push(res);
        }
    }

    return stk.top();
}
