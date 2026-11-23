class ProductOfNumbers {
private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {

        // Reset when zero appears
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            int last = prefix.back();
            prefix.push_back(last * num);
        }
    }

    int getProduct(int k) {

        int n = prefix.size();

        // Requested range contains a zero
        if (k >= n) {
            return 0;
        }

        // Prefix division
        return prefix[n - 1] / prefix[n - 1 - k];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */