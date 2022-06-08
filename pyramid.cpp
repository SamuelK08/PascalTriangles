#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateVectors(vector<int> inputVector) {
  vector<int> result;
  int tempNum = 0;
  
  for(int i = 0; i < inputVector.size() + 1; i++) {
    if(i == inputVector.size() || i == 0) {
      tempNum = 1;
    } else {
      tempNum = inputVector[i] + inputVector[(i - 1)];
    }
    result.push_back(tempNum);
  }
  return result;
}

string repeatChar(char inputChar, int number) {
  string result = "";
  for(int i = 0; i < number; i++) {
    result += inputChar;
  }
  return result;
}

void output(vector<vector<int>> outputVectors, int bCounter) {
  int spaceCounter = 0;
  int posVector = 0;
  int spacing = bCounter / 2;
  
  for(int i = 0; i < outputVectors.size(); i++) {
    int posVector = 0;
    
    if(i == 0) {
      cout << repeatChar(' ', spacing) << outputVectors[i][0] << repeatChar(' ', spacing);
    } else {
      cout << repeatChar(' ', (spacing - spaceCounter));
      while(posVector != outputVectors[i].size()) {
        if(posVector == outputVectors[i].size() - 1) {
          cout << outputVectors[i][posVector];
        } else {
          cout << outputVectors[i][posVector] << " ";
        }
        posVector++;
      }
      
    }
    cout << endl;
    spaceCounter++;
  }
}

int main() {
  int userInput = 0;
  int bottomCounter = 0;
  vector<int> vectorNumbers;
  vector<vector<int>> outputVectors;
  vector<int> previous = {1, 1};
  
  cout << "Number of quadratic generations: ";
  cin >> userInput;

  for(int i = 0; i < userInput; i++) {
    if(i == 0) {
      //1st gen
      vectorNumbers = {1};
      outputVectors.push_back(vectorNumbers);
      
    } else if(i == 1) {
      //2nd gen (to the second)
      vectorNumbers = {1, 1};
      outputVectors.push_back(vectorNumbers);
      previous = vectorNumbers;
      
    } else {      
      vectorNumbers = calculateVectors(previous);
      outputVectors.push_back(vectorNumbers);
      previous = vectorNumbers;
    }
  }

  for(int i = 0; i < outputVectors.size(); i++) {
    int counter = 0;
    string bottomNumbers = to_string(outputVectors[outputVectors.size() - 1][i]);
    bottomCounter += bottomNumbers.size();
    if(i != outputVectors.size() - 1) {
      bottomCounter++;
    }
  }

  output(outputVectors, bottomCounter);
}
      

  