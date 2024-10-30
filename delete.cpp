#include<bits/stdc++.h>
using namespace std;

void PriceDel( vector<string>&Name, vector<float>&Price, vector<float>&Rating, float val , bool flage = true){
    if(Name.size()==0){
        cout<<"\nYou have No Any Product in your Record !!";
        return;
    }
    bool found = false;
    if(flage){
        int n= Price.size();
        for(int i=0; i<n ;i++){ 
            if(Price[i] == val){
                found = true;
                Price.erase(Price.begin()+i);
                Rating.erase(Rating.begin()+i);
                Name.erase(Name.begin()+i);
                i--;  
                n--;
            }
        }
    }
    else{
        int n = Rating.size();
        for(int i=0; i<n; i++){
            if(Rating[i] ==val){
                found = true;
                Rating.erase(Rating.begin()+i);
                Price.erase(Price.begin()+i);
                Name.erase(Name.begin()+i);
                i--;
                n--;
            }
        }
        
    }
    if(!(found)){
        cout<<"\nThe Product which You Trying to Delete is Already Not in Record";
    }
}

void NameDel( vector<string>& Name, vector<float>&Price, vector<float>&Rating, string val){
    if(Name.size()== 0){
        cout<<"\nYou have No any Product in Your Record !!";
        return;
    }
    int n = Name.size();
    bool found = false;
    for(int i=0; i<n; i++){
        if(Name[i] == val){
            found = true;
            Name.erase(Name.begin()+i);
            Rating.erase(Rating.begin()+i);
            Price.erase(Price.begin()+i);
            i--;
        }
    }
    if(!(found)){
        cout<<"\n The Product which You Trying to Delete is Already Not in Record !!";
    }
}