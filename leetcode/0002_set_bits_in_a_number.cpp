/* Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight). 
 */

class Solution {
public:
    // naive way
    int hammingWeight1(uint32_t n) {
        int set_bits = 0;
        
        for(uint32_t i = 0; n > 0 && i < (sizeof(uint32_t)*8); i++) {
            if ((n >> i) & (unsigned)0x01)
                ++set_bits;
        }
        return set_bits;
    }
    
    // Follow up: If this function is called many times, how would you optimize it?
    // Brian Kernighan's way
     int hammingWeight(uint32_t n) {
        int set_bits;
        
        for(set_bits = 0; n; ++set_bits)
            n &= (n-1);
         
        return set_bits;
    }
};
