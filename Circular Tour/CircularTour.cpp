
#include <bits/stdc++.h> 
using namespace std;  
    int canCompleteCircuit(int Petrol[], int Distance[], int n ) 
    {
        int deficit = 0, surplus = 0, Start = 0;
        for(int i = 0; i < n; ++i){
            surplus += Petrol[i] - Distance[i];
            
            if(surplus < 0){
                Start = i+1;
                deficit+=surplus;
                surplus = 0;
            }
        }
        return (surplus+deficit < 0) ? -1 : Start;
    }
int main()
{
    int Petrol[]  = {6,3,7};
    int Distance[] = {4,6,3};
    int n=sizeof(Petrol)/sizeof(Petrol[0]);
    int start = canCompleteCircuit(Petrol,Distance, n);  
  
    (start == -1)? cout<<"No solution": cout<<"Start = "<<start;  
    return 0; 
}