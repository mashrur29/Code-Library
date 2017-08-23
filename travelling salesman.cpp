// Travelling salesman problem

struct pp {
    int x, y;
};

pp b[20];

int Set(int N,int pos) {
    return N=N | (1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

int dis(pp a1, pp b1) {
    return max(abs(a1.x - b1.x), abs(a1.y - b1.y));
}

int tsp(int mask, int pos) {
    if(mask==(1<<cn)-1) {
        return dis(b[0], b[pos]);
    }

    if(dp[mask][pos]!=-1) return dp[mask][pos];
    
    int ret = 100000001;
    for(int i=0; i<=cnt; i++) {
        if(!check(mask, i)) ret = min(ret, dis(b[pos], b[i])+tsp(Set(mask, i), i));
    }

    return dp[mask][pos] = ret;
}
