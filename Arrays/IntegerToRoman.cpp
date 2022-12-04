#include<iostream>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string ans = "";
    string nos[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for(int i = 0; num > 0; i++){
      while(num >= val[i]){
        num -= val[i];
        ans += nos[i];
      }
    }
    return ans;
  }
};

int main() {

  return 0;
}