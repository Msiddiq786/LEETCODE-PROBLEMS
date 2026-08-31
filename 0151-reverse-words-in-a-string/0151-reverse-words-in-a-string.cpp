class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.size() - 1;

        while (i >= 0) {

            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            // Find the beginning of the current word
            while (j >= 0 && s[j] != ' ')
                j--;

            // Append the word
            ans += s.substr(j + 1, i - j);

            // Skip spaces before the next word
            while (j >= 0 && s[j] == ' ')
                j--;

            // Add a space if another word exists
            if (j >= 0)
                ans += " ";

            i = j;
        }

        return ans;
    }
};