
// Using comperator    // Tricky solution 

class FoodRatings {
public:
   class comp{
       public:
    bool operator() (pair<int,string>const&a,pair<int,string>const&b) {
        
        if(a.first==b.first){
            return a.second>=b.second;
        }
        return a.first<b.first;
    }
       
   };    


unordered_map<string, pair<int, string>> e;
unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>> c;


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i =0;i<foods.size();i++){
            e[foods[i]]={ratings[i],cuisines[i]};
            c[cuisines[i]].push({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        e[food].first= newRating;
        string cuisine = e[food].second;
        c[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        pair<int,string> f ;
        f = c[cuisine].top();
        while((e[f.second].first)!=f.first){
            c[cuisine].pop();
            f = c[cuisine].top();
        }
        return f.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
