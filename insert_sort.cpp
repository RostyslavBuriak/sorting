#include <vector>
#include <iostream>

template<typename T>
void insert_sort(const T beg,const T end){
    for(T it = beg+1;it!=end;++it){
        if(*it < *(it-1)){
            typename std::remove_reference<decltype(*it)>::type temp = std::move(*it);
            for(T it1 = it-1; it1 >= beg; --it1){
                if(temp < *it1)
                    *(it1+1) = std::move(*it1);
                else{
                    *(it1+1) = std::move(temp);
                    break;
                }
                if(it1 == beg){
                    *it1 = std::move(temp);
                    break;
                }
            }
        }
    }
}

int main(){
    std::vector<int> v{9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5};
    auto x = v.begin();

    insert_sort(v.begin(),v.end());
    for(auto x : v){
        std::cout << x;
    }
}