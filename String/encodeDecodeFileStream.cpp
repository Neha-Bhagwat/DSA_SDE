// Encode and Decode a String Stream
// Problem statement
// Source note: The source preserves the task identity as tokenizing and detokenizing a stream of strings but omits a callable signature. This exercise supplies a length-prefixed practice protocol and preserves arbitrary string boundaries at about 90%.
// Implement both directions of a length-prefixed string-stream protocol.
// When operation is "ENCODE", encode values. Return a one-element array containing the encoded stream.
// When operation is "DECODE", decode stream. Return the decoded strings and ignore values.
// Each value is encoded as its decimal character length, followed by #, followed by its exact characters. Values may be empty and may themselves contain #, digits, spaces, or commas.

// For DECODE, the stream is guaranteed to be a valid encoding produced by this protocol.

// Function
// transformStringStream(operation: String, values: String[], stream: String) → String[]
// Examples
// Example 1
// operation = "ENCODE"
// values = ["api","","a#b"]
// stream = ""
// return = ["3#api0#3#a#b"]
// Lengths make the empty string and the embedded delimiter unambiguous.

// Example 2
// operation = "DECODE"
// values = []
// stream = "5#hello5#world0#"
// return = ["hello","world",""]
// Reading the decimal length before each delimiter recovers every original boundary.

// Constraints
// operation is either ENCODE or DECODE.
// 0 ≤ values.length ≤ 10^5
// Strings contain printable ASCII characters.
// The total number of characters in the relevant input is at most 10^6.
// For DECODE, stream is valid.

class Solution {
public:
  vector<string> transformStringStream(string operation, vector<string> values, string stream) {
      vector<string> ans;
      if(operation == "ENCODE")
      {
        string temp;
          // find len, append #, append values[i]
        for(int i = 0; i < values.size(); i++)
          {
            int len = values[i].size();
            temp += to_string(len);
            temp.push_back('#');
            temp += values[i];
          }
          ans.push_back(temp);
      }
      else
      {
         // if it is decode, then we store strings in an array to return
          int idx = 0, len = 0;
          while(stream[idx] != '#')
            {
              // number is present here
              len *= 10;
              len += (stream[idx] - '0');
              idx++;
            }
          // int idx = 2;
          while(idx < stream.size())
          {
              idx++;
              string temp="";
              for(int i = 0; i < len; i++)
                {
                    temp.push_back(stream[i+idx]);
                }
              ans.push_back(temp);
              idx+=len;  
              len = 0;
              while(idx < stream.size() && stream[idx] != '#')
              {
                // number is present here
                len *= 10;
                len += (stream[idx] - '0');
                idx++;
              }
          }
      }
      return ans;
  }
};
