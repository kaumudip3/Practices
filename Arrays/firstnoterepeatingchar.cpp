// Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.
// For s = "abacabad", the output should be firstNotRepeatingCharacter(s) = 'c'.
// There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

char firstNotRepeatingCharacter(std::string s) {
    set<char> notrep;
    set<char> repeated;
   // char res = '0';
   list<char> res;
    for(auto &ch :s)
    {
        if(notrep.find(ch) != notrep.end() )
        {
            notrep.erase(ch);
            repeated.insert(ch);
            res.remove(ch);
        }
        else {
            if(repeated.find(ch) == repeated.end()){
            notrep.insert(ch);
            res.push_back(ch);
            }
        }
        
        
    }
    if(notrep.empty())
    return '_';
    else
    {
        //return res;
//        cout<< notrep.size();
        return *res.begin();
    }

}
