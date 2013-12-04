#include <iostream>

#include <vector>

using namespace std;
class checkAge:public exception{};
template <class T>
class SharedPointer
{
private:
    T* ptr;
    int* count;
    
        

public:
    SharedPointer():ptr(0), count(new int (0)){}
    explicit SharedPointer(T* p=0): ptr(p), count(new int (1)) {}
    SharedPointer(const SharedPointer<T>& p) throw(): ptr(p.ptr), count(p.count){++*count;}
    ~SharedPointer()
    {
        if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
    }
    T& operator*(){return *ptr;}
    T* operator->(){return ptr;}
    SharedPointer<T>& operator= (const SharedPointer<T>& p) throw()
    {
        if(this!=&p)
        {
            if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
            ptr=p.ptr;
            count=p.count;
            ++*count;
        }
        return *this;
    }
};

class People
{
    int age1,age2;
public:
    People(int a,int b):age1(a),age2(b){}
    void show_diff()
    {
        if(((age1>18)&&(age1<30))&&((age2>18)&&(age2<30)))
    {
        cout<<"oba molodie"<<endl;
    }
    else
    {
        if(age2>age1)
        {
            cout<<"pervii mologe"<<endl;
        }
        else
            cout<<"vtoroi mologe"<<endl;

    }
    }
};





int main()
{
    int a,b;
    cout<<"vvedi age1,age2"<<endl;
    cin>>a>>b;
      if(a<1||b<1||a>150||b>150)
        throw checkAge();
    SharedPointer<People> Men (new People(a,b));


    vector <People> men;
    men.push_back(*Men);
        vector<People>::iterator cur;
    for (cur=men.begin(); cur<men.end(); cur++)
        cur->show_diff();
    system("pause");
}
