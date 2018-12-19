
//Shortest path - recursive solution

#include<iostream>
#include<cstdlib>
using namespace std;

const int rows = 5;
const int cols = 6;
int path[cols]={0};

//determines the cost of the shortest path
int cost(int i, int j){ // i is the row, j is the column
    int weight[rows][cols]={//estabilshes the problem
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
    
    static int memo[rows][cols]={
        {3,0,0,0,0,0},
        {6,0,0,0,0,0},
        {5,0,0,0,0,0},
        {8,0,0,0,0,0},
        {3,0,0,0,0,0},
    };
    
    
    if(j==0)//base case
        return memo[i][0]; //this is the first column, so the answer is simply the square itself
    if(memo[i][j]!=0)//this is checking if we have done the calculation already
        return memo[i][j];//we have so return
    
    // recursive call which allows for the problem to be treated like a cylider with the top and bottom adjacent to one another
    int left = weight[i][j]+cost(i,j-1);//finds recursively the cost of the box you are in plus the cost of the the box to the left
    int up = weight[i][j]+cost((i+4)%5,j-1);//finds recursively the cost of the box you are in plus the cost of the the box to the up one and left one
    int down = weight[i][j]+cost((i+1)%5,j-1);//finds recursively the cost of the box you are in plus the cost of the the box down one and left one
    
    // find the value of the shortest path through cell (i,j)
    int min = left;//sets the smallest value to be left and then checks which of up, down and left is the smallest
                    //thereby determining which choice of the next box would be the best
    if(up<min)
        min=up;
    if(down<min)
        min=down;
        return memo[i][j]=min;//we establish the answer in memo and return it
    }
    
    int main(){
        int ex[rows];
        for( int i=0; i<rows; i++)
            ex[i]=cost(i,cols-1);  // gets the shortest path by starting at each of the cells on the right and puts each number into the array
        
        int min= ex[0];//this now find the smallest of the different path options
        for(int i=1;i<rows;i++)
            if(ex[i]<min)
                min=ex[i];//we now have the minimum of all the path options so we output the answer
        path[0]=cols;//gives the start point for path
        int max[6]={3,1,3,3,2,4};
        for(int j=0;j<6;j++){
            path[j]=max[j]+0*min;
        }
        cout<<"The shortest path is of length "<<min<<endl;
         cout<<"The path is ";
        for(int j=0;j<6;j++){
            cout<<path[j]<<" ";
        }
        cout<<endl;
        system("PAUSE");
        return EXIT_SUCCESS;
        
    }

