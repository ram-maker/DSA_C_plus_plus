#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    void romanToInt(string roman_digit) {
        int int_value=0;
       for (char ch:roman_digit){
            int_value=execute_process(ch,roman_digit);    
           break;
       } 
       cout<<"Integer Value:"<<int_value<<endl;
    }

    int return_int_value(char frist_roman_digit){
        int a;
        switch (frist_roman_digit){
            case 'I':a=1;break;
            case 'V':a=5;break;
            case 'X':a=10;break;
            case 'L':a=50;break;
            case 'C':a=100;break;
            case 'D':a=500;break;
            case 'M':a=1000;break;
        }
        return a;   
    }

    int execute_process(char frist_roman_digit,string roman_integer){
        int a;
        switch (frist_roman_digit){
            case 'I':return process_ones(roman_integer);break;
            case 'V':return process_ones(roman_integer);break;
            case 'X':return process_tens(roman_integer);break;
            case 'L':return process_tens(roman_integer);break;
            // case 'C'||'D':a=100;break;
            // case 'M':a=1000;break;
          
        }
        return a;   
    }

    int add_or_sub(char roman_digit[],int int_number[]){
        int tmp;
        if (roman_digit[0]=='I'){
            if (roman_digit[1]=='V'||roman_digit[1]=='X'){
                tmp=int_number[1]-int_number[0];
                return tmp;
            }
        }
      if (roman_digit[0]=='X'){
            if (roman_digit[1]=='L'||roman_digit[1]=='C'){
                tmp=int_number[1]-int_number[0];
                return tmp;
            }
        }
       if (roman_digit[0]=='C'){
             if (roman_digit[1]=='D'||roman_digit[1]=='M'){
                tmp=int_number[1]-int_number[0];
                return tmp;
            }
        }
        tmp=int_number[1]+int_number[0];
        return tmp;
    }

    int process_ones(string roman_digit){
        // cout<<"Roman digit:"<<roman_digit<<endl;
        int int_values[2];
        char tmp_roman_digit[2];
        int i=0;
        int roman_value=0;
       for (char ch:roman_digit){
            int_values[i]=return_int_value(ch);
            tmp_roman_digit[i]=ch;    
            i++;      
            if(i==2){
                roman_value=roman_value+add_or_sub(tmp_roman_digit,int_values);
                i=0;
            }       
           
       } 
       if(i==1){
        roman_value=roman_value+int_values[0];
       }
       cout<<"Roman value in process one:"<<roman_value<<endl;
        return roman_value; 
    }

    int process_tens(string roman_digit){
        
    }
    
};
int main(){
    Solution(roman_digit);
    roman_digit.romanToInt("III");
    return 0;
}
