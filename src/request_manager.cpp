#include "request_manager.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

RequestManager::RequestManager(HPA* hpa_owner) {
    queue = std::queue<PathRequest*>();
    this->hpa_owner = hpa_owner;
}

RequestManager::~RequestManager() {
    
}

void RequestManager::request_path(Vector3 p_path_start, Vector3 p_path_end, Node* p_caller) {
    PathRequest* pr = new PathRequest(p_path_start, p_path_end, p_caller);
    queue.push(pr);
    try_process_next();

}

void RequestManager::try_process_next() {
    if (is_processing) return;
    if (queue.front() == nullptr) return;
    current_path_request = queue.front();
    queue.pop();
    is_processing = true;
    hpa_owner->search_path();
   
}

void RequestManager::finished_processing(PackedVector3Array path, bool success) {
    bool has = false;
    if (current_path_request->caller->has_method("on_path_found")) {
        current_path_request->caller->call("on_path_found",path, success);
        has = true;
    }
    if (has == false) {
        UtilityFunctions::push_error("no on_path_found(path:PackedVector3Array, success:bool) method found in: ", current_path_request->caller->get_name(), "the code will be ignored!");
    }
    delete current_path_request;
    is_processing = false;
    try_process_next();

    

}