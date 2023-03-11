class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s(allowed.begin(),allowed.end()); //declear set

        int count=0;  //count the number of matched string

        for(auto &i : allowed)  //insert the element in set 
        {
            s.insert(i);
        }

        for(int i=0;i<words.size();i++)  //iterate over the words
        {
            int temp =0; //temporary count the size of element present in words of string 
            for(auto ch : words[i])
            {
                if(s.find(ch) != s.end() )
                {
                    temp++;
                }
            }

            if(temp == words[i].size())  //if total count of elements in words is not differ from thw element in set,increase the count
            {
                count++;
            }
        }
        return count;  //return the count
        
    }
};
