//Program for Simple Perceptron
// Developed by Dr Amita Kapoor 
// For Workshop on " Biologically inspired learning: Neural Networks and Artificial Intelligence"
// Venue Hansraj College, University of Delhi

#include <iostream>

using namespace std;

int neuron(int[], float []); //Implement a single neuron
void init(float*); //Initializes weights
//Global variables
const int N = 2; // Number of inputs
const int M = 4; // Number of training patterns
float eta = 0.2; // Learning rate
int I[M][N+1] = {{1,1,-1}, {1,0,-1}, {0,1,-1}, {0,0,-1}};
//The four possible inputs
int y[M] = {1,0,0,0}; // The four outputs
const int epochs = 10; //Max epochs


int main()
{
    int temp[N+1], y_hat, flag=1;
    float W[N+1], err, epsilon=1e-05;
    init(W);
    int e = 0;
    
    //Learning Phase
    while(flag==1 && e < epochs)//for(int e=0;e<epochs;e++) //For loop: Epochs
    {
        flag=0; e++;
        for(int m=0; m<M;m++) //For Loop:Patterns
        {
            for(int j=0;j<N+1;j++) temp[j] = I[m][j]; 
            err=10;
            while (abs(err)> epsilon)
            { y_hat = neuron(temp,W);
              err = y[m]-y_hat;
              if(abs(err)>epsilon)
                 flag = 1;
              for(int j=0;j<N+1;j++) 
                 W[j]= W[j] + eta*err*temp[j];
                  
            }
        }
    }
    
    if(e < epochs){
        cout<<"\nLearning Complete in "<<e<<" Epochs\n\tFinal weights are\n\t";
         for(int j=0;j<N+1;j++)
                cout<<" "<<W[j];
    
        // Retreival Phase
        cout<<"\nTruth Table Learned\n";
        for(int i = 0; i<M; i++)
            {
                for(int j=0;j<N+1;j++) 
                     {temp[j] = I[i][j];
                     if(j==N)break;
                     cout<<temp[j]<<"  ";}
                int out = neuron(temp,W); 
                cout<<out<<"\n";
            }
    }
    else
    cout<<"\nCould not learn the logic in specified epochs"
         <<"\n Try Increasing Epochs "
         <<"\n Try modifying learning rate eta"
         <<"\n Check if the problem is linearly separable or not\n";
         
   
}

int neuron(int A [N+1],float B[N+1])
{
    float sum = 0;int out; 
    
    for (int i=0;i<N+1;i++)
        sum = sum + A[i]*B[i];
    out = (sum>=0)?1:0;
    return out;
}

void init(float *wts)
{
    for(int i=0; i<N+1;i++)
        wts[i] = 0;
}
