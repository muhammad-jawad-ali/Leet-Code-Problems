class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                fives++;
            } else if (bill == 10) {
                if (fives == 0) {
                    return false;  // Can't give change for a $10 bill.
                }
                fives--;
                tens++;
            } else {  // bill == 20
                if (tens > 0 && fives > 0) {
                    // Prefer giving one $10 bill and one $5 bill as change.
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    // Otherwise, give three $5 bills as change.
                    fives -= 3;
                } else {
                    return false;  // Can't give change for a $20 bill.
                }
            }
        }
        return true;
    }
};
