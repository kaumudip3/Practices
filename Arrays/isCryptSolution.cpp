
// You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits, solution. T
// he array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3], which should be 
// interpreted as the word1 + word2 = word3 cryptarithm.
// If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution,
// becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true. If it does not become a 
// valid arithmetic solution, the answer is false.
//Note that number 0 doesn't contain leading zeroes (while for example 00 or 0123 do).

/*For crypt = ["SEND", "MORE", "MONEY"] and

solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]
the output should be
isCryptSolution(crypt, solution) = true.

When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.

2)
crypt:
["A", 
 "A", 
 "A"]
solution: [["A","0"]]
Expected Output:
true
3)
crypt:
["AA", 
 "AA", 
 "AA"]
solution: [["A","0"]]
Expected Output:
false

*/
long getNum(std::string word, std::vector<std::vector<char>> solution)
{
    string temp = "";
    for(auto &ch : word)
    {
        for(int i=0;i<solution.size();i++)
        {
            if(ch == solution[i][0])
            temp+= solution[i][1];

        }
    }
    long res = (long)atoi(temp.c_str());
    if(temp[0] == '0' && temp.size() >1) // leading zeros
    return -1;
    
    return res;
}

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    //crypt is always 3 words
     
    if( max(crypt[0].size(), crypt[1].size()) > crypt[2].size() )
    return false;
    
    long num1, num2, num3;
    
    num1 = getNum(crypt[0], solution);
    cout<< num1;
    num2 = getNum(crypt[1], solution);
    cout<< " "<< num2;
    num3 = getNum(crypt[2], solution);
    cout<< " "<< num3;
    if(num3 == (num1+num2) )
    return true;
    else {
    return false;
    }
}
