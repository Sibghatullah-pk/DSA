// #include<iostream>
// #include<cmath>
// using namespace std;


// int convert (int a){
//  int dec =0,i=0,rem;
//   while(a!=0)
//   {
//     rem= a%10;
//     a=a/10;
//     dec+=rem*pow(2,i);
//     i++;
//   }   
//   return dec;
// }
// int main(){
//     int a;
//     cout<<"enter nay value";
//     cin>>a;
//     cout << a << " in binary = " << convert(a) << " in decimal";
//     return 0;   


// }1011



#include<iostream>
#include<stack>
using namespace std;
// void dec_to_bin(int number) {
//    stack<int> stk;
//    while(number > 0) {
//       int rem = number % 2; //take remainder
//       number = number / 2;
//       stk.push(rem);
//    }
//    while(!stk.empty()) {
//       int item;
//       item = stk.top();
//       stk.pop();
//       cout << item;
//    }
// }
int main() {
   int num;
    stack<int> stk;
   cout << "Enter a number: ";
   cin >> num;
   stk.pop();
   stk.pop();
   stk.push(10);
cout << num;
   
//    dec_to_bin(num);
}
