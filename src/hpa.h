#ifndef HPA_H
#define HPA_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/array.hpp>



#include "as_grid.h"
#include "online_search.hpp"
#include "helper.hpp"
#include "cell_data.h"

namespace godot {



class HPA : public Node3D {
    GDCLASS(HPA, Node3D)
    
    private:
        int grid_size;
        int cell_radius;
        
        ASGrid grid;
        // TypedArray<Resource> test;

    public:
        HPA();
        ~HPA();

        void set_grid_size(const int p_grid_size);
        int get_grid_size() const;

        void set_cell_radius(const int p_cell_radius);
        int get_cell_radius() const;

        void start();

        TypedArray<CellData> debug_get_cells();

    protected:
        static void _bind_methods();
};

} // namespace godot

#endif