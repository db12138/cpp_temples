#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>
#include <queue>
using namespace std;
// c++ 数据结构熟悉  
int VectorOperator()
{
    //基本操作  push  size  
    vector<int> vec;
    for(int i=0;i<55;i++)
    {
        vec.push_back(i);
    }
    //初始化  插入
    vec.insert(vec.begin(),-1);
    vec.insert(vec.begin()+20,1000);
    cout<<vec.size()<<endl;
    //找最大值 下标
    auto index = max_element(vec.begin(),vec.end());
    cout<<"max_ index:"<<index - vec.begin()<<endl;
    cout<<"max_ value:"<<*index<<endl;
    //遍历
    auto v_it = vec.begin();
    for(;v_it != vec.end();v_it++)
    {
        cout<< *v_it<<"  ";
    }
    cout<<endl;
    // vector<int > ::iterator v = vec.begin();
    // for(;v != vec.end();v++)
    // {
    //     cout<<"value:"<< *v<<" ";
    // }
    // cout<<endl;
    // for(auto it = vec.begin();it != vec.end();it++)
    // {
    //     cout<<*it<<endl;
    // }
    
    // vector<int> vec2(vec);
    // for(auto it=vec2.begin();it != vec2.end();it++)
    // {
    //     cout<< *it <<endl;
    // }
    // //vec2.insert(vec2)

    // //删除 第i 个元素 返回下一个指针
    // auto it1 = vec.erase(vec.begin()+3);
    // cout<<*it1<<endl;
    
}
int MapOperation()
{
    map<int, string> ID_Name;
    ID_Name[2015] = "Tom";
    pair<int,string> temp(44,"alice");
    ID_Name.insert(temp);
    //遍历
    map<int,string>::iterator iter;
    for(iter=ID_Name.begin();iter != ID_Name.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    //查找
    iter = ID_Name.find(2016);
    if(iter == ID_Name.end())
    {
        cout<<"Not in"<<endl;
    }
    else
    {
        cout<<"in"<<endl;
    }

    //删除
    ID_Name.erase(44);
    for(iter=ID_Name.begin();iter != ID_Name.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    ID_Name.erase(ID_Name.begin(),ID_Name.end());
    cout<<"**********************"<<endl;
    for(iter=ID_Name.begin();iter != ID_Name.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }

}
int ListOperation()
{
    list<int> L;
    for(int i=0;i<10;i++)
    {
        L.push_back(i);
    }
    for(list<int>::iterator it= L.begin();it != L.end();it++)
    {
        cout<<*it<<" "<<endl;
    }
    L.push_back(7);
}
// 双端队列 deque
int DequeOperation()
{
    deque<int> q;
    for(int i=0;i<40;i++)
    {
        q.push_back(i);
        q.push_front(i);
        // q.pop_back(i);
        // q.pop_front(i);
    }
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    //q.clear();
    cout<<q.size();
}
bool mycompare(int a,int b)
{
    return a > b;
}
int SortOperation()
{
    int a[11] = {8,6,4,7,89,3,4,2,3,4,6};
    vector<int> vec (a,a+11);
    sort(vec.begin(),vec.end(),mycompare);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}
struct Student{
    int _id;
    string _name;
    Student(int id,string name)
    {
        _id = id;
        _name = name;
    }
};
bool struct_sort_function(Student A,Student B)
{
    return A._name <  B._name;
}
int StructSort()
{
    vector<Student> student_list;
    for(int i=0;i<55;i++)
    {
        student_list.push_back(Student(i,"student"+to_string(55-i)));
    }
    for(int i=0;i<student_list.size();i++)
    {
        cout<<student_list[i]._id <<"#"<< student_list[i]._name<<" ";
    }
    cout<<endl;
    //sort by _id 
    sort(student_list.begin(),student_list.end(),struct_sort_function);
    for(int i=0;i<student_list.size();i++)
    {
        cout<<student_list[i]._id <<"#"<< student_list[i]._name<<" ";
    }
    cout<<endl;
}
template<typename T>
void print_queue(T q) 
{ // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << '\n';
}
int priority_queue_operation()
{
    priority_queue<int> q;
    int data[10] = {1,8,5,6,3,4,0,9,7,2};
    for(int n:data)
    {
        q.push(n);
    }
    print_queue(q);
}
int two_dimention_array()
{
    vector<vector<int> > vec(5);
    for(int i=0;i<vec.size();i++)
    {
        vec[i].resize(3);
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[0].size();j++)
        {
            vec[i][j] = i*j;
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[0].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"hello world\n"<<endl;
    VectorOperator();
    //MapOperation();
    //ListOperation();
    //SortOperation();
    //StructSort();
    //priority_queue_operation();
    //two_dimention_array();
    return 0;
}
