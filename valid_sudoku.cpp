class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
 set<char> duplicateinrow;
 for(int i=0;i<n;i++)
 {
     duplicateinrow.clear();
     for(int j=0;j<n;j++)
     {
         if(board[i][j] == '.')
         continue;
         //cout << board[i][j] <<" ";
         if(duplicateinrow.find(board[i][j]) != duplicateinrow.end()){
            // cout<<"duplicate in row :";
         return false;
         }
         else {
         duplicateinrow.insert(board[i][j]);
         }
         int k=i+1;
         // check columns
             while(k<n )
             {
                
                 if(board[k][j] == board[i][j] && board[k][j]!='.'){
               //  cout<< "dup at col"<< j <<" " << k;
                 return false;
                 }
                 k++;
             }
         // check sub matrix 3-3 for duplicate
         for(int ii = (i/3)*3; ii<(i/3+1)*3;ii++)
         {
             for(int jj = (j/3)*3; jj<(j/3+1)*3;jj++)
             {
                 if(board[ii][jj] == board[i][j] && ii!=i && jj!=j){
                  //   cout << "duplicate "<<ii << " "<< jj;
                 return false;
                 }
             }
             
         }
         }
         
        // cout<<"\n";
     }
     return true;

    }
};
