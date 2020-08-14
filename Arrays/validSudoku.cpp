

//Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, 
// each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.
// Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the 
// layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

bool sudoku2(std::vector<std::vector<char>> grid) {

 int n = grid.size();
 set<char> duplicateinrow;
 for(int i=0;i<n;i++)
 {
     duplicateinrow.clear();
     for(int j=0;j<n;j++)
     {
         if(grid[i][j] == '.')
         continue;
         cout << grid[i][j] <<" ";
         if(duplicateinrow.find(grid[i][j]) != duplicateinrow.end()){
             cout<<"duplicate in row :";
         return false;
         }
         else {
         duplicateinrow.insert(grid[i][j]);
         }
         int k=i+1;
         // check columns
             while(k<n )
             {
                
                 if(grid[k][j] == grid[i][j] && grid[k][j]!='.'){
                 cout<< "dup at col"<< j <<" " << k;
                 return false;
                 }
                 k++;
             }
         // check sub matrix 3-3 for duplicate
         for(int ii = (i/3)*3; ii<(i/3+1)*3;ii++)
         {
             for(int jj = (j/3)*3; jj<(j/3+1)*3;jj++)
             {
                 if(grid[ii][jj] == grid[i][j] && ii!=i && jj!=j){
                     cout << "duplicate "<<ii << " "<< jj;
                 return false;
                 }
             }
             
         }
         }
         
         cout<<"\n";
     }
     return true;
 }

