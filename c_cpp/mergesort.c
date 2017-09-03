int a[MAXN];
void merge(int i,int mid,int j)
{
    int l1=mid-i+1,l2=j-mid,p=0,q=0,r;
	int b[l1],c[l2];
    while(p<l1) {b[p]=a[p+i];p++;}
    while(q<l2) {c[q]=a[q+mid+1];q++;}
    p=0;q=0,r=i;
    while(p<l1 && q<l2)
    {
        if(b[p]<=c[q])
        {
            a[r]=b[p];
            p++;
            r++;
        }
        else
        {
            a[r]=c[q];
            q++;
            r++;
        }
    }
    while(p<l1)
    {
        a[r]=b[p];
        p++;
        r++;
    }
    while(q<l2)
    {
        a[r]=c[q];
        q++;
        r++;
    }
}
void divide(int i,int j)
{
    if(i<j)
    {
        int mid=(i+j)/2;
        divide(i,mid);
        divide(mid+1,j);
        merge(i,mid,j);
    }
}
