class Solution {
public:
    void reverse(string& str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            char t = str[left];
            str[left] = str[right];
            str[right] = t;
            left++;
            right--;
        }
    }

    string decodeString(string s) {
        string ans = "";
        vector<char> st;

        for (char c : s) {
            if (c != ']') {
                st.push_back(c);
            }
            else {
                string temp = "";

                while (st.back() != '[') {
                    temp += st.back();
                    st.pop_back();
                }

                st.pop_back();
                reverse(temp);

                string number = "";

                while (!st.empty() && st.back() >= '0' && st.back() <= '9') {
                    number += st.back();
                    st.pop_back();
                }

                reverse(number);
                int repeate = stoi(number);

                string original = temp;

                for (int i = 1; i < repeate; i++) {
                    temp += original;
                }

                for (char x : temp) {
                    st.push_back(x);
                }
            }
        }

        for (char c : st) {
            ans += c;
        }

        return ans;
    }
};