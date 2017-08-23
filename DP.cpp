// coin change (is it possible to make a sum)

int coin[]={5,8,11,15,18}; //value of coins available
int make=18; //we will try to make 18
int dp[6][100];
int call(int i,int amount)
{
    if(i>=5) { //All coins have been taken
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount]; //no need to calculate same state twice
    int ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1=call(i,amount-coin[i]); //try to take coin i
    ret2=call(i+1,amount); //dont take coin i
    return dp[i][amount]=ret1|ret2; //storing and returning.
    
}
int main()
{
    // freopen("in","r",stdin);
    memset(dp,-1,sizeof(dp));
    while(cin>>make)
    {
        cout<<call(0,make)<<endl;
    }
    return 0;
}

// coin change (number of ways)

just return ret1+ret2

// Rock climbing (max point which the player can make by moving from (0,0) )

#define inf 1 << 28
int mat[][10] = {
    { -1, 2, 5 },
    { 4, -2, 3 },
    {
        1, 2, 10,
    }
};
int dp[10][10];
int r = 3, c = 3;
int call(int i, int j)
{
    if (i >= 0 && i < r and j >= 0 and j < c) //if still inside the array
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int ret = -inf;
        //try to move to 3 direction,also add current cell's point
        ret = max(ret, call(i + 1, j) + mat[i][j]);
        ret = max(ret, call(i + 1, j - 1) + mat[i][j]);
        ret = max(ret, call(i + 1, j + 1) + mat[i][j]);
        return dp[i][j] = ret;
    }
    else
        return 0; //if outside the array
}
int main()
{
    // READ("in");
    mem(dp, -1);
    printf("%d\n", call(0, 0));
    return 0;
}

// LIS

#define mx 1000
int n=7;
int value[]={-100000,5,0,9,2,7,3,4};
int dp[mx],dir[mx];
int longest(int u)
{
	if(dp[u]!=-1) return dp[u];
	int maxi=0;
	for(int v=u+1;v<=n;v++) //১ম শর্ত,v>u
	{
		if(value[v]>value[u]) //২য় শর্ত, value[v]>value[u]
		{
			if(longest(v)>maxi) //সর্বোচ্চ মানটা নিবো
			{
				maxi=longest(v); 
                                dir[u]=v;

			}
		}
	}
	dp[u]=1+maxi; //১ যোগ হবে কারণ u নম্বর নোডটাও পাথের মধ্যে আছে
	return dp[u];
}


void solution(int start) // printing the solution
{	
	while(dir[start]!=-1)
	{
		printf("index %d value %d\n",start,value[start]);
		start=dir[start];
	}
}

int main() 
{ 
	READ("in");
	memset(dp,-1,sizeof dp);
        memset(dir,-1,sizeof dir);
	int LIS=0,start;
	for(int i=1;i<=n;i++)
	{
		printf("longest path from: %d\n",longest(i));
		if(longest(i)>LIS)
		{
			LIS=longest(i);
			start=i;
		}
	}
	printf("LIS = %d Starting point %d\n",LIS,start);
	
	return 0;	
}

// BITMASK dp

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

// Minimum vertex cover 
// maximum matching=minimum vertext cover

#define MAXN 100002
int dp[MAXN][5];
int par[MAXN];
vectoredges[MAXN];

int f(int u, int isGuard)
{
    if (edges[u].size() == 0)
        return 0;
    if (dp[u][isGuard] != -1)
        return dp[u][isGuard];
    int sum = 0;
    for (int i = 0; i < (int)edges[u].size(); i++) {
        int v = edges[u][i];
        if (v != par[u]) {
            par[v] = u;
            if (isGuard == 0)
                sum += f(v, 1);
            else
                sum += min(f(v, 1), f(v, 0));
        }
    }
    return dp[u][isGuard] = sum + isGuard;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans = 0;
    ans = min(f(1, 1), f(1, 0));
    printf("%d\n";, ans);
    return 0;
}

// LCS

#define MAXC 1000
char A[MAXC],B[MAXC];
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
int calcLCS(int i,int j)
{	
	if(A[i]=='\0' or B[j]=='\0') return 0;
	if(visited[i][j])return dp[i][j];

	int ans=0;
	if(A[i]==B[j]) ans=1+calcLCS(i+1,j+1);
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	visited[i][j]=1;
	dp[i][j]=ans;
	return dp[i][j];
}
int main() {
	scanf("%s%s",A,B);
	lenA=strlen(A);
	lenB=strlen(B);
	printf("%d\n",calcLCS(0,0));
	return 0;

}

// printing LCS

string ans;
void printLCS(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0'){
        cout<<ans<<endl;
        return;
    }
    if(A[i]==B[j]){
        ans+=A[i];
        printLCS(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}

// printing all LCS

string ans;
void printAll(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0'){
		cout<<ans<<endl;
		return;
	}
	if(A[i]==B[j]){
		ans+=A[i];
		printAll(i+1,j+1);
		ans.erase(ans.end()-1); //Delete last character
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else
		{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}

// Matrix chain multiplication

#define MAX 100
int row[MAX], col[MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int f(int beg,int end)
{
	if(beg>=end)return 0;
	if(visited[beg][end])return dp[beg][end];
	int ans=1<<30; //২^৩০ কে ইনফিনিটি ধরছি
	for(int mid=beg; mid<end;mid++) //দুইভাগে ভাগ করছি
	{
		int opr_left = f(beg, mid); //opr = multiplication operation
		int opr_right = f(mid+1, end);
		int opr_to_multiply_left_and_right = row[beg]*col[mid]*col[end];
		int total = opr_left + opr_right + opr_to_multiply_left_and_right;
		ans = min(ans, total);
	}
	visited[beg][end] = 1;
	dp[beg][end] = ans;
	return dp[beg][end];
}

int main()
{
	int n;
	cin>>n;
	rep(i,n)cin>>row[i]>>col[i];
	cout<<f(0,n-1)<<endl;

}
