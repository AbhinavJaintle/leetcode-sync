class Solution {
public:
    void room(vector<vector<int>>& rooms, int index, vector<int>& vis){
        vis[index]=1;
        for(int i = 0; i<rooms[index].size(); i++){
            if(vis[rooms[index][i]]!=1){
                room(rooms,rooms[index][i],vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),-1);
        vis[0]=1;
        room(rooms,0,vis);
        for(auto& i: vis){
          if(i!=1) return false;  
        }
        
        return true;
    }
};