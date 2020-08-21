
/*: c=a 23
: c=d 23
: c=e 23
: c=f 23
: c=b 23
: c=d 23
: c=e 23
: c=f 23
: c=c 23
: c=d 23
: c=e 23
: c=f 23

Output
["ad","ae","af","bd","be","bf","cd","ce","cf"]
Expected
["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> num_to_char {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> result; string combination(digits.length(), ' ');
        letterCombinations(digits, combination, 0, num_to_char, result);
        return result;
    }
    
    void letterCombinations(string digits, string& combination, int idx,  unordered_map<char, string>& num_to_char, vector<string>& result)
    {
        if (idx == digits.length()){
            result.push_back(combination);
            return;
        }
        
        for (char c : num_to_char[digits[idx]]){
            combination[idx] = c;
            cout << ": c=" << c << " " << digits << "\n";
            letterCombinations(digits, combination, idx + 1, num_to_char, result);
        }
    } 
};
