/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int temp = n/2;
        while(guess(temp)!=0){
            if(guess(temp)==-1){
                temp--;
            }
            else{
                temp++;
            }
        }
        return temp;
        
    }
};