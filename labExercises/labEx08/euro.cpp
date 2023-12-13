#include "euro.h"

string Euro::toString() {
    return "EUR " + to_string(getSuper()) + "." +to_string(getSub());
}
