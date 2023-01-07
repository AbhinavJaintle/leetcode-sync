class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume;
        int bulky=0;
        int heavy =0;
        if(mass>=100) heavy++;
        volume = (long long)length*width*height;
        if(volume>=1e9) bulky++;
        else if(length>=1e4||width>=1e4||height>=1e4) bulky++;
        if(bulky==0&&heavy==0) return "Neither";
        if(bulky==1&&heavy==1) return "Both";
        if(bulky==1) return "Bulky";
        return "Heavy";
    }
};