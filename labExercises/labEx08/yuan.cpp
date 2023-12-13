#include "yuan.h"

string Yuan::toString() {
    return "CYN " + to_string(getSuper()) + "." + to_string(getSub());
}
