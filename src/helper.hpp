#ifndef HELPER
#define HELPER

#include <godot_cpp/classes/engine.hpp>

//Runs only when the user is playing the game
#define RUNTIME_ONLY if ( Engine::get_singleton()->is_editor_hint()) return;

//Runs only in-editor
#define EDITOR_ONLY if ( Engine::get_singleton()->is_editor_hint() == false) return;

#endif