class Solution {
public:
    int countSubstrings(string s) {
        int pal_ct = 0;
        int n = s.length();
        for (int mid = 0; mid < n; mid++)
        {
            for (int x = 0; mid - x >= 0 && mid + x < n; x++)
            {
                if (s[mid - x] != s[mid + x])
                    break;
                pal_ct++;
            }
        }

        for (int mid = 0; mid < n - 1; mid++)
        {
            for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++)
            {
                if (s[mid - x + 1] != s[mid + x])
                    break;
                pal_ct++;
            }
        }

        return pal_ct;
    }
};