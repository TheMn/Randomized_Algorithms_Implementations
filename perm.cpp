#include <bits/stdc++.h>
using namespace std;

#define lenOf(x) sizeof(x)/sizeof(x[0])

int* perm_nlogn(int n){
    vector<pair<int, int> > numbers;
    for(int i=0; i<n; i++) // O(n)
        numbers.push_back(make_pair(rand(), i+1));

    sort(numbers.begin(), numbers.end()); // O(nlogn)

    int* result = new int[n];
    for(int i=0; i<n; i++) // O(n)
        result[i] = numbers[i].second;

    return result;
}

int* perm_n(int n){
    int* result = new int[n];
    for(int i=0; i<n; i++) // O(n)
        result[i] = i+1;

    int j;
    for(int i=0; i<n-1; i++){ // O(n)
        j = (i+1)+rand()%(n-i-1);
        swap(result[i], result[j]);
    }

    return result;
}

int* perm_k(int n, int k=3){
    int j, idx=0;
    int* result = new int [k];
    map<int, int> numbers;

    for(int i=0; i<k; i++){ // O(k)
        do{
            j = 1+rand()%n;
            if(numbers.find(j) == numbers.end()){ // k < n/2
                numbers[j] = j;
                result[idx++] = j;
                break;
            }
        }while(true);
    }

    return result;
}

int main(){
    srand(time(0));

    const int len = 5;
    int* a = perm_nlogn(len); // = perm_n(len); // = perm_k(len, k)
    for(int i=0; i<len; i++)
        cout << a[i] << ' ';
}
