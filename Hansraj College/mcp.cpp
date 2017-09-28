// Program to implement McCulotch Pitts Model and different logic gates using MCP model.
// Developed by Dr Amita Kapoor 
// For Workshop on " Biologically inspired learning: Neural Networks and Artificial Intelligence"
// Venue Hansraj College, University of Delhi

#include <iostream>

using namespace std;

// Global Variables
const int N = 2; // Number of Neurons
const int M = 4; // Number of Training Patterns
int I[M][N+1] = {{1,1,-1}, {1,0,-1}, {0,1,-1}, {0,0,-1}};
//The four possible inputs

// Function Declaration
int neuron(int [],float []);
int init(float*, int, int []) ; // Pass array by reference


int main()
{
   float W[N+1]; // Weight matrix
   int temp[N+1], choice;
   cout<<"Enter\n1 for AND\n2 for OR\n3 for NOT\n4 for NAND\n5 for XOR\n";
   cin>>choice;
   //cout<<choice<<"\n";
   cout<<"Truth Table using MCP\n";
   for(int i = 0; i<M; i++)
   {
      for(int j=0;j<N+1;j++) 
        {temp[j] = I[i][j];
        cout<<temp[j]<<"  ";}
      int out = init(W, choice, temp); 
      cout<<out<<"\n";
   }
   
  
   
}
int init(float *wts, int ch, int t[]){
    switch(ch){
    case 1: for(int i=0;i<N;i++)
                wts[i]=1;  
            wts[N] = N;
            
            break;
    case 2: for(int i=0;i<N;i++)
                wts[i]=1;  
            wts[N] = 1;
            break;
    case 3: for(int i=1;i<N+1;i++)
                wts[i]=0;  
            wts[0] = -1;
            break;
    case 4: for(int i=0;i<N;i++)
                wts[i]=-1;  
            wts[N] = -N + 0.5;
            break;  
    case 5: int andNot = init(wts, 4, t);
            int or_ = init(wts, 2, t);
            int arr[3] = {andNot, or_, -1};
            int out = init(wts, 1,arr);
            return out;
    
    }
    
    int out = neuron(t,wts);
    return out;
    
}


int neuron(int A [N+1],float B[N+1])
{
    float sum = 0;int out; 
    
    for (int i=0;i<N+1;i++)
        sum = sum + A[i]*B[i];
    out = (sum>=0)?1:0;
    return out;
}

