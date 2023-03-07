class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        char ch = 'a';

        for(auto i : key)
        {
            if(i==' ')
            {
                continue;
            }
            if(!mp.count(i))
            {
                mp[i] = ch++;
            }
        }

        // for(auto &c : message)
        // {
        //     if(mp.count(c))
        //     {
        //         c = mp[c];
        //     }
        // }
        for(int i=0;i<message.size();i++)
        {
            if(mp.count(message[i]))
            {
                message[i]  = mp[message[i]];
            }
        }
        return message;
        
    }
};
