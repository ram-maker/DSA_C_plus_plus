#include <iostream>
using namespace std;
int *sortArray(int *array,int array_size){
    int tmp=0;
    for(int j=0;j<array_size-1;j++){
        for (int i=0;i<array_size-1;i++){
            if(array[i]>array[i+1]){
                tmp=array[i];
                array[i]=array[i+1];
                array[i+1]=tmp;
            }
        }      
    }
    int *sorted_array=new int[array_size];
    sorted_array=array;
    return sorted_array;
}

float calculate_median(int *ascending_array,int size){
    float median=0;
    int first_median_term=0;
    int rem=size%2;
    if (rem==0){
       first_median_term=ascending_array[size/2-1];
       int second_median_term=ascending_array[size/2]; 
       median=static_cast<float>(first_median_term+second_median_term)/2;
    }
    else{
        median=ascending_array[size/2];
    }
    return median;
}

int main(){
    int array[]={50,23,0,28,190,1};
    int size=sizeof(array)/sizeof(array[0]);
    int *sorted_array=sortArray(array,size+1);
    cout<<"The sorted array is:"<<endl;
    for (int i=0;i<size;i++){
        cout<<sorted_array[i]<<" ";
    }
    cout<<endl;
    float median=calculate_median(sorted_array,size); 
    cout<<"Median is:"<<median<<endl;
    return 0;
}