class Solution {
public:
    class UF{
    public:
        vector<int> parent;
        UF(){
            parent = vector<int>(26,0);
            for(int i=0;i<26;i++){
                parent[i] = i;
            }
        }
        void Union(int a, int b){
            int roota = Find(a);
            int rootb = Find(b);
            if(roota==rootb){
                return;
            }
            parent[roota] = rootb;
            return;
        }
        int Find(int x){
            if(parent[x]!=x){
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }
        bool connected(int a,int b){
            return Find(a)==Find(b);
        }
    };
    bool equationsPossible(vector<string>& equations) {
        UF uf;
        for(string& equa:equations){
            if(equa[1]=='='){
                int a = equa[0]-'a';
                int b = equa[3]-'a';
                uf.Union(a,b);
            }
        }
        for(string& equa:equations){
            if(equa[1]=='!'){
                int a = equa[0]-'a';
                int b = equa[3]-'a';
                if(uf.connected(a,b)){
                    return false;
                }
            }
        }
        return true;
    }
};