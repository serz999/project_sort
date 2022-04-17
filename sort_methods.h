#pragma once

template<typename T>
void SWAP(T &first, T &second) {
    T TEMP = first;
    first = second;
    second = TEMP;
}

template <class Iterator>
Iterator advance_and_return(Iterator now_Iterator, size_t pos){
    std::advance(now_Iterator,pos);
    return now_Iterator;
}

template <class Iterator>
Iterator my_in_place_merge(Iterator begin, size_t middle, Iterator end) {
    std::vector<Iterator> TEMP;
    TEMP.resize(std::distance(begin, end));
    int left_index = 0;
    int right_index = middle;
    int i = 0;
    while ((left_index < middle) || (right_index < std::distance(begin, end))) {
        if (left_index == middle) {
            for (size_t j = right_index; j < std::distance(begin, end); j++) {
                TEMP[i++] = advance_and_return(begin, j);
            }
            break;
        }
        if (right_index == std::distance(begin, end)) {
            for (size_t j = left_index; j < middle; j++) {
                TEMP[i++] = advance_and_return(begin, j);
            }
            break;
        }
        if (*(advance_and_return(begin, left_index)) < *(advance_and_return(begin, right_index))) {
            TEMP[i++] = (advance_and_return(begin, left_index++));
        } else {
            TEMP[i++] = (advance_and_return(begin, right_index++));
        }
    }
    std::vector<typeof(*begin)> SECOND_TEMP;
    SECOND_TEMP.resize(std::distance(begin, end));
    for (int j = 0; j < std::distance(begin, end); ++j) {
        SECOND_TEMP[j] = *TEMP[j];
    }
    for (int j = 0; j < std::distance(begin, end); ++j) {
        *(advance_and_return(begin, j)) = SECOND_TEMP[j];
    }
}

template<class Iterator>
Iterator my_partition(Iterator begin, Iterator end) {
    begin--;
    end--;
    Iterator step_ = begin;
    Iterator step__ = ++begin;
    while(step__ != end) {
        if (*step__ <= *end) {
            step_++;
            SWAP(*step_, *step__);
        }
        step__++;
    }
    step_++;
    SWAP(*step_, *step__);
    return step_;
}

template <class Iterator>
void bubble_sort(Iterator begin, Iterator end) {
    for (Iterator i = begin; i != end; i++) {
        for (Iterator j = begin; j != i; j++) {
            if (*i < *j) {
                SWAP(*i, *j);
            }
        }
    }
}

template <class Iterator>
void insert_sort(Iterator begin, Iterator end) {
    size_t size = std::distance(begin, end);
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; (j >= 0) || (*(advance_and_return(begin,j)) < *(advance_and_return(begin,j + 1))); j--) {
            if (*(advance_and_return(begin,j)) > *(advance_and_return(begin, j + 1))) {
                SWAP(*(advance_and_return(begin,j)), *(advance_and_return(begin,j + 1)));
            }
        }
    }
}

template <class Iterator>
void merge_sort(Iterator begin, Iterator end) {
    if (std::distance(begin, end) > 1) {
        size_t middle = std::distance(begin, end) / 2;
        merge_sort(begin, advance_and_return(begin, middle));
        merge_sort(advance_and_return(begin, middle), end);
        my_in_place_merge(begin, middle, end);
    } else {
        return;
    }
}

template<class Iterator>
void quick_sort(Iterator begin, Iterator end) {
    if (std::distance(begin, end) > 1) {
        Iterator wall = my_partition(begin, end);
        quick_sort(begin, wall);
        quick_sort(++wall, end);
    } else {
        return;
    }
}