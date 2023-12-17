struct cmp {
 //use const for return type and parameters for both
 bool operator() (const pair<int,string> &a,const pair<int,string> &b) const {        
       if(a.first==b.first) return a.second<b.second;
       return a.first>b.first;
 }
 };

class FoodRatings {
unordered_map<string,int> food_rating;
unordered_map<string,string> food_cus;
unordered_map<string,set<pair<int,string>,cmp>> cus_food_rat;
public:

//O(N)
FoodRatings(vector<string>& a, vector<string>& b, vector<int>& c) {
    int n= a.size();
    for(int i=0;i<n;i++){
        food_cus[a[i]]= b[i];
        food_rating[a[i]]= c[i]; 
        cus_food_rat[b[i]].insert({c[i],a[i]});
    }
}

//O(logn)
void changeRating(string f, int R) {
    string cuison= food_cus[f];
    cus_food_rat[cuison].erase({food_rating[f],f});
    cus_food_rat[cuison].insert({R,f});
    food_rating[f]=R;
}

//O(logn)
// *(cfr[c].begin()) -> get first in set
string highestRated(string c) {
    pair<int,string> p= *(cus_food_rat[c].begin());
    return p.second;
}
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */