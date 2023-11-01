#ifndef CELL_DATA_H
#define CELL_DATA_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/vector3.hpp>


namespace godot {

class CellData : public Resource {
    GDCLASS(CellData, Resource)
    
    public:
        CellData();
        ~CellData();

        Vector3 world_pos;
        int size;

    
    protected:
        static void _bind_methods();
};

} // namespace godot

#endif