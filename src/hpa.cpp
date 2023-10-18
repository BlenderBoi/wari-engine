#include "hpa.h"

using namespace godot;

HPA::HPA() {
    
}

HPA::~HPA() {
    
}

void HPA::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_"), &HPA::get_);
    ClassDB::bind_method(D_METHOD("set_", ""), &HPA::set_);
    ClassDB::add_property("HPA", PropertyInfo(Variant::Resource, ""), "set_", "get_");
}

void HPA::set_test(const TypedArray<Resource> p_test) {
    test = p_test;
}

TypedArray<Resource> HPA::get_test() const {
    return test;
}