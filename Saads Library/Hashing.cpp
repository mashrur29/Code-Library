//gives first index where matched;
ll Hash(const string &s, int m, ll B, ll M)
{
    ll h = 0, power = 1;
    for(int i = m-1; i>=0; i--)
    {
        h = h + (s[i] * power) % M;
        h = h % M;
        power = (power * B)%M;
    }
    return h;
}

int match(const string &text, const string &pattern)
{
    cout<<"here"<<endl;
    int n = text.size();
    int m = pattern.size();
    if(n < m)return -1;
    if(m == 0 or n == 0)
        return -1;
    ll B1 = 347, M1 = 1000000000+7;
    ll B2 = 257, M2 = 402653189;
    //ll B3 = 347, M3 = 1610612741;
    //ll B4 = 78643, M4 = 1000000000+7;

    //Calculate B^(m-1)
    ll power[5] = {1,1,1,1,1};
    for(int i=1; i<=m-1; i++)
        power[1] = (power[1] * B1) % M1;
    for(int i=1; i<=m-1; i++)
        power[2] = (power[2] * B2) % M2;



    ll hash_text[5],hash_pattern[5];
    hash_text[1] = Hash(text, m, B1, M1);
    hash_pattern[1] = Hash(pattern, m, B1, M1);
    hash_text[2] = Hash(text, m, B2, M2);
    hash_pattern[2] = Hash(pattern, m, B2, M2);

    if(hash_text[1] == hash_pattern[1] && hash_text[2] == hash_pattern[2])//returns the index of the match
    {
        return 0;
        //We should've checked the substrings character by character here as hash collision might happen
    }

    for(int i=m; i<n; i++)
    {

        //Update Rolling Hash
        hash_text[1] = (hash_text[1] - (power[1] * text[i-m]) % M1) % M1;
        hash_text[1] = (hash_text[1] + M1) % M1; //take care of M of negative value
        hash_text[1] = (hash_text[1] * B1) % M1;
        hash_text[1] = (hash_text[1] + text[i]) % M1;
        hash_text[2] = (hash_text[2] - (power[2] * text[i-m]) % M2) % M2;
        hash_text[2] = (hash_text[2] + M2) % M2; //take care of M of negative value
        hash_text[2] = (hash_text[2] * B2) % M2;
        hash_text[2] = (hash_text[2] + text[i]) % M2;

        if(hash_text[1] == hash_pattern[1] && hash_text[2] == hash_pattern[2])
        {
            return i - m + 1; //returns the index of the match
            //We should've checked the substrings character by character here as hash collision might happen
        }
    }
    return -1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
