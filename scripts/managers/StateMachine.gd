extends RefCounted
class_name StateMachine

## This is a state machine implementation, very optimize w/ code organization on your side
# Created by Nonunknown

signal changed_state(from:int, to:int)

var _states_enter:Array[StringName]
var _states_update:Array[StringName]
var _states_exit:Array[StringName]

var _current_state:int = 0
var _machine_owner:Node = null

## Register all states that the machine contains
## for each state the user should create the following functions: _enter_name, _update_name, _exit_name
func register_states(target:Node, states:Dictionary,initial_state:int = 0) -> void:
	#Register the functions to be called in arrays of stringname (which is faster)
	for st in states:
		_states_enter.append(StringName("_enter_%s" % st))
		_states_update.append(StringName("_update_%s" % st))
		_states_exit.append(StringName("_exit_%s" % st))
		print("Registering State: ", st)
	
	_current_state = initial_state
	_machine_owner = target
	
	#Call the initial state
	target.call(_states_enter[_current_state])
	pass

## change the state to the target one
func change_state(to_state:int) -> void:
	changed_state.emit(_current_state, to_state)
	#call the old state's exit
	_machine_owner.call(_states_exit[_current_state])
	#update the current state to the targeted one
	_current_state = to_state
	#call the new state's enter method
	_machine_owner.call(_states_enter[to_state])
	pass

## update the machine, must be called in _process or _physics_process
func update(delta:float) -> void:
	_machine_owner.call(_states_update[_current_state],delta)
	pass

## return the integer of current state according to states dictionary
func get_current_state() -> int: return _current_state

## return the bolean to check the current state
func current_state_is(state:int) -> bool: return state == _current_state
