#include "st.h"
#include "float.h"
#include "del.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
float val;
string num;
vector<string>Name;
vector<float> Price;
vector<float> Rating;
vector<float> Final;
vector<float> helper;
vector<string>helper2;
string name;
float rating;
float price;
int choice;
int delchoice;

do{
    cout << "\n\nMain Page of our Project \n\n";
    cout << "1. Give the Product Detaile \n\n";
    cout << "2. See Your product Page \n\n";
    cout << "3. Delete Items from your project \n\n";
    cout << "4. Close All the Pages \n\n";
    cout << "Visit Any one Page : ";
    cin>>choice;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(choice) {
        case 1: 
         cout << "\n\nEnter product details. Type 'exit' for the product name to finish.\n";
    
        while (true) {
           cout << "\nEnter product name: ";
           getline(cin, name);
        
           if (name == "exit") {
              cout << "Exiting the input loop.\n";
              break;
            }
            cout << "Enter Rating (0 To 5): ";
            while (!(cin >> rating) || rating < 0 || rating >5) {
               if(rating <0) cout<<"Rating Must be positive\n";
               if(rating >5) cout<<"Rating Must be within 0 To 5 \n";
               cin.clear();            
               cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            cout << "Enter price: ";
            while (!(cin >> price) || price < 0) {
               cout << "Invalid input. Price Must be Postive : ";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            Name.push_back(name);
            Price.push_back(price);
            Rating.push_back(rating);
        }
      
        break;

        case 2:
        do{
            cout << "\n On Which Basis You want To See Product\n\n";
            cout << "1. On The Basis of Price\n\n";
            cout << "2. On The Basis of Rating\n\n";
            cout << "3. On The Basis of Combine Rating as well as Price\n\n";
            cout << "4. On The Basis of Alphabate\n\n";
            cout << "5. Back To main Page\n\n";
            cout << "Choose any option : ";
            cin>> choice;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch(choice){
                case 1:
                helper = Price;
                n = Price.size();
                sort(helper, 0, n-1);
                display(helper, Price, Name, Price, Rating);
                break;

                case 2:
                helper = Rating;
                n = Rating.size();
                sort(helper, 0, n-1);
                display(helper, Rating, Name, Price, Rating);
                break;

                case 3:
                n = Price.size();
                for(int i=0; i<n; i++){
                    val = cmp(Price[i], Rating[i]);
                    Final.push_back(val);
                }
                helper = Final;
                sort(helper, 0, n-1);
                display(helper, Final, Name, Price, Rating);
                break;

                case 4: 
                helper2 = Name;
                n = Name.size();
                sort2(helper2, 0, n-1);
                display2(helper2, Name, Price, Rating);
                break;

                case 5:
                 cout<<"Retruning to Main Page...\n\n";
                 break;
                
                default:
                cout << "Invalid choice! Please try again.\n";
            }
            cout<<endl;
        }while(choice !=5);

        break;

        case 3:
        do{
            cout << "\nOn the Basis of what You want to delete\n";
            cout << "1.Price\n";
            cout << "2.Rating\n";
            cout << "3.Name\n";
            cout << "4.Back To main Page\n";
            cout <<"choose Option : ";
            cin>>delchoice;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch(delchoice){
                case 1:
                n = Price.size();
                cout<<"\nEnter the Price:";
                cin>>val;
                PriceDel(Name, Price, Rating,val);
                break;

                case 2: 
                n = Rating.size();
                cout<<"\nEnter the Rating:";
                cin>>val;
                PriceDel(Name, Price, Rating,val,false);
                break;

                case 3:
                n = Name.size();
                cout<<"\nEnter the Name: ";
                getline(cin, num);
                NameDel(Name, Price, Rating, num);
                break;

                case 4:
                cout<<"Returning Back To main Page ...\n";
                break;

                default:
                cout << "Invalid choice! Please try again.\n";
            }
            cout<<endl;
        }while(delchoice !=4);
        break;

        case 4:
        cout<<"Closed All the page ....\n";
        break;

       default:
       cout << "Invalid choice! Please try again.\n";

    }
    
    cout<<endl;

}while(choice != 4);

}



//g++ input.cpp string.cpp float.cpp -o input -mconsole
//./input
