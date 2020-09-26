#pragma once

#include <cstddef>

namespace Physics{

struct Size{
    size_t rows, columns;

    Size();
    Size(size_t rows, size_t columns);

    friend bool operator==(Size &left, Size &right);
};

}