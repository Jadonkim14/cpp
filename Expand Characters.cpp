#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string input;
    getline(cin, input);

    for(int i=0;i<input.length();i++){
        if(input[i] == '-'){
            if(input[i-1] == input[i+1]){  // a-a 的形式
                input.erase(i, 1);
            }
            else if(input[i-1] < input[i+1]){  // a-c 的形式
                string add;
                char front = input[i-1];
                char back = input[i+1];
                while(front<back){
                    front += 1;
                    add += front;
                }
                input = input.substr(0,i) + add + input.substr(i+2);
            }
            else if(input[i-1] > input[i+1]){  // c-a 的形式
                string add;
                char front = input[i-1];
                char back = input[i+1];
                while(front>back){
                    front -= 1;
                    add += front;
                }
                input = input.substr(0,i) + add + input.substr(i+2);
            }
        }
    }
    
    cout << input;

    return 0;
} 