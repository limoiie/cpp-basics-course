#ifndef C___BASICS_COURSE_UTILS_POINTER_H_
#define C___BASICS_COURSE_UTILS_POINTER_H_

template <typename T>
inline
long long int to_long(T * p) {
    return reinterpret_cast<long long int>(
            static_cast<void *>(p));
}

#endif //C___BASICS_COURSE_UTILS_POINTER_H_
