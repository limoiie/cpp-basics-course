#ifndef C___BASICS_COURSE_UTILS_RANDOMS_H_
#define C___BASICS_COURSE_UTILS_RANDOMS_H_

#include <random>


template<typename T>
std::function<T()>
rand_dist(int limit) {
    static std::random_device r;
    static std::default_random_engine e(r());
    auto dist = std::make_shared<std::uniform_int_distribution<T>>(0, limit-1);
    return [dist]() {
        return dist->operator()(e);
    };
}


int rand_int(int const limit) {
    return rand_dist<int>(limit)();
}


#endif //C___BASICS_COURSE_UTILS_RANDOMS_H_
