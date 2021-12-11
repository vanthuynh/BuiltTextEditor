class Solution {
public:

    /* there has to be a condition which makes the runtime 
        faster and not letting the loop happend infinitely */
    bool isHappy(int n) {
        int lastDigit = 0;
        int result = 0;
        
        // Evaluate each result
        while (result != 1) {
            
            // Calculation for each result
            while (n != 0) {
                lastDigit = n % 10;
                result += lastDigit * lastDigit;
                n = n / 10;
            }
            /* Key Concept */
			// _this condition is needed for the calculation not to loop endlessly
			// _this also help reduce runtime by not repeat calculation for 1 to 9
            if(result < 10){
                if(result == 1 || result == 7)  return true;
                else                            return false;
            }
            n = result;
            result = 0;
        }
        return true;
    }
    
};