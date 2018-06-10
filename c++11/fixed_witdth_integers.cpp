#include <cstdint>

int main(int argc, char** argv)
{
    // C++11 officially introduces fixed width integers. Fixed width integers, however
    // may not be supportted on all architectures, or they may be slower than than the
    // built in types. To remedy this, fast and least integer types were introduced.
    // They all reside in <cstdint> header.

    // The fast type (int_fast#_t) gives you an integer that’s the fastest type with a
    // width of at least # bits (where # = 8, 16, 32, or 64). For example, int_fast32_t
    // will give you the fastest integer type that’s at least 32 bits. If you need a
    // variable guaranteed to be a particular size and want to favor performance, use
    // int_fast#_t.

    // The least type (int_least#_t) gives you the smallest integer type with a width of
    // at least # bits (where # = 8, 16, 32, or 64). For example, int_least32_t will give
    // you the smallest integer type that’s at least 32 bits. If you need a variable
    // guaranteed to be a particular size and want to favor memory conservation over
    // performance, use int_least#_t. This is used most often when allocating lots of
    // variables.

    // Signed integer type with width of exactly 8, 16, 32 and 64 bits respectively
    // with no padding bits and using 2's complement for negative values
    // (provided only if the implementation directly supports the type) .
    int8_t int8;
    int16_t int16;
    int32_t int32;
    int64_t int64;

    // Fastest signed integer type with width of at least 8, 16, 32 and 64 bits
    // respectively
    int_fast8_t fastInt8;
    int_fast16_t fastInt16;
    int_fast32_t fastInt32;
    int_fast64_t fastInt64;

    // smallest signed integer type with width of at least 8, 16, 32 and 64 bits
    // respectively
    int_least8_t leastInt8;
    int_least16_t leastInt16;
    int_least32_t leastInt32;
    int_least64_t leastInt64;

    // maximum width integer type
    intmax_t maxWidthInt;

    // signed integer type capable of holding a pointer. Can be used to either obfuscate
    // use of a pointer, or to perform pointer arithmetic operations.
    intptr_t intPtr;

    // unsigned integer type with width of exactly 8, 16, 32 and 64 bits respectively
    // (provided only if the implementation directly supports the type)
    uint8_t uint8;
    uint16_t uint16;
    uint32_t uint32;
    uint64_t uint64;

    // fastest unsigned integer type with width of at least 8, 16, 32 and 64 bits
    // respectively
    uint_fast8_t fastUInt8;
    uint_fast16_t fastUInt16;
    uint_fast32_t fastUInt32;
    uint_fast64_t fastUInt64;

    // smallest unsigned integer type with width of at least 8, 16, 32 and 64 bits
    // respectively
    uint_least8_t leastUInt8;
    uint_least16_t leastUInt16;
    uint_least32_t leastUInt32;
    uint_least64_t leastUInt64;

    // maximum width unsigned integer type
    uintmax_t maxWidthUInt;

    // Along with the new integer types, their corresponsing min and max values
    // have been introduced through macro constants.

    int8_t int8MinValue = INT8_MIN;
    int8_t int8MaxValue = INT8_MAX;

    int16_t int16MinValue = INT16_MIN;
    int16_t int16MaxValue = INT16_MAX;

    int32_t int32MinValue = INT32_MIN;
    int32_t int32MaxValue = INT32_MAX;

    int64_t int64MinValue = INT64_MIN;
    int64_t int64MaxValue = INT64_MAX;

    int_fast8_t fastInt8MinValue = INT_FAST8_MIN;
    int_fast8_t fastInt8MaxValue = INT_FAST8_MAX;

    int_fast16_t fastInt16MinValue = INT_FAST16_MIN;
    int_fast16_t fastInt16MaxValue = INT_FAST16_MAX;

    int_fast32_t fastInt32MinValue = INT_FAST32_MIN;
    int_fast32_t fastInt32MaxValue = INT_FAST32_MAX;

    int_fast64_t fastInt64MinValue = INT_FAST64_MIN;
    int_fast64_t fastInt64MaxValue = INT_FAST64_MAX;

    int_least8_t leastInt8MinValue = INT_LEAST8_MIN;
    int_least8_t leastInt8MaxValue = INT_LEAST8_MAX;

    int_least16_t leastInt16MinValue = INT_LEAST16_MIN;
    int_least16_t leastInt16MaxValue = INT_LEAST16_MAX;

    int_least32_t leastInt32MinValue = INT_LEAST32_MIN;
    int_least32_t leastInt32MaxValue = INT_LEAST32_MAX;

    int_least64_t leastInt64MinValue = INT_LEAST64_MIN;
    int_least64_t leastInt64MaxValue = INT_LEAST64_MAX;

    intmax_t maxWidthIntMinValue = INTMAX_MIN;
    intmax_t maxWidthIntMaxValue = INTMAX_MAX;

    intptr_t intPtrMin = INTPTR_MIN;
    intptr_t intPtrMax = INTPTR_MAX;
}