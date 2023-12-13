#include "pound.h"

string Pound::toString() {
    return "GBP " + to_string(getSuper()) + "." +to_string(getSub());
}

