#ifndef REQUEST_MANAGER_H
#define REQUEST_MANAGER_H


#include <queue>
#include "hpa.h"

namespace godot {

struct PathRequest {
    Vector3 path_start;
    Vector3 path_end;
    Node* caller;

    PathRequest(Vector3 p_path_start, Vector3 p_path_end, Node* p_caller) {
        path_start = p_path_start;
        path_end = p_path_end;
        caller = p_caller;
    }

    PathRequest(){};

};

class HPA;

class RequestManager {
    
    private:
        std::queue<PathRequest*> queue;
        HPA* hpa_owner;
        bool is_processing;


    public:
        RequestManager(HPA* hpa_owner);
        ~RequestManager();

        PathRequest* current_path_request;

        void request_path(Vector3 p_path_start, Vector3 p_path_end, Node* p_caller);
        void try_process_next();
        void finished_processing(PackedVector3Array path, bool success);
        
    
};

} // namespace godot

#endif