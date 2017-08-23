
        while(!q.empty()){
           x=q.top().second;
           lim=a[x].size();
           q.pop();

                for(i=0;i<lim;i++){
                    pp=a[x][i].first; ppw=a[x][i].second;
                    if(ppw+d[x]<d[pp]){
                        p[pp]=x;
                        ll t=d[x]+ppw;
                        q.push(pii(-(d[pp]=t),pp));
                    }
                }
        }
