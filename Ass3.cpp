#include<bits/stdc++.h>
using namespace std;

int n;
int board[20][20];

// PRINT BOARD
void printBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

// CHECK SAFE POSITION
bool isSafe(int row,int col){

   // Column check
   for(int i = 0 ; i<row ; i++){
      if(board[i][col]==1)
         return false;
   }

   // Upper left diagonal
   for(int i=row, j=col ; i>=0 && j>=0 ; i--,j--){
      if(board[i][j]==1)
         return false;
   }

   // Upper right diagonal
   for(int i=row, j=col ; i>=0 && j<n ; i--,j++){
      if(board[i][j]==1)
         return false;
   }

   return true;
}

// BACKTRACKING FUNCTION
bool SolveBT(int row){

   // Base case
   if(row==n){
      printBoard();
      return true;
   }

   // Try every column
   for(int col=0; col<n; col++){

      if(isSafe(row,col)){

         // Place queen
         board[row][col]=1;

         // Recursive call
         if(SolveBT(row+1))
            return true;

         // Backtrack
         board[row][col]=0;
      }
   }

   // No position found
   return false;
}

int main(){

   cout<<"Enter n: ";
   cin>>n;

   // Initialize board with 0
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         board[i][j]=0;
      }
   }

   // Solve
   if(!SolveBT(0)){
      cout<<"No solution exists";
   }

   return 0;
}
