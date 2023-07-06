bool isValidParenthesis(string exp)
{
    // Write your code here.
    if(exp.length()%2)  return false;
    stack<int> s;
    unordered_map<char, char> mp = {
      {')', '('},
      {'}', '{'},
      {']', '['}
    }; 
    for (auto ch : exp) {
      if (ch == '{' or ch == '(' or ch == '[')
        s.push(ch);
      else{
          if(s.empty()) return false;
          if (mp[ch]!=s.top())      return false;
          s.pop();
      } 
    }
    return s.empty();
}