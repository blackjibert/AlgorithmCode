#include <iostream>
#include <queue>
using namespace std;

class Base3DObject
{
public:
    ~Base3DObject();//1
    Base3DObject();// 2
    Base3DObject(const Base3DObject& other); // 3
    Base3DObject(Base3DObject&& other) noexcept; // 4
    Base3DObject(unsigned short* bufer, unsigned int buffer_len, const string& name); //5
    const Base3DObject& operator=(const Base3DObject& other);// 6
    const Base3DObject& operator=(Base3DObject&& other) noexcept; // 7
protected:
    virtual void Copy(const Base3DObject& other)final; // 8
    virtual void Move(Base3DObject&& other) final;  //9
private:
    unsigned short* buffer_;
    unsigned int buffer_len_;
    string name_;
};


// 构造函数
Base3DObject::Base3DObject() : buffer_(nullptr), buffer_len_(0), name_("") {}

// 析构函数
Base3DObject::~Base3DObject() {
    delete[] buffer_; // 释放缓冲区
}

// 复制构造函数
Base3DObject::Base3DObject(const Base3DObject& other): buffer_(nullptr), buffer_len_(other.buffer_len_), name_(other.name_) {
    Copy(other);
}

// 移动构造函数
Base3DObject::Base3DObject(Base3DObject&& other) noexcept
    : buffer_(other.buffer_), buffer_len_(other.buffer_len_), name_(move(other.name_)) {
    other.buffer_ = nullptr;
    other.buffer_len_ = 0;
}

// 带参数的构造函数
Base3DObject::Base3DObject(unsigned short* buffer, unsigned int buffer_len, const std::string& name)
    : buffer_(buffer), buffer_len_(buffer_len), name_(name) {}

// 复制赋值运算符
const Base3DObject& Base3DObject::operator=(const Base3DObject& other) {
    if (this != &other) {
        // 释放现有资源
        delete[] buffer_;
        // 从其他对象复制数据
        buffer_len_ = other.buffer_len_;
        name_ = other.name_;
        Copy(other);
    }
    return* this;
}

// 移动赋值运算符
const Base3DObject& Base3DObject::operator=(Base3DObject&& other) noexcept {
    if (this != &other) {
        // 释放现有资源
        delete[] buffer_;
        // 从其他对象移动数据
        buffer_ = other.buffer_;
        buffer_len_ = other.buffer_len_;
        name_ = std::move(other.name_);
        // 重置其他对象
        other.buffer_ = nullptr;
        other.buffer_len_ = 0;
    }
    return *this;
}

// 保护函数 - 复制
void Base3DObject::Copy(const Base3DObject& other) {
    // 如果缓冲区存在，则复制缓冲区
    if (other.buffer_ != nullptr) {
        buffer_ = new unsigned short[other.buffer_len_];
        copy(other.buffer_, other.buffer_ + other.buffer_len_, buffer_);
    }
}

// 保护函数 - 移动
void Base3DObject::Move(Base3DObject&& other) {
    // 如果缓冲区存在，则移动缓冲区
    buffer_ = other.buffer_;
    buffer_len_ = other.buffer_len_;
    // 重置其他对象
    other.buffer_ = nullptr;
    other.buffer_len_ = 0;
}
