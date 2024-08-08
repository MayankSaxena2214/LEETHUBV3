//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

    void solve(string &digits,vector<string>&ans,string temp,int index){
        if(index==digits.size()){
            ans.push_back(temp);
            return ;
        }
        int idx=digits[index]-'0';
        string word=mp[idx];
        for(int i=0;i<word.length();i++){
            temp.push_back(word[i]);
            solve(digits,ans,temp,index+1);
            temp.pop_back();
        }

    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string digits;
        for(int i=0;i<N;i++){
            char ch=a[i]-0+'0';
            digits+=ch;
        }
        if(digits.length()==0)return {};
        vector<string>ans;
        string temp;
        solve(digits,ans,temp,0);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends