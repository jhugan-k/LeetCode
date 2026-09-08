class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // put all letter logs first, then digit logs 
        // don't reorder digit logs 
        // for letter logs: sort by content 
        // if content same: sort by identifier 
        vector<string> digitLogs; 
        
        priority_queue<pair<string,string>, vector<pair<string,string>>, greater<pair<string,string>>> pq; //content -> id for letter log

        vector<string> ans;

        for(auto s : logs){
            int i = 0;

            while(s[i] != ' ') i++; //skip identifier 
            string id = s.substr(0, i); //id 
            i++; //first char 

            if(s[i] >= 'a' && s[i] <= 'z'){
                //letter
                string content = s.substr(i, s.size()-i);
                pq.push({content, id}); //sort by lex content then lex id 

            }
            else{
                //digit 
                digitLogs.push_back(s);
                continue; //push as it is
            }

        }
        // rebuild out of pq 
        while(!pq.empty()){
            auto it = pq.top();
            string content = it.first;
            string id = it.second;
            //rebuild string
            string temp = "";
            temp += id;
            temp += ' ';
            temp += content;
            ans.push_back(temp); //push full letter string
            pq.pop();
        }
        for(auto it : digitLogs){
            ans.push_back(it); //push all digit string
        }
        return ans;
    }
};