#ifndef HPA_H
#define HPA_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/array.hpp>



#include "as_grid.h"
#include "online_search.hpp"
#include "helper.hpp"
#include "cell_data.h"
#include "request_manager.h"


namespace godot {


class RequestManager;

class HPA : public Node3D {
    GDCLASS(HPA, Node3D)
    
    
    private:
        int grid_size;
        int cell_radius;
        
        Ref<ASGrid> grid;
        Ref<OnlineSearch> online_search;
        RequestManager* request_manager;

        bool is_valid; //determines if this HPA node is valid or not!
        // TypedArray<Resource> test;

    public:
        HPA();
        ~HPA();

        void set_grid_size(const int p_grid_size);
        int get_grid_size() const;

        void set_cell_radius(const int p_cell_radius);
        int get_cell_radius() const;

        Vector3 get_cell_world_position(Vector2i index) const;

        void find_path(const Vector3 p_from, const Vector3 p_to, Node* p_caller);
        void search_path();
        void start();

        void iterate_grid_cells(Callable p_action);
        
    protected:
        static void _bind_methods();
};

} // namespace godot

#endif