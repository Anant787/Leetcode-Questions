class Solution {
    void put_formed_in_stack(stack<string> &s,int c){
        map<string,int> m;
        while(!s.empty() && (s.top() != "(")){
            // cout<<s.top()<<endl;
            string temp = "";
            int count = 0;
            for(int i = 0;i < s.top().length();i++){
                char x = s.top()[i];
                    // cout<<x<<endl;
                if((x >= 'a' && x <= 'z') || temp.length() == 0){
                    temp += x;
                }else if(x >= '0' && x <= '9'){
                    count = (count * 10) + int(x - '0');
                }else if(temp.length() != 0){
                    if(count == 0) count = 1;
                    // cout<<temp<<" "<<count<<endl;
                    m[temp] += count;
                    temp = "";
                    i--;
                    count = 0;
                }
            }
            if(temp.length() != 0){
                // cout<<temp<<" "<<count<<endl;
                if(count == 0) count++;
                m[temp] += count;
            }
            s.pop();
        }
        if(!s.empty()) s.pop();

        string ans = "";
        for(auto [x,y] : m){
            // cout<<x<<" "<<y<<endl;
            ans += x;
            if(y*c > 1) ans += to_string(y * c);
        }
        // cout<<ans<<endl<<endl;
        s.push(ans);
    }
public:
    string countOfAtoms(string &f) {
        int n = f.length();
        stack<string> s;
        for(int i = 0;i < n;){
            if(f[i] == '('){
                s.push("(");
                i++;
            }else if(f[i] == ')'){
                i++;
                int count = 0;
                while(i < n && (f[i] >= '0' && f[i] <= '9')){
                    count = (count * 10) + int(f[i++] - '0'); 
                }
                // cout<<count<<endl;
                if(count == 0) count++;
                put_formed_in_stack(s,count);
            }else{
                string ele = "";
                ele += f[i++];
                while(i < n && (f[i] >= 'a' && f[i] <= 'z') || (f[i] >= '0' && f[i] <= '9')){
                    ele += f[i++];
                }
                // cout<<ele<<endl;
                s.push(ele);
            }
        }
        put_formed_in_stack(s,1);
        return s.top();
    }
};
