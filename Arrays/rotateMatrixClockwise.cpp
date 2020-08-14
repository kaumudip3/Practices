// Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.
//You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
// rows become columns
int N = a.size();
//int k = n;
  // Consider all squares one by one 
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
  
            // Swap elements of each cycle 
            // in clockwise direction 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    }
return a;
}
