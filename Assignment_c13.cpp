/*Consider the scheduling problem. n tasks to be scheduled on single processor. 
Let t1, ...,tn be durations required to execute on single processor is known. 
The tasks can be executed in any order but one task at a time. Design a greedy algorithm for this
problem and find a schedule that minimizes the total time spent by all the tasks in the system. 
(The time spent by one is the sum of the waiting time of task and the time spent on its execution.)*/

//prism's algorithm
#include<iostream>
using namespace std;


int adjacencymatric[10][10],i,j,n,k;
    

int main()
{
    int m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;   

    cout << "\n EDGES of the graph are :\n";
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        adjacencymatric[i][j] = 1;
        adjacencymatric[j][i] = 1;
    }
    
    //display function
    cout << "The adjacency matrix of the graph is : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << adjacencymatric[i][j];
        }
        cout << endl;
    }
}


