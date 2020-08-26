template<typename T>
void insert_sort(const T beg,const T end){
    if(beg!=end){
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
}

template<typename T, typename Bin>
void insert_sort(const T beg,const T end,Bin binary){
    if(beg!=end){
    for(T it = beg+1;it!=end;++it){
        if(binary(*it,*(it-1))){
            typename std::remove_reference<decltype(*it)>::type temp = std::move(*it);
            for(T it1 = it-1; it1 >= beg; --it1){
                if(binary(temp,*it1))
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
}