class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int i=numBottles;
        int carry = 0;
        while(numBottles>=numExchange){
            carry = 0;
            i += (numBottles/numExchange);
            carry = numBottles%numExchange;
            numBottles = numBottles/numExchange + carry;
            cout << i << "     carry: " << carry << "     remaining: " << numBottles << endl;
        }
        return i;
    }
};