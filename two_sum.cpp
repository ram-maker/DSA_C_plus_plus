#include <iostream>
#include <vector>
using namespace std;

int* returns_indices(int nums[], int target){
    static int tmp[2];
    for (int i=0;i<3;i++){
        for (int j=1;j<=3;j++){
            if (nums[j]+nums[i]==target)

            {
               tmp[0]=i;
               tmp[1]=j;
            }
        }
    }
    return tmp;
}

int main(){
    int nums[]={2,7,11,15};
    int target=18;
    int indices[2];
    int *sth;
    sth=returns_indices(nums,target);
    int i=0;
    for (int i=0;i<2;i++){
        indices[i]=sth[i];
    }
    cout<<"The array are :"<<indices[0]<<","<<indices[1]<<endl;
    return 0;
}

