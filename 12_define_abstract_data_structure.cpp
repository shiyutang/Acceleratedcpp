//
// Created by Daisy on 2020/12/16.
//

#include <cstddef>
#include <memory>

using namespace std;

template<class T>
class Vec{
public:
    // interface
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    // 迭代器
    iterator begin() {return data;};
    const_iterator begin() const { return data;};
    iterator end() {return limit;};
    const_iterator end() const {return limit;};

    // 构造函数
    Vec() {create();};
    explicit Vec(size_type n, const T& val=T()) {create(n,val);};
    Vec(const Vec& v){create(v.begin(), v.end());}; // 复制构造函数
    ~Vec() {uncreate();};  // 析构函数

    size_type size() const {return limit - data; };

    // 重载的操作符：索引，赋值
    T& operator[] (size_type i) {return data[i];};  //重载索引运算符；写成函数并返回
    const T& operator[] (size_type i) const {return data[i];}; // 能重载是因为还隐式地传入了自身这个参数
    Vec& operator= (const Vec&);

    void push_back(const T& val)
    {
        if (avail==limit)
            grow();
        unchecked_append(val);
    }

private:
    // implement
    iterator data;
    iterator avail;
    iterator limit;

    allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec<T> & rhs)
{
    if (&rhs!= this)
    {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data+n;
    uninitialized_fill(data,limit,val);
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j-i);
    limit = avail = uninitialized_copy(i,j,data);
}

template<class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        iterator it = avail;
        while (it!=data)
            alloc.destroy(--it);
        alloc.deallocate(data,limit-data);
    }
    data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow()
{
    size_type new_size = max(2*(limit-data),std::ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data,avail,new_data);

    uncreate();
    data = new_data;
    avail = new_avail;
    limit = data+new_size;
}

template<class T>
void  Vec<T>::unchecked_append(const T & val)
{
    alloc.construct(avail++, val);
}
