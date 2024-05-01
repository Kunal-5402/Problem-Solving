class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        stack<char> s;
        for(auto &c: word){
            if(c == ch){
                s.push(c);
                break;
            }
            i++;
            s.push(c);
        }
        if(i == word.size())
            return word;
        i = 0;
        while(s.size() > 0){
            word[i] = s.top();
            s.pop();
            i++;
        }
        return word;
    }
};