void reverse(queue<int> &q)
{
    if(q.empty())
        return ;
    int num=q.front();
    q.pop();
    reverse(q);
    q.push(num);
}