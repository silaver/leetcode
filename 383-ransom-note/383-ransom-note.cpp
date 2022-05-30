class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        //declaring a hashmap
        unordered_map<char, int> mp;
        
        //store all occurences of magazine in map
        for(auto ch: magazine) 
            mp[ch]++;
        
        //check all chars in ransomnote are present in map or not
        for(auto ch: ransomNote ) 
            mp[ch]--;
        
        //check for all chars of ransomNote in map if count is less than 0, means atleast one character not found in ransomNote
        
        for(auto ch: ransomNote ){
            if(mp[ch]<0) 
                return false;
        } 
        
        //all characters are either 0 or greater than 0 after subtracting the frequency -> return true
        return true;
    
    }
};