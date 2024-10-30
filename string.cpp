#include "string.h"
#include <bits/stdc++.h>
using namespace std;

void swap(string& p, string& q) {
    string temp = p;
    p = q;
    q = temp;
}

void sort2(vector<string>& Final, int a, int b) {
    if (a >= b) {
        return;
    }

    int j = a - 1;
    int pivote_idx = a + (b - a) / 2;
    string pivote_el = Final[pivote_idx];

    for (int i = a; i <= b; i++) { 
        if (Final[i] < pivote_el) {
            j++;
            if (Final[j] == pivote_el) pivote_idx = i;
            swap(Final[i], Final[j]);
        }
    }

    swap(Final[j + 1], Final[pivote_idx]);
    pivote_idx = j + 1;

    sort2(Final, a, pivote_idx - 1);
    sort2(Final, pivote_idx + 1, b);
}

int search( vector<string>& Final, int low, int high, string val) {
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;

    if (val > Final[mid]) {
        return search(Final, mid + 1, high, val);
    } else if (val == Final[mid]) {
        return mid;
    } else {
        return search(Final, low, mid - 1, val);
    }
}

void display2(vector<string>Final, vector<string>Name, vector<float> Price, vector<float>Rating){
    int n = Final.size();
    float p[n];
    float r[n];
    string ans[n];
    unordered_map<string,int>mp1;
    unordered_map<string, int>mp2;
    for(int i=0; i<n; i++){
        string val = Name[i];
        int idx = search(Final,0, n-1, val);

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
    for(int i=0; i<n; i++){
        cout<<"("<<ans[i]<<","<<p[i]<<","<<r[i]<<")";
        if(i!= n-1)cout<<",";
    }
    cout<<"]";
    cout<<endl; 
} 




