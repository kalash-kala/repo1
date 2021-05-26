//
//  main.cpp
//  github_testing
//
//  Created by kalash kala on 26/03/21.
//

#include <iostream>
#include <iterator>
#include <set>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
/*
string palindrome(string s){
    string sub="";
    
        for(int i=s.length()/2 - 1; i>=0 ;i--){
            sub=sub+s[i];
        }
    return sub;
}
*/
/*
void next_palindrome(string s){
    size_t size=s.length();
    string sub=palindrome(s);
    if(sub==s.substr(size/2,size/2)){
        cout<<s<<"\n";
    }
    else if(size%2==0){
        if(sub>s.substr(size/2,size/2)){
            cout<<s.substr(0,size/2)+sub<<endl;
        }else{

            if(s[size/2 - 1]=='9'){
                for(int i =size/2 -1; i>=0; i--){
                    if(s[i]=='9'){
                        s[i]='0';
                    }else{
                        s[i]++;
                        break;
                    }
                }
            }else{
                s[size/2 - 1]++;
            }
            cout<<s.substr(0,size/2)+palindrome(s)<<endl;
        }
    }else if(size%2==1){
        if(sub>s.substr(size/2+1,size/2)){
            cout<<s.substr(0,size/2+1)+sub<<endl;
        }else{
            
            if(s[size/2]=='9'){
                for(int i =size/2; i>=0; i--){
                    if(s[i]=='9'){
                        s[i]='0';
                    }else{
                        s[i]++;
                        break;
                    }
                }
            }else{
                s[size/2]++;
            }
            cout<<s.substr(0,size/2+1)+palindrome(s)<<endl;
        }
    }
}*/


void next_palindrome(char *s){
    int count = 0;
    bool flag = true;
    size_t len=strlen(s);
    
    if(len==1){
        printf("11\n");
    }
    else if(len%2==0){ //even
        for(int i=0; i<len/2; i++){
            if(s[len/2-1-i]!=s[len/2+i]){
                flag=false;
                break;
            }

            count++; // counts number of equal chars
        }
        if(flag){
            if(s[len/2-1]=='9'){
                s[0]='1';
                for(int i=1; i<len; i++){
                    s[i]='0';
                }
                s[len]='1';
            }else{
                s[len/2 - 1]++;
                int j = 0;
                for(int i=len/2-1; i>=0; i--){
                    s[j+len/2]=s[i];
                    j++;
                }
            }
            printf("%s\n",s);
        }else{
            if(s[len/2-1-count]>s[len/2+count]){
                int j = 0;
                for(int i=len/2-count-1; i>=0; i--){
                    s[j+count+len/2]=s[i];
                    j++;
                }
            }else{
                if(s[len/2-1]=='9'){
                    for(int i=len/2-1; i>=0; i--){
                        if(s[i]=='9'){
                            s[i]='0';
                        }else{
                            s[i]++;
                            break;
                        }
                    }
                }else{
                    s[len/2 - 1]++;
                }
                int j = 0;
                for(int i=len/2-1; i>=0; i--){
                    s[j+len/2]=s[i];
                    j++;
                }
            }
            printf("%s\n",s);
        }
    }else{  //odd
        for(int i=0; i<len/2; i++){
            if(s[len/2-1-i]!=s[len/2+1+i]){
                flag=false;
                break;
            }
            count++; // counts number of equal chars
        }
        if(flag){
            if(s[len/2-1]=='9'){
                s[0]='1';
                for(int i=1; i<len; i++){
                    s[i]='0';
                }
                s[len]='1';
            }else{
                s[len/2]++;
                int j = 0;
                for(int i=len/2-1; i>=0; i--){
                    s[j+len/2+1]=s[i];
                    j++;
                }
            }
            printf("%s\n",s);
        }else{
            if(s[len/2-1-count]>s[len/2+1+count]){
                int j = 0;
                for(int i=len/2-count-1; i>=0; i--){
                    s[j+count+len/2+1]=s[i];
                    j++;
                }
            }else{
                
                if(s[len/2]=='9'){
                    for(int i =len/2; i>=0; i--){
                        if(s[i]=='9'){
                            s[i]='0';
                        }else{
                            s[i]++;
                            break;
                        }
                    }
                }else{
                    s[len/2]++;
                }
                int j = 0;
                for(int i=len/2-1; i>=0; i--){
                    s[j+len/2+1]=s[i];
                    j++;
                }
            }
            printf("%s\n",s);
        }
    }

}

int lonely_integer(vector<int>a){
    
    int numbers[100]={0};
    for(int i=0; i<a.size(); i++){
        numbers[a[i]-1]++;
    }
    for(int i=0; i<100; i++){
        if(numbers[i]==1){
            return  i+1;
        }
    }
    return 0;
}

int maximizingXor(int l, int r) {
    
    int max=0;
    
    for(int i=l; i<=r; i++){
        for(int j=i; j<=r; j++){
            if(max<(i^j)){
                max = i^j;
            }
        }
    }
    
    return max;
}

string balancedSums(vector<int> arr) {
    
    int l_sum=0, r_sum=0;
    string s="";
    if(arr.size()==1){
        return "YES";
    }else{
        for(int i=0; i<arr.size(); i++){
            l_sum=0;
            r_sum=0;
            /*
            if(i==0){
                for(int j=1; j<arr.size(); i++){
                    r_sum+=arr[j];
                }
                if(l_sum==r_sum){
                    s = "YES";
                }else{
                    s = "NO";
                }
                
            }else if(i==arr.size()-1){
                for(int j=0; j<arr.size()-1; j++){
                    l_sum+=arr[j];
                }
                if(l_sum==r_sum){
                    s = "YES";
                }else{
                    s = "NO";
                }
            }*/
            
            for(int j=0; j<i; j++){
                l_sum+=arr[j];
            }
            for(int j=i+1; j<arr.size(); j++){
                r_sum+=arr[j];
            }
            if(r_sum==l_sum){
                s = "YES";
            }else{
                s = "NO";
            }
        }
    }
    
    return s;
}

int sansaXor(vector<int> arr) {
    
    
    return 0;
}

void merge(int arr1[], int arr2[], int n, int m) {
    int i=0, j=0, k=0;
    int *c= new int[n+m];
    
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            //cout<<arr1[i]<<" ";
            c[k++]=arr1[i];
            i++;
            j++;
        }else if(arr1[i]>arr2[j]){
            //cout<<arr2[j]<<" ";
            c[k++]=arr2[j++];
        }else{
            //cout<<arr1[i]<<" ";
            c[k++]=arr1[i++];
        }
    }
    
    for(;i<n;i++){
     //   cout<<arr1[i]<<" ";
        c[k++]=arr1[i];
    }
    for(;j<m;j++){
        c[k++]=arr2[j];
     //   cout<<arr2[j]<<" ";
    }
    for(int x=0; x<k;x++){
        if(x<n){
            arr1[x]=c[x];
        }else{
            arr2[x-n]=c[x];
        }
    }
    delete []c;
}

string caseSort(string str, int n){
    
    string s="";
    int posn[n];
    int low[26]={0};
    int up[26]={0};
    string s_low="abcdefghijklmnopqrstuvwxyz";
    string s_up="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i=0; i<n; i++){
        if((int)str[i]>96 && (int)str[i]<123){
            low[(int)str[i]-97]++;
            posn[i]=0;
        }else{
            up[(int)str[i]-65]++;
            posn[i]=1;
        }
    }
    for(int i=0; i<n; i++){
        if(posn[i]==0){
            for(int j=0; j<26; j++){
                if(low[j]!=0){
                    s+=s_low[j];
                    low[j]--;
                    break;
                }
            }
        }else{
            for(int j=0; j<26; j++){
                if(up[j]!=0){
                    s+=s_up[j];
                    up[j]--;
                    break;
                }
            }
        }
    }
    return s;
}


int red_blue_codeforces(){
    
    int T=0;
    cin>>T;
    
    while(T--){
        
        int r=0,b=0,d=0;
        cin>>r>>b>>d;
        
        if(r==b){
            cout<<"YES\n";
            continue;
            
        }else if(r==1 || b==1){
            if(abs(r-b)<=d){
                cout<<"YES\n";
                continue;
            }else{
                cout<<"NO\n";
                continue;
            }
            
        }else if(d==0){
            if(r==b){
                cout<<"YES\n";
                continue;
            }else{
                cout<<"NO\n";
                continue;
            }
        }else{
            if(r<b){
                if(b%r==0){
                    if((b/r - 1<=d)){
                        cout<<"YES\n";
                        continue;
                    }else{
                        cout<<"NO\n";
                        continue;
                    }
                }else{
                    if((b/r <=d)){
                        cout<<"YES\n";
                        continue;
                    }else{
                        cout<<"NO\n";
                        continue;
                    }
                }
            }else if(r>b){
                if(r%b==0){
                    if((r/b - 1<=d)){
                        cout<<"YES\n";
                        continue;
                    }else{
                        cout<<"NO\n";
                        continue;
                    }
                }else{
                    if((r/b <=d)){
                        cout<<"YES\n";
                        continue;
                    }else{
                        cout<<"NO\n";
                        continue;
                    }
                }
            }
        }
        
    }

    return 0;
}

int twins_codeforces(){
    
    
    int n=0;
    cin>>n;
    
    int a[n];
    int sum=0,count=0,ans=0;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    sort(a, a+n, greater<int>());
    
    for(int i=0; i<n; i++){
        ans+=a[i];
        count++;
        if(ans>sum-ans){
            cout<<count<<"\n";
            break;
        }
    }

    return 0;
}

void taxiCodeforces(){
    
    int n=0;
    cin>>n;
   
    int arr[n];
    int count_1234[4]={0};
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
        count_1234[arr[i]-1]++;
    }
    
    int min_num=count_1234[3];
    
    if(count_1234[0]<=count_1234[2]){
        min_num+=count_1234[0];
        count_1234[2]-=count_1234[0];
        count_1234[0]=0;
    }else{
        min_num+=count_1234[2];
        count_1234[0]-=count_1234[2];
        count_1234[2]=0;
    }
    
    min_num+=count_1234[2];
    
    if(count_1234[0]/2 <= count_1234[1]){
        min_num+=count_1234[0]/2;
        count_1234[1]-=count_1234[0]/2;
        count_1234[0]%=2;
        
        if((count_1234[0]+count_1234[1])%2==1){
            min_num+=(count_1234[0]+count_1234[1])/2 + 1;
            count_1234[0]=0;
            count_1234[1]=0;
        }else{
            min_num+=(count_1234[0]+count_1234[1])/2;
            count_1234[0]=0;
            count_1234[1]=0;
        }
    }else{
        min_num+=count_1234[1];
        count_1234[0]-=2*count_1234[1];
        count_1234[1]=0;
    }
    if(count_1234[0]%4==0){
        min_num+=count_1234[0]/4;
    }else{
        min_num+=count_1234[0]/4 + 1;
    }

    cout<<min_num<<"\n";

}

void Codeforces(){
    int n=0;
    cin>>n;
    
    int arg[n+1];
    for(int i=0; i<n; i++){
        cin>>arg[i];
    }
    arg[n]=0;
    
    vector<int>v;
    int count=1;
    
    for(int i=1; i<n; i++){
        if(arg[i]<arg[i-1]){
            v.push_back(count);
            count=0;
        }
        count++;
    }
    v.push_back(count);
    
    if(v.size()!=0){
        cout<<*max_element(v.begin(), v.end())<<"\n";
        v.clear();
    }
}

void capslockCodeforces(){
    string s;
    cin>>s;
    
    bool check=true;
    size_t size=s.length();
    
    for(int i=1; i<size; i++){
        if(islower(s[i])){
            check=false;
            break;
        }
    }
    
    if(check){
        if(islower(s[0])){
            s[0]=toupper(s[0]);
        }else{
            s[0]=tolower(s[0]);
        }
        for(int i=1; i<size; i++){
            s[i]=tolower(s[i]);
        }
        cout<<s<<"\n";
    }else{
        cout<<s<<"\n";
    }
}

void dubstepCodeforces(){
    string s;
    cin>>s;
    
    size_t size = s.length();
    string wub="WUB";
    
    int arr[size];
    for(int i=0; i<size; i++){
        string sub=s.substr(i,3);
        //cout<<sub<<"\n";
        if(wub.compare(sub)==0){
            arr[i]=1;
            arr[i+1]=1;
            arr[i+2]=1;
            i+=2;
        }else{
            arr[i]=0;
        }
    }

    for(int i=0; i<size; i++){
        if(arr[i]==0){
            cout<<s[i];
        }else if(arr[i-1]<arr[i]){
            cout<<" ";
        }
    }
    cout<<"\n";
}

void gravityFlip(){
    
    int n=0;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int min_idx=0,temp=0;
    
    for(int i=0; i<n-1; i++){
        
        min_idx=i;
        for(int j=i+1; j<n; j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}

void puzzleCodeforces(){
    int n=0,m=0;
    cin>>n>>m;
    
    int arr[m];
    int arg[n];
    
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    
    int min_diff=INT_MAX;
    
    sort(arr,arr+m);
    
    for(int i=0; i<m-n+1; i++){
        for(int j=0; j<n; j++){
            arg[j]=arr[i+j];
        }
        if(min_diff>(*max_element(arg, arg+n)-*min_element(arg, arg+n))){
            min_diff=(*max_element(arg, arg+n)-*min_element(arg, arg+n));
        }
    }
    
    cout<<min_diff<<"\n";

}

void leastCoinsCodeforces(){
    
    long long n=0;
    cin>>n;
    
    long long count=0;
    count+=n/100;
    n%=100;
    count+=n/20;
    n%=20;
    count+=n/10;
    n%=10;
    count+=n/5;
    n%=5;
    count+=n/1;
    
    cout<<count<<"\n";
    
}

int dragonsCodeforces(){
    
    int s=0,n=0;
    cin>>s>>n;
    
    int x=0,y=0;
    
    int strength[n],bonus[n];
    
    for(int i=0; i<n; i++){
        cin>>x>>y;
        strength[i]=x;
        bonus[i]=y;
    }
    
    int min_idx=0,temp=0;
    
    for(int i=0; i<n-1; i++){
        min_idx=i;
        for(int j=i+1; j<n; j++){
            if(strength[min_idx]>strength[j]){
                min_idx=j;
            }
        }
        temp=strength[min_idx];
        strength[min_idx]=strength[i];
        strength[i]=temp;
        
        temp=bonus[min_idx];
        bonus[min_idx]=bonus[i];
        bonus[i]=temp;
    }
    
    for(int i=0; i<n; i++){
        if(s<=strength[i]){
            cout<<"NO\n";
            return 0;
        }else{
            s+=bonus[i];
        }
    }
    
    cout<<"YES\n";
    
    return 0;
}

void goodnumCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    long long A=0,B=0;
    cin>>T;

    while(T--){
        
        cin>>A>>B;
        if(B==1){
            cout<<"NO\n";
        }else if(B!=2){
            cout<<"YES\n";
            cout<<A*(B-1)<<" "<<A<<" "<<A*B<<"\n";
        }else if(B==2){
            B*=5;
            cout<<"YES\n";
            cout<<A*(B-1)<<" "<<A<<" "<<A*B<<"\n";
        }
    }
}

void xenia_and_ringroadCodeforces(){
    
    int n=0,m=0;
    cin>>n>>m;
    
    int arr[m];
    
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    
    unsigned long long j=0, check=1;
    unsigned long long count=0;
    
    while(j<m){
        if(check==arr[j]){
            j++;
            continue;
        }else if(check<arr[j]){
            count+=arr[j]-check;
            check=arr[j];
        }else{
            count+=n-(check-arr[j]);
            check=arr[j];
        }
    }
    
    cout<<count<<"\n";
}

void T_primeCodeforces(){           // lots of new things learnt
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int T=0;
    //cin>>T;
    
    long long n=0;
    cin>>n;
    long long arr[n];
    set<long double> s1;
    int prime[1000001]={0};
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(long i=2; i*i<1000000; i++){
        if(prime[i]==0){
            for(long j=i*i; j<1000000; j+=i){
                prime[j]=1;
            }
        }
    }
    for(long i=2; i<1000000; i++){
        if(prime[i]==0){
            s1.insert(i);
        }
    }
    
    for(int i=0; i<n; i++){
        auto pos = s1.find(sqrt(arr[i]));
        if(pos==s1.end()){              // nice way to check if an iterator is empty or not
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}

int cut_ribbonsCodeforces(){
    
    int n=0;
    int abc[3];
    cin>>n>>abc[0]>>abc[1]>>abc[2];
    
    int sub=n,sum=0,flag=0;
    
    sort(abc, abc+3);
    
    while(n!=0){
        
        sum=0;
        
        if(flag<1){
            if(n%abc[0]==0){
                sum+=n/abc[0];
                cout<<sum<<"\n";
                return 0;
            }else{
                sum+= n/abc[0] - 1;
                n-=(n/abc[0] - 1)*abc[0];
            }
        }
        if(flag<2){
            if(n%abc[1]==0){
                sum+=n/abc[1];
                cout<<sum<<"\n";
                return 0;
            }else{
                sum+= n/abc[1] - 1;
                n-= (n/abc[1]-1)*abc[1];
            }
        }

        sum+=n/abc[2];
        n-=(n/abc[2])*abc[2];
        flag++;
    }
    
    cout<<sum<<"\n";
    return 0;

}

void remove_smallestCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int n=0,flag=0;
    
    while(T--){
        cin>>n;
        int arg[n];
        
        flag=1;
        
        for(int i=0; i<n; i++){
            cin>>arg[i];
        }
        sort(arg, arg+n);
        for(int i=1; i<n; i++){
            if(arg[i]-arg[i-1]>1){
                flag=0;
                break;
            }
        }
        
        if(flag){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    /* above soln is better
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int T=0;
     cin>>T;
     
     int n=0,j=0;
     set<int>s1;
     vector<int>v1;
     
     while(T--){
         cin>>n;
         
         for(int i=0; i<n; i++){
             cin>>j;
             s1.emplace(j);
         }
         for(auto iter=s1.begin(); iter!=s1.end(); iter++){
             v1.push_back(*iter);
         }
         
         int flag=1;
         
         while(flag!=0){
             flag=0;
             for(int i=0; i<v1.size()-1; i++){
                 if(abs(v1[i]-v1[i+1])<=1){
                     flag++;
                     v1.erase(v1.begin()+i);
                     i=-1;
                 }
             }
         }
         
         if(v1.size()==1){
             cout<<"YES\n";
         }else{
             cout<<"NO\n";
         }
         
         s1.clear();
         v1.clear();
     }
     */
}

void Yet_Another_Two_Integers_Problem_codeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0,a=0,b=0,diff=0;
    cin>>T;
    
    while(T--){
        cin>>a>>b;
        diff=abs(a-b);
        if(diff%10==0){
            cout<<(diff/10)<<"\n";
        }else{
            cout<<(diff/10 + 1)<<"\n";
        }
    }
    
}
void Design_Tutorial_Learn_from_MathCodeforces(){
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arg[500001]={0};
    
    for(int i=2; i*i<500001; i++){
        
        if(arg[i]==0){
            for(int j=i*i; j<=500001; j+=i){
                arg[j]=1;
            }
        }
    }
    
    int n=0,a=0,b=0;
    cin>>n;
    
    if(n%2==0){
        a=n/2;
        b=n/2;
        while(arg[a]==0 || arg[b]==0){
            a-=1;
            b+=1;
        }
    }else{
        a=n/2;
        b=n/2+1;
        while(arg[a]==0 || arg[b]==0){
            a-=1;
            b+=1;
        }
    }
    
    cout<<a<<" "<<b<<"\n";

}

void balanced_arrayCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int n=0;
    
    while(T--){
        cin>>n;
        int arr[n];
        int sum=0,even=2,odd=1;
        
        if((n/2)%2==1){
            cout<<"NO\n";
        }else{
            for(int i=0; i<n/2; i++){
                arr[i]=even;
                even+=2;
                sum+=arr[i];
            }
            
            for(int i=n/2; i<n-1; i++){
                arr[i]=odd;
                odd+=2;
                sum-=arr[i];
            }
            arr[n-1]=sum;
            cout<<"YES\n";
            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }
}

void candiesCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    unsigned long long int n=0,two=4;
    
    while(T--){
        
        n=0;
        cin>>n;

        two=4;
        while(true){
            if(n%(two-1)==0){
                break;
            }
            two*=2;
        }
        cout<<n/(two-1)<<"\n";
    }
}

void ilya_and_bank_accountCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int T=0;
    //cin>>T;
    
    long long int n=0,sub=0,sub1=0;
    cin>>n;
    
    if(n<0){
        n*=-1;
        sub=n/10;
        sub1=(n/100)*10 + (n%10);
        if(sub>sub1){
            cout<<-1*sub1<<"\n";
        }else{
            cout<<-1*sub<<"\n";
        }
    }else{
        cout<<n<<"\n";
    }
    
}

void police_recruits(){
    
    int n=0;
    cin>>n;
    
    int arg[n];
    
    for(int i=0; i<n; i++){
        cin>>arg[i];
    }
    
    int sum=0,count=0;
    
    for(int i=0; i<n; i++){
        if(arg[i]<0 && sum==0){
            count++;
        }else{
            sum+=arg[i];
        }
    }
    
    cout<<count<<"\n";
    
}

void team_olympiadCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=0;
    cin>>n;
    
    int t[3]={0},j=0,k=0,l=0;
    int team[n],i_1[n],i_2[n],i_3[n];
    
    for(int i=0; i<n; i++){
        cin>>team[i];
        t[team[i]-1]++;
        if(team[i]==1){
            i_1[j]=i+1;
            j++;
        }else if(team[i]==2){
            i_2[k]=i+1;
            k++;
        }else{
            i_3[l]=i+1;
            l++;
        }
    }
    
    int m=*min_element(t, t+3);
    
    cout<<m<<"\n";
    
    for(int i=0; i<m; i++){
        cout<<i_1[i]<<" "<<i_2[i]<<" "<<i_3[i]<<"\n";
    }
}

void vasya_and_socksCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=0,m=0;
    cin>>n>>m;
    
    int days=0;
    
    for(int i=1; i<=n; i++){
        days++;
        if(i%m==0){
            n+=1;
        }
    }
    
    cout<<days<<"\n";
}

void newYearCandlesCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a=0,b=0;
    cin>>a>>b;
    int count=0,hours=0;
    for(int i=0; i<a; i++){
        hours++;
        count++;
        if(count==b){
            count=0;
            a++;
        }
    }
    
    cout<<hours<<"\n";
}

void honestCoachCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int n=0,min=INT_MAX;
    
    while(T--){
        
        cin>>n;
        int arr[n];
        min=INT_MAX;
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        for(int i=0; i<n-1; i++){
            if(arr[i+1]-arr[i]<min){
                min=arr[i+1]-arr[i];
            }
        }
        cout<<min<<"\n";
    }
    
}

void bachgold_problemCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int T=0;
    //cin>>T;
    
    int n=0;
    cin>>n;
    
    if(n%2==0){
        cout<<n/2<<"\n";
        for(int i=0; i<n/2; i++){
            cout<<"2 ";
        }
        cout<<"\n";
    }else{
        cout<<n/2<<"\n";
        for(int i=0; i<n/2-1; i++){
            cout<<"2 ";
        }
        cout<<"3 \n";
    }
}

void most_unstable_arrayCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int n=0,m=0;
    
    while(T--){
        cin>>n>>m;
        if(n==1){
            cout<<"0\n";
        }else{
            cout<<min(2, n-1)*m<<"\n";
        }
    }
}

int footballCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    
    int count=1,j=0;
    
    for(int i=1; i<s.length(); i++){
        if(s[j]==s[i]){
            count++;
        }else{
            j=i;
            if(count>=7){
                cout<<"YES\n";
                return 0;
            }else{
                count=1;
            }
        }
    }
    
    if(count<7){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
    return 0;
}

void Multiply_by_2_divide_by_6Codeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    long long n=0,count=0;
    
    while(T--){
        cin>>n;
        count=0;
        while(n!=1){
            if(n%6==0){
                count++;
                n/=6;
            }else if(n%3==0){
                count++;
                n*=2;
            }else{
                cout<<"-1\n";
                break;
            }
        }
        if(n==1){
            cout<<count<<"\n";
        }
    }
}

void restore_the_permutation_by_mergerCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int n=0;
    
    while(T--){
        cin>>n;
        int arg[n];
        int input[2*n];
        
        for(int i=0; i<2*n; i++){
            cin>>input[i];
            if(i<n){
                arg[i]=0;
            }
        }
        for(int i=0; i<2*n; i++){
            if(arg[input[i]-1]==0){
                cout<<input[i]<<" ";
                arg[input[i]-1]++;
            }
        }
        cout<<"\n";
    }
}

void minimal_squareCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    int a=0,b=0;
    
    while(T--){
        cin>>a>>b;
        int sub=min(a,b);
        int sub1=max(a,b);
        
        if(sub*2 >= sub1){
            cout<<4 * sub * sub<<"\n";
        }else{
            cout<<sub1*sub1<<"\n";
        }
    }
}

void oddDivisor(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    long long n=0;
    
    while(T--){
        cin>>n;
        while(n%2==0){
            n/=2;
        }
        if(n==1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}

void black_squareCodeforces(){
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arg[4]={0};
    for(int i=0; i<4; i++){
        cin>>arg[i];
    }
    
    string seq;
    cin>>seq;
    long long sum=0;
    
    for(int i=0; i<seq.length(); i++){
        sum+=arg[(int)seq[i]-49];
    }
    
    cout<<sum<<"\n";
}

void parklighthingCodeforces(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    while(T--){
        int n=0,m=0;
        cin>>n>>m;
        
        int mux = max(n,m);
        int mun = min(n,m);
        
        long long sum=mux/2 * mun;
        
        if(mux%2==0){
            sum=mux/2 * mun;
            cout<<sum<<"\n";
        }else{
            sum=mux/2 * mun + (int)ceil((double)mun/2);
            cout<<sum<<"\n";
        }
        
    }
}

void moveBracketCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    string s;
    int n=0;
    int flag=0;
    
    while(T--){
        
        cin>>n;
        cin>>s;
        
        if(s[0]==')' || s[s.length()-1]=='('){
            flag=1;
        }
        
        stack<char> st;
        
        int i=0;
        st.push(s[i]);
        i++;
        
        while(s[i]){
            
            if(st.empty()){
                st.push(s[i]);
                i++;
                continue;
            }
            
            if(st.top()=='(' && s[i]==')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }
        int len=0;
        while(!st.empty()){
            len++;
            st.pop();
        }
        if(flag){
            cout<<len/2<<"\n";
        }else{
            cout<<len<<"\n";
        }
    }
    
}

void roadToZeroCodeforces(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    long long x,y,a,b;
    
    while(T--){
        cin>>x>>y;
        cin>>a>>b;
        
        long mux=max(x, y);
        long mun=min(x,y);
        
        long long int money=(mux-mun)*a + mun*b;
        long long int money1=(mun+mux)*a;
        
        if(money>=money1 && mun+mux!=0){
            cout<<money1<<"\n";
        }else{
            cout<<money<<"\n";
        }
    }
    
}

int main(int argc, const char * argv[]){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    
    string s;
    cin>>s;
    
    return 0;
}
