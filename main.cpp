#include<iostream>
#include<vector>
#include<forward_list>
#include"custom_vector.h"
#include"custom_forward_list.h"
#include"custom_list.h"
int main(){
    //Вектор
    /*
    c_vector<int>a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"Size:"<<a.size()<<"\n";
    auto it=a.begin();
    for(int i=0;i<2;i++){
        ++it;
    }
    a.erase(it);
    ++it;
    a.erase(it);
    ++it;
    a.erase(it);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    it=a.begin();
    a.insert(it, 10);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    it=a.begin();
    for(int i=0;i<a.size()/2;i++){
        ++it;
    }
    a.insert(it, 20);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    a.push_back(30);
    for(int i=0;i<a.size();i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    */

    //односвязный список
    /*
    c_forward_list<int>b;
    for(int i=0;i<10;i++){
        b.push_back(i);
        std::cout<<b[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"size: "<<b.size()<<"\n";
    b.erase(1);
    b.erase(2);
    b.erase(3);
    for(int i=0;i<b.size();i++){
        std::cout<<b[i]<<" ";
    }
    std::cout<<"\n";
    b.insert(-1, 10);
    for(int i=0;i<b.size();i++){
        std::cout<<b[i]<<" ";
    }
    std::cout<<"\n";
    b.insert(b.size()/2-1, 20);
    for(int i=0;i<b.size();i++){
        std::cout<<b[i]<<" ";
    }
    std::cout<<"\n";
    b.push_back(30);
    for(int i=0;i<b.size();i++){
        std::cout<<b[i]<<" ";
    }
    std::cout<<"\n";
    */
    
    // двухсвязный список
    c_list<int>c;
    for(int i=0;i<10;i++){
        c.push_back(i);
        std::cout<<c[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"size: "<<c.size()<<"\n";
    c.erase(2);
    c.erase(3);
    c.erase(4);
    for(int i=0;i<c.size();i++){
        std::cout<<c[i]<<" ";
    }
    std::cout<<"\n";
    c.push_front(10);
    for(int i=0;i<c.size();i++){
        std::cout<<c[i]<<" ";
    }
    std::cout<<"\n";
    c.insert(c.size()/2, 20);
    for(int i=0;i<c.size();i++){
        std::cout<<c[i]<<" ";
    }
    std::cout<<"\n";
    c.push_back(30);
     for(int i=0;i<c.size();i++){
        std::cout<<c[i]<<" ";
    }
    std::cout<<"\n";
    c.insert(c.size()/2, 20);
    for(int i=0;i<c.size();i++){
        std::cout<<c[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}