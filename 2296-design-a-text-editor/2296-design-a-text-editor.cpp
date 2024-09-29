// class TextEditor {
//     string alltext = "";
//     int len = 0;
//     int cursor = 0;
// public:
//     TextEditor() {
//         alltext = "";
//         len = 0;
//         cursor = 0;
//     }
    
//     void addText(string text) {
//         cout << len << "    " << cursor << endl;
//         alltext += text;
//         len += text.size();
//         cursor += text.size();

//         cout << alltext << endl;
//         cout << len << "    " << cursor << endl;
//     }
    
//     int deleteText(int k) {
//         int deleted = 0;

//         if((cursor-k)>=0){
//             cursor -= k;
//             deleted = k;
//         }
//         else{
//             deleted = cursor;
//             cursor = 0;
//         }

//         len -= deleted;

//         alltext.erase(cursor,deleted );
//         return deleted;
//     }
    
//     string cursorLeft(int k) {
//         if((cursor - k)>=0)
//         cursor -= k;
//         else
//         cursor = 0;
//         int i = cursor;
//         int count = 0;
//         string ans = "";

//         if(i>=10){
//             i -= 10;
//             count = 10;
//         }
//         else{
//             count = i;
//             i=0;
//         }

//         for(int j=0;j<count;j++){
//             ans += alltext[i];
//             i++;
//         }

//         return ans;
//     }
    
//     string cursorRight(int k) {
//         if((cursor + k) <= len)
//         cursor += k;
//         else
//         cursor = len;

//         cout << "++" << cursor << endl;

//         int i = cursor;
//         int count = 0;
//         string ans = "";
//         if(i>=10){
//             i -= 10;
//             count = 10;
//         }
//         else{
//             count = i;
//             i=0;
//         }

//         for(int j=0;j<count;j++){
//             ans += alltext[i];
//             i++;
//         }

//         return ans;
//     }
// };

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

 class TextEditor {
    string alltext;  // Store the text
    int cursor;      // Store the cursor position

public:
    TextEditor() {
        alltext = "";  // Initialize text as empty
        cursor = 0;    // Initialize cursor at the start
    }
    
    // Adds 'text' at the cursor position
    void addText(string text) {
        alltext.insert(cursor, text);  // Insert text at cursor position
        cursor += text.length();       // Move cursor to the end of the newly added text
    }

    // Deletes 'k' characters to the left of the cursor
    int deleteText(int k) {
        int deleteCount = min(k, cursor);  // Calculate how many characters can be deleted
        alltext.erase(cursor - deleteCount, deleteCount);  // Erase characters
        cursor -= deleteCount;  // Move cursor left by deleteCount
        return deleteCount;     // Return the number of characters deleted
    }
    
    // Moves the cursor 'k' positions to the left
    string cursorLeft(int k) {
        cursor = max(0, cursor - k);  // Move cursor to the left, but not beyond 0
        int start = max(0, cursor - 10);  // Find the start position for the substring
        return alltext.substr(start, cursor - start);  // Return last 10 characters to the left of the cursor
    }
    
    // Moves the cursor 'k' positions to the right
    string cursorRight(int k) {
        cursor = min((int)alltext.length(), cursor + k);  // Move cursor to the right, but not beyond text length
        int start = max(0, cursor - 10);  // Find the start position for the substring
        return alltext.substr(start, cursor - start);  // Return last 10 characters to the left of the cursor
    }
};
