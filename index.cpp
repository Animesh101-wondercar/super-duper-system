#include<iostream>
#include<map>
int main(){
    std::map<int,int> mpp;
    mpp[5]++;
    for(auto it:mpp){
    printf("%d", it);
    }
    return 0;
}