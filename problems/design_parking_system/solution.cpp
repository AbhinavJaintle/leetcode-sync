class ParkingSystem {
    int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            b--;
            return b>=0;
        }
        if(carType==2){
            m--;
            return m>=0;
        }
        s--;
        return s>=0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */