// 0-1 Knapsack Problem
/*
    Put n items with given weight and value in a knapsack (bag) 
    of capacity W to get maximum total value in the knapsack
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

/*
    values : 9   8   5   2   5
    weight : 20  13  19  11  22
    capactity (W) : 50
*/

int knapsack(int value[], int weight[], int n, int capacity) {
    if(capacity==0 || n==0) {
        return 0;
    }
    if(weight[n-1] > capacity) {
        return knapsack(value, weight, n-1, capacity);
    }

    return max(knapsack(value, weight, n-1, capacity-weight[n-1]) + value[n-1], // if included then value
                knapsack(value, weight, n-1, capacity)); // if not included then value
}

int main() {
    int wt[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    int capacity = 50;
    int n = 3;
    cout<<knapsack(value, wt, n, capacity)<<endl;

    return 0;
}