

//Input:"-1/2+1/2"
// Output: "0/1"

//Input:"-1/2+1/2+1/3"
// Output: "1/3" 

class Solution {
public:
int findgcd(int a, int b) {
    if(b == 0) return a;
    return findgcd(b, a%b);
}
void add(int& a, int& b, int c, int d) {
    int nume = a*d + c*b, deno = b*d;
    int gcd = findgcd(abs(nume), abs(deno)); // reduce fraction
    a = nume / gcd;
    b = deno / gcd;
}
string fractionAddition(string expression) {
    stringstream ss(expression);
    char op;
    int a, b, c, d;
    ss >> a; 
    ss >> op; 
    ss >> b;
    while(ss >> c) {
        ss >> op; 
        ss >> d;
        add(a, b, c, d);
    }
    return to_string(a) + "/" + to_string(b);
}};
