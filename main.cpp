#include <iostream>
#include <vector>
using namespace std;

void output(vector<int> equationNumbers) {
  //output vector<int>
  for(int i = 0; i < equationNumbers.size(); i++) {
    if(i != (equationNumbers.size() - 1)) {
      cout << equationNumbers[i] << ", ";
    } else {
      cout << equationNumbers[i];
    }
  }
  cout << endl;
}

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


int main() {
  int userInput = 0;
  vector<int> equationNumbers;
  vector<int> previous = {1, 1};
  
  cout << "Number of quadratic generations: ";
  cin >> userInput;

  for(int i = 0; i < userInput; i++) {
    if(i == 0) {
      //1st gen
      equationNumbers = {1};
      output(equationNumbers);
      
    } else if(i == 1) {
      //2nd gen (to the second)
      equationNumbers = {1, 1};
      output(equationNumbers);
      previous = equationNumbers;
      
    } else {      
      equationNumbers = calculateVectors(previous);
      output(equationNumbers);
      previous = equationNumbers;
    }
  }
}
      

  