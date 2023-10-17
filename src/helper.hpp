#ifndef HELPER
#define HELPER

#include <godot_cpp/classes/engine.hpp>

#define RUNTIME_ONLY if ( Engine::get_singleton()->is_editor_hint()) return;
#define EDITOR_ONLY if ( Engine::get_singleton()->is_editor_hint() == false) return;

#endif