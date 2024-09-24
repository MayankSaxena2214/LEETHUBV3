//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p) {
    if (p.length() > s.length()) return "-1";  // If p is larger than s, no such window can exist.

    vector<int> p_freq(128, 0);  // Frequency map for characters in p.
    vector<int> window_freq(128, 0);  // Frequency map for characters in the current window.
    
    // Populate the frequency map for p.
    for (char ch : p) p_freq[ch]++;
    
    int required = p.length();  // Total number of characters needed.
    int i = 0, j = 0, min_window = INT_MAX, start_idx = 0;
    
    while (j < s.length()) {
        char ch = s[j];
        
        // If the current character is in p, decrease the required count.
        if (p_freq[ch] > 0) {
            window_freq[ch]++;
            if (window_freq[ch] <= p_freq[ch]) {
                required--;
            }
        }
        
        // When the required count reaches 0, we found a valid window.
        while (required == 0) {
            int curr_window_size = j - i + 1;
            if (curr_window_size < min_window) {
                min_window = curr_window_size;
                start_idx = i;
            }
            
            // Try to shrink the window from the left.
            char start_char = s[i];
            if (p_freq[start_char] > 0) {
                window_freq[start_char]--;
                if (window_freq[start_char] < p_freq[start_char]) {
                    required++;
                }
            }
            i++;
        }
        
        j++;
    }
    
    return min_window == INT_MAX ? "-1" : s.substr(start_idx, min_window);
}

};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends