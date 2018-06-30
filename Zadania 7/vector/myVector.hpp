#ifndef MYVector_HPP_INCLUDED
#define MYVector_HPP_INCLUDED

#include <algorithm>
#include <cassert>
#include <memory>

namespace MYown
{

    template<typename T>
    class Vector
    {
        private:
            std::unique_ptr<T[]> ptr_;
            int size_;

        public:

//            explicit Vector<T>(int n=0)
//                : (n ? ptr_(new T[n]) : ptr_(nullptr)), size_(n)
//            {
//            }

            explicit Vector(int n=0)  // działa tez Vector<T>?
                : ptr_(nullptr), size_(n)
            {
                if (n)
                    ptr_.reset(new T[n]);
            }

            Vector(const Vector& v)
                : ptr_(nullptr), size_(0)
            {
                if (v.size())
                {
                    ptr_.reset(new T[v.size()]);
                    size_ = v.size_;
                    std::copy_n(v.ptr_.get(),v.size_, ptr_.get());
                }
            }

            Vector& operator=(const Vector& v)
            {
                Vector k(v);
                swap(k);
                return *this;
            }

            Vector(Vector&&) noexcept = default;

            Vector& operator=(Vector&&) noexcept = default;

            // destruktor wystarczy, gdyz usuwajac Vector "unique_ptr" zadba o siebie

            int size() const
            {
                return size_;
            }

            bool empty() const
            {
                return !size_;
            }

            void swap(Vector& v) noexcept
            {
                std::swap(ptr_, v.ptr_);
                std::swap(size_, v.size_);
            }

            const T& operator[](int i) const
            {
                return ptr_[i];
            }

            T& operator[](int i)
            {
                return ptr_[i];
            }

            void push_back(T&& a)
            {
                std::unique_ptr<T[]> temp(new T[size_ + 1]);
                std::move(ptr_.get(), ptr_.get() + size_, temp.get());
                temp[size_++] = std::move(a);
                ptr_ = std::move(temp);
            }

            void push_back(const T& a)
            {
                push_back(T(a));
            }

            T& back()
            {
                return ptr_[size_-1];
            }

            const T& back() const
            {
                return ptr_[size_-1];
            }

            void pop_back()
            {
                std::unique_ptr<T[]> temp(new T[--size_]);
                std::move(ptr_.get(), ptr_.get() + size_, temp.get());
                ptr_ = std::move(temp);
            }

            void push_front(T&& a)
            {
                std::unique_ptr<T[]> temp(new T[size_ + 1]);
                std::move(ptr_.get(), ptr_.get() + (size_++), temp.get() + 1);
                temp[0] = std::move(a);
                ptr_ = std::move(temp);
            }

            void push_front(const T& a)
            {
                push_front(T(a)); // ?

//                std::unique_ptr<T[]> temp(new T[size_ + 1]);
//                std::move(ptr_.get(), ptr_.get() + size_, temp.get() + 1);
//                temp[0] = a;
//                +size_;
//                ptr_ = std::move(temp);
            }

            T& front()
            {
                return ptr_[0];
            }

            const T& front() const
            {
                return ptr_[0];
            }

            void pop_front()
            {
                --size_;
                std::unique_ptr<T[]> temp(new T[size_]);
                std::move(ptr_.get() + 1, ptr_.get() + size_ + 1, temp.get());
                ptr_ = std::move(temp);
            }
    };

    template<typename T>
    void swap(Vector<T>& v1, Vector<T>& v2)
    {
        v1.swap(v2);
    }



}


#endif // MYVector_HPP_INCLUDED
