#ifndef FLAGVARIABLE_CONFIGVARIABLE_H
#define FLAGVARIABLE_CONFIGVARIABLE_H

#include "FlagVariable.h"

enum ConfigFlag : uint16_t {
    NONE = 0b0,
    EXISTS = 0b10,
    MAX = 0b100,
    MIN = 0b1000,
    AUTO = 0b10000,
    DEFAULT = 0b100000,
};

template <class Var>
using ConfigVariable = FlagVariable<Var, uint16_t>;


typedef ConfigVariable<int> IntVar;

#endif //FLAGVARIABLE_CONFIGVARIABLE_H
