#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int firstWordIndex = 0, lastWordIndex = 0, len = 0;
    vector<string> lines;

    for(int i = 0; i < words.size(); i++){
        if(len == 0){
            firstWordIndex = i;
            len = words[i].length();
        } else if(len + words[i].length() + 1 > maxWidth){
            string line = "";
            lastWordIndex = i - 1;
            if(firstWordIndex == lastWordIndex){
                line = words[firstWordIndex];
                line.append(maxWidth - words[firstWordIndex].length(), ' ');
            } else {
                int blancNumber = maxWidth - len;
                int rightBlancNumber = blancNumber / (lastWordIndex - firstWordIndex) + 1;
                int leftBlancNumber = rightBlancNumber + 1;
                int firstRightIndex = firstWordIndex + blancNumber - (rightBlancNumber - 1) * (lastWordIndex - firstWordIndex);

                for(int j = firstWordIndex; j <= lastWordIndex; j++){
                    line += words[j];
                    if(j < firstRightIndex){
                        line.append(leftBlancNumber, ' ');
                    } else if(j != lastWordIndex){
                        line.append(rightBlancNumber, ' ');
                    }
                }
            }
            lines.push_back(line);
            firstWordIndex = i;
            len = words[i].length();
        } else {
            len += words[i].length() + 1;
        }
    }
    string line = "";
    for(int i = firstWordIndex; i < words.size(); i++){
        line += words[i];
        if(i != words.size() - 1){
            line += " ";
        }
    }
    line.append(maxWidth - len, ' ');
    lines.push_back(line);
    return lines;
}


