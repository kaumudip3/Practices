class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
        if(matrix.size() == 0) return res;
        
        int m = matrix.size();
        int n = matrix[0].size();
    
       
     int i=0, j=0, ie=m, je=n;
        while(i < ie && j < je)
        {
            //right
            for(int jj = j;jj < je;jj++)
            {
                res.push_back(matrix[i][jj]);
            }
            // down
            for(int ii = i+1;ii < ie;ii++)
           {
                res.push_back(matrix[ii][je-1]);
            }
            if(i < ie-1 && j < je-1)
            {
                //left
                 for(int jj = je-2;jj > j;jj--)
           {
                res.push_back(matrix[ie-1][jj]);
            }
                //up
                 for(int ii = ie-1;ii > i;ii--)
           {
                res.push_back(matrix[ii][j]);
            }
                
            }
            
            // inner circle
            i++;
            ie--;
            j++;
            je--;
            
        }      
        return res;
    }
};
