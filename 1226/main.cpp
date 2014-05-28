#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 21000;

int input[maxn];
void printList(int *r, int n) {
    for (int i = 0; i<n; i++) {
        cout << r[i] << endl;
    }
}

int cmp(int *r,int a,int b,int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

// m should be the largest number in r array plus 1
void getSuffixArray(int *r,int *sa,int n,int m)
{
    int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
    int i,j,p,*x=wa,*y=wb,*t;
    
    //Bin sort the r array
    for(i=0;i<m;i++) ws[i]=0; // Init to 0 for all bins
    for(i=0;i<n;i++) ws[x[i]=r[i]]++; // Put each item into bin
    for(i=1;i<m;i++) ws[i]+=ws[i-1]; // Bin sort: the number for each bin equals all 
    // Get the suffix array after the first sort
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;

    for(j=1,p=1;p<n;j*=2,m=p)
    {
        // Sort the second key number which is Y. save result sa in y array.
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        
        // wv is already sorted based on Y by passing y[i] as new i.
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];

        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}

int compare(int *r, int n, int first, int second) {
    int result = 0;
    for (int i = first, j = second; i < n && j < n; i++, j++) {
        if (r[i]==r[j]) {
            result++;
            continue;
        } else {
            break;
        }
    }
    return result;
}

void getHeightArray(int *r, int *sa, int *height, int n) {
    /*
    int rank[maxn];
    int i, j, k=0;
    for (i = 0; i < n; i++)
        rank[sa[i]] = i;
    for (i = 0; i<n; height[rank[i++]]=k) {
        if (rank[i]==0) {
            k=0;
        } else {
            if (k>0) k--;
            for (j = sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
        }
    }*/
    height[0] = 0;
    for (int i = 1; i < n; i++) {
        height[i] = compare(r, n, sa[i-1], sa[i]);
    }

    return;
}

int vis[1004];

bool check(int *height, int *sa, int *loc, int n, int mid, int numOfStrings){  
    int tot=0;  
    memset(vis,0,sizeof(vis));  
    for (int i=2; i < n; i++) {  
        if (height[i] < mid) {  
            memset(vis,0,sizeof(vis));  
            tot=0;  
        } else {  
            if (!vis[loc[sa[i-1]]]) {  
                vis[loc[sa[i-1]]]=1;  
                tot++;  
            }  
            if (!vis[loc[sa[i]]]) {  
                vis[loc[sa[i]]]=1;  
                tot++;  
            }  
            if (tot == numOfStrings) {  
                return true;  
            }  
        }  
    }  
    return false;  
}

void solve(int *height, int *sa, int *loc, int n, int minLen, int numOfStrings) {
    int left=0, right=minLen, mid, ans=1;  
    while (right>=left) {  
        mid=(right+left)/2;  
        if (check(height, sa, loc, n, mid, numOfStrings)) {// check if the string with length mid is the answer 
            left=mid+1;  
            ans=mid;  
        } else{  
            right=mid-1;  
        }  
    }  
    cout << ans << endl; 
}

int main(){
    int cases;
    int loc[maxn], n;
    int indexOfSpecialNumber = 100; //Fake index of Special number to 100, since we have 1~100 items.
    cin >> cases;
    while (cases--) {
        n = 0;
        int numOfStrings;
        int specialNumber = 180;
        int minLen = 100;
        cin >> numOfStrings;
        for (int index=0; index<numOfStrings; index++) {
            string tmp;
            cin >> tmp;
            int len = tmp.length();
            minLen = minLen>len ? len : minLen;
            for (int i=0; i<len; i++) {
                input[n] = tmp.at(i);
                loc[n++] = index;
            }
            input[n] = specialNumber++;
            loc[n++] = indexOfSpecialNumber;
            for (int i=len-1; i>=0; i--) {
                input[n] = tmp.at(i);
                loc[n++] = index;
            }
            input[n] = specialNumber++;
            loc[n++] = indexOfSpecialNumber;
        }
        input[n] = 0;
        loc[n++] = indexOfSpecialNumber;
        if (numOfStrings == 1) {
            cout << minLen << endl;
            continue;
        }
        //printList(input, n);
        int sa[maxn], height[maxn];
        getSuffixArray(input, sa, n, 400);
        getHeightArray(input, sa, height, n);
        //printList(height, n);
        solve(height, sa, loc, n, minLen, numOfStrings);    


    }
    return 0;
}
