#include "list.hpp"

namespace MYown
{
    template<typename T>
    auto TsingleList<T>::push_back(T&& foo) -> void
    {
        TlistNode *newEnd = new TlistNode(foo);

        if (this->empty())
        {
            begin_ = newEnd;
        }
        else
        {
            end_->next_ = newEnd;
        }

        end_ = newEnd;
        ++size_;
    }

    template<typename T>
    auto TsingleList<T>::push_back(const T& foo) -> void
    {
        push_back(T(foo));
    }

    template<typename T>
    auto TsingleList<T>::push_front(T&& foo) -> void
    {
        TlistNode *newBegin = new TlistNode(foo, begin_);

        if (this->empty())
        {
            begin_ = newBegin;
            end_ = newBegin;
        }
        else
        {
            begin_ = newBegin;
        }
        ++size_;
    }

    template<typename T>
    auto TsingleList<T>::push_front(const T& foo) -> void
    {
        push_front(T(foo));
    }

    template<typename T>
    TsingleList<T>::TsingleList()
        : size_(0), begin_(nullptr), end_(nullptr)
    {
    }

    template<typename T>
    TsingleList<T>::~TsingleList()
    {
        TlistNode *tmp;

        while(begin_)
        {
            tmp = begin_->next_;
            delete begin_;
            begin_ = tmp;
        }
    }

    template<typename T>
    auto TsingleList<T>::size() const -> size_t
    {
        return size_;
    }

    template<typename T>
    auto TsingleList<T>::empty() const -> bool
    {
        return begin_ == nullptr;
    }

    template<typename T>
    TsingleList<T>::TsingleList(const TsingleList& src)
        : size_(0), begin_(nullptr), end_(nullptr)
    {
        TlistNode *tmp = src.begin_;
        while (tmp != nullptr)
        {
            this->push_back(tmp->data_);
            tmp = tmp->next_;
        }


    }
//
//    template<typename T>
//    TsingleList<T>::TsingleList(TsingleList&& src) // jesli obiekty TlistNode są rvalue, to ta wersja nie jest poprawna
//        : size_(src.size_), begin_(src.begin_), end_(src.end_)
//    {
//        src.begin_ = nullptr;
//        src.end_ = nullptr;
//        src.size_ = 0;
//    }
//
//    template<typename T>
//    auto TsingleList<T>::operator=(TsingleList&& src) -> TsingleList& // jesli obiekty TlistNode są rvalue, to ta wersja nie jest poprawna
//    {
//        if(this.begin_ != &src.begin_)
//        {
//            TlistNode *tmp;
//
//            while(begin_)
//            {
//                tmp = begin_->next_;
//                delete[] begin_;
//                begin_ = tmp;
//            }
//
//            size_ = src.size();
//            begin_ = src.begin_;
//            end_ = src.end_;
//
//            src.begin_ = nullptr;
//            src.end_ = nullptr;
//            src.size_ = 0;
//        }
//        return *this;
//    }

    template<typename T>
    auto TsingleList<T>::operator=(TsingleList src) -> TsingleList&
    {
        TsingleList tmp(src);
        swap(tmp);
        return *this;
    }

    template<typename T>
    auto TsingleList<T>::swap(TsingleList& src) noexcept -> void
    {
        std::swap(size_, src.size_);
        std::swap(begin_, src.begin_);
        std::swap(end_, src.end_);
    }



    template<typename T>
    void swap(TsingleList<T>& l1, TsingleList<T>& l2)
    {
        l1.swap(l2);
    }

    template<typename T>
    bool operator==(const TsingleList<T>& l1, const TsingleList<T>& l2)
    {
        bool foo = true;
        if(l1.begin_ == l2.begin_)
        {
        }

        else if(l1.size() != l2.size())
        {
            foo = false;
        }

        else
        {
            typename TsingleList<T>::TlistNode *tmp1, *tmp2;

            tmp1 = l1.begin_;
            tmp2 = l2.begin_;
            while(tmp1 && tmp2 && foo)
            {
                foo &= (tmp1->data_ == tmp2->data_);
                tmp1 = tmp1->next_;
                tmp2 = tmp2->next_;
            }
        }
        return foo;
    }

    template<typename T>
    bool operator!=(const TsingleList<T>& l1, const TsingleList<T>& l2)
    {
        return !(l1 == l2);
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const TsingleList<T>& l)
    {
        typename TsingleList<T>::TlistNode *tmp;

        if(!l.begin_)
            os << "Lista jest pusta.";
        else
        {
            tmp = l.begin_;
            while(tmp)
            {
                os << tmp->data_;
                tmp = tmp->next_;
                if(tmp)
                    os << ',';
            }

        }
        return os;
    }
}
