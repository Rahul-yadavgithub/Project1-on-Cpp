#include "float.h"
#include<bits/stdc++.h>
using namespace std;

void swap(float& p, float& k){
    float temp = p;
    p = k;
    k = temp;
}

float cmp(float price, float rating){

    if(price == 0){
        return 0.0;
    }
    
  float val = rating/price;
    return val;
}

void sort(vector<float>& Final, int a, int b){
    if(a>= b){
        return;
    }
    int i = a;
    int j = a-1;

    int  pivote_idx = a+ (b-a)/2;
    float pivote_el = Final[pivote_idx];

    for(i ; i<=b ; i++){
        if(Final[i]< pivote_el){
            j++;
            if(Final[j] == pivote_el) pivote_idx = i;
            swap(Final[i], Final[j]);
        }
    }
    swap(Final[j+1], Final[pivote_idx]);
    pivote_idx = j+1;

    sort(Final, a, pivote_idx-1);
    sort(Final, pivote_idx+1, b);

    return;

}

int search(vector<float>& Final,int low, int high , float m){
    if(low> high){
        return -1;
    }
    int mid = low + (high-low)/2;

    if(m> Final[mid]) low = mid+1;
    else if(m == Final[mid]) return mid;
    else  high = mid-1;

    search(Final, low, high, m);


}



void display(vector<float>Final, vector<float>initial, vector<string> Name, vector<float>Price, vector<float>Rating){
    int n = Final.size();
    string ans[n];
    float p[n];
    float r[n];
    int count;
    unordered_map<float, int> mp1;
    unordered_map<float, int>mp2;
    for(int i=0; i<n; i++){
        float val = initial[i];
        int idx = search(Final, 0, n-1, val);

        // Finding in mp1 ->For left side
        if(mp1.find(val) != mp1.end() ||mp2.find(val) != mp2.end()){
            if(mp1.find(val) != mp1.end()){
               int index = mp1[val]+idx;
               ans[index] = Name[i];
               p[index] = Price[i];
               r[index] =Rating[i];
               mp1[val]--;
            } 

             else{
               int index = idx-mp2[val];
               ans[index] = Name[i];
               p[index] = Price[i];
               r[index] = Rating[i];
               mp2[val]--;
            }

        }
        else{
            if(!(idx==n-1) && Final[idx+1] == Final[idx]){
               bool flage = true;
               int j = idx;
               int count = 0;
               while(flage && j<n-1){
                  if(Final[j] == Final[j+1]){
                      count++;
                      j++;
                    }
                   else flage = false;
                }
                mp1[val] = count;
            }

            if(!(idx==0) && Final[idx-1] == Final[idx]){
                bool flage = true;
                int j = idx;
                int count = 0;
                while(flage && j>0){
                  if(Final[j] == Final[j-1]){
                       count++;
                       j--;
                    }
                    else flage = false;
                }
                mp2[val] = count;
            }

            ans[idx] = Name[i];
            p[idx] = Price[i];
            r[idx] = Rating[i];

        }

    }
    
    cout<<"\n\nOur Final Product List:\n\n";
    cout<<"[";
    for(int i=n-1; i>=0; i--){
        cout<<"("<<ans[i]<<","<<p[i]<<","<<r[i]<<")";
        if(i!= 0){
            cout<<",";
        }  
    }
    cout<<"]";
}

