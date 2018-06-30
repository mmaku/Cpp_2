#pragma once

#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include <iostream>
#include <cstdlib>

namespace MYown
{

    template <typename T>
    class TsingleList;

    template <typename T>
    auto operator== (const TsingleList<T>& l1, const TsingleList<T>& l2) -> bool;

    template <typename T>
    auto operator<<( std::ostream& os, const TsingleList<T>& l ) -> std::ostream&;

    template<typename T>
    class TsingleList
    {
    private:

        struct TlistNode
        {
            T data_;
            TlistNode *next_;

            TlistNode(T const& data, TlistNode* next = nullptr)
                : data_(data), next_(next)
                {
                }

            TlistNode(T&& data, TlistNode* next = nullptr)
                : data_(std::move(data)), next_(next)
                {
                }
        };

        unsigned size_ = 0;
        TlistNode *begin_, *end_;

    public:

        auto push_back(T&& foo) -> void;
        auto push_back(const T& foo) -> void;
        auto push_front(T&& foo) -> void;
        auto push_front(const T& foo) -> void;
        TsingleList();
        ~TsingleList();
        auto size() const -> size_t;
        auto empty() const -> bool;
        TsingleList(const TsingleList& src);
//        TsingleList(TsingleList&& src); // jesli obiekty TlistNode są rvalue, to ta wersja nie jest poprawna
//        auto operator=(TsingleList&& src) -> TsingleList&; // jesli obiekty TlistNode są rvalue, to ta wersja nie jest poprawna

//        a moze wystarczy tylko:
        TsingleList(TsingleList&&) noexcept = default;

        TsingleList& operator=(TsingleList&&) noexcept = default;
//        ? (działa ok)

        auto operator=(TsingleList src) -> TsingleList&; // jesli obiekty TlistNode są rvalue, to ta wersja nie jest poprawna
        auto swap(TsingleList& src) noexcept -> void;
        friend auto operator== <T> (const TsingleList<T>& l1, const TsingleList<T>& l2) -> bool;
        friend auto operator<< <T> (std::ostream& os, const TsingleList<T>& l) -> std::ostream&;

        class iterator
            : public std::iterator<std::forward_iterator_tag, T>
        {
            private:
                TlistNode* current_;

            public:

                iterator(TlistNode* current)
                    : current_(current)
                {
                }

//                iterator() : current_(0)
//                {
//                }

                const iterator& operator++()
                {
                    current_ = current_->next_;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator tmp = *this;
                    current_ = current_->next_;
                    return tmp;
                }

                T& operator*()
                {
                    return current_->data_;
                }

                T& operator*() const
                {
                    return current_->data_;
                }

                T* operator->()
                {
                    return &(current_->data_);
                }

                T* operator->() const
                {
                    return &(current_->data_);
                }

                auto operator==(const iterator src) -> bool
                {
                    return current_ == src.current_;
                }

                auto operator!=(const iterator src) -> bool
                {
                    return current_ != src.current_;
                }

                auto erase() -> void
                {
                    current_->data_ = current_->next_->data_;
                    current_ = current_->next_;
                }
        };

        iterator begin()
        {
            return iterator(begin_);
        }

        iterator end()
        {
            return iterator(nullptr);
        }
    };

    template<typename T>
    void swap(TsingleList<T>& l1, TsingleList<T>& l2);

    template<typename T>
    bool operator==(const TsingleList<T>& l1, const TsingleList<T>& l2);

    template<typename T>
    bool operator!=(const TsingleList<T>& l1, const TsingleList<T>& l2);

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const TsingleList<T>& l);
}



#endif // LIST_HPP_INCLUDED
