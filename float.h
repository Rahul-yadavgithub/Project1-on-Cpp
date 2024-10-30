#ifndef FLOAT_H
#define FLOAT_H

#include<bits/stdc++.h>
using namespace std;

void swap(float& p, float& k);
float cmp(float price, float rating);
void sort(vector<float>& Final, int a, int b);
int search(vector<float>& Final,int low, int high , float m);
void display(vector<float>Final, vector<float>initial, vector<string> Name, vector<float>Price, vector<float>Rating);

#endif