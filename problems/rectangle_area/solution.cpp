class Solution {
public:
    bool belongs(int c1, int c2, int d1, int d2){
        if((c1<d1&&d1<c2)||(c1<d2&&d2<c2)||(d1<c1&&c1<d2)||(d1<c2&&c2<d2)||(c1==d1&&c2==d2)){
            return true;
        }
        return false;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int count = (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
    
        if(belongs(ax1,ax2,bx1,bx2)&&belongs(ay1,ay2,by1,by2)){
            count-=(min(ax2,bx2)-max(ax1,bx1))*(min(ay2,by2)-max(ay1,by1));
        }
        return count;
    }
};