#ifndef HPA_H
#define HPA_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/array.hpp>

namespace godot {



class HPA : public Node3D {
    GDCLASS(HPA, Node3D)
    
    private:
        TypedArray<Resource> test;

    public:
        HPA();
        ~HPA();

        void set_test(const TypedArray<Resource> p_test);
        TypedArray<Resource> get_test() const;

        
    protected:
        static void _bind_methods();
};

} // namespace godot

#endif