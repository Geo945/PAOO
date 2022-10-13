#include<iostream>

using namespace std;

int main ()
{
    int j, i,temp;
    int a[100];
    int n;

    cout<<"n: ";
    cin>>n;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    for(i = 0; i<n; i++) {
        for(j = i+1; j<n; j++)
        {
            if(a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout <<"Sorting result\n";
    for(i = 0; i<n; i++) {
        cout <<a[i]<<"\t";
    }

    return 0;
}