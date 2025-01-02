#include <iostream>
using namespace std;
// int sortArray(int *array,int array_size){
//     int *tmp=new int[array_size];
//     tmp=array;
//     int tmp_number;
//     for(int i=0;i<array_size;i++){
//         for (int j=1;j<array_size;j++){
//             if (*(array+i)>*(array+j)){
//                 tmp[i]=
//             }
//         }
//     }
// }

int main(){
    int array[]={50,23,500,28,190,1};
    int size=6;
    int tmp;
    int loop_count=size-1;
    for (int j=0;j<loop_count;j++){
        for (int i=0;i<loop_count;i++){  
            if (array[i]>array[i+1]){
                tmp=array[i];
                array[i]=array[i+1];
                array[i+1]=tmp;
            }
            
        }
        cout<<j<<". ";
            for (int i=0;i<6;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
            // loop_count--;

    }
    // for (int i=0;i<6;i++){
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}