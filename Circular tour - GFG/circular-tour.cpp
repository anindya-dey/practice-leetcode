//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int startingPoint = 0;
        int remainingFuel = 0;
        int totalFuel = 0;
        
        for(int i = 0; i < n; i++) {
            remainingFuel += p[i].petrol - p[i].distance;
            
            if(remainingFuel < 0) {
                remainingFuel = 0;
                startingPoint = i+1;
            }
            
            totalFuel += p[i].petrol - p[i].distance;
        }
        
        // if totalFuel is negative, there are no possible starting point
        return (totalFuel < 0) ? -1 : startingPoint;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends