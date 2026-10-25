class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pointer1 = 0, pointer2 = 0;
        while(pointer1 < version1.size() || pointer2 < version2.size()){
            if(version1[pointer1] == '.') pointer1++;
            if(version2[pointer2] == '.') pointer2++;
            int v1 = 0, v2 = 0;

            while(pointer1 < version1.size() && version1[pointer1] != '.'){
                v1 = v1 * 10 + (version1[pointer1] - '0');
                pointer1++;
            }

            while(pointer2 < version2.size() && version2[pointer2] != '.'){
                v2 = v2 * 10 + (version2[pointer2] - '0');
                pointer2++;
            }
            
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
        }
        return 0;
    }
};