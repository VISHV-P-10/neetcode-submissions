class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //if the size of the strings diffres then its impossible to be them as isomorphic
        if(s.size()!=t.size()) return false;
        // need to make 2 maps
        
        unordered_map<char,char>mapST;
        unordered_map<char,char>mapTS;
        // traver throguh out the stirng
        for(int i=0;i<s.size();i++){
            char c1 = s[i];
            char c2 = t[i];
            // there are two conditions for the each char
            // if its pressents in the map already then 
            if(mapST.count(c1)){
                if(mapST[c1]!=c2) return false;
            } 
            // if not present in the strinf
            else{
                mapST[c1]=c2;
            }

            // now the same for the other set of the map
            if(mapTS.count(c2)){
                if(mapTS[c2]!=c1) return false;
            }
            else{
                mapTS[c2]=c1;
            }
        }
        return true;
    }
};