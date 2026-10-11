class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        for(int i=0;i<position.size();i++)
        {
            double time = double(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](pair<int, double> &a, pair<int, double> &b){return a.first> b.first;});

        stack<double> st;

        for(auto car : cars)
        {
            double time = car.second;

            if(st.empty() || time>st.top())
            {
                st.push(time);
            }
        }
        return st.size();
        
    }
};