extends Panel
class_name PanelMode

static var instance:PanelMode = null
var state_machine := StateMachine.new()
@onready var unit_move: Panel = $"../UnitMove"

signal changed_to_unit
signal changed_to_edit
signal changed_state(from:int, to:int)

enum STATES {unit,edit}

func _init() -> void:
	if instance != null:
		push_error("you have more than 2 instances of PanelMode")
		return
	instance = self
	state_machine.register_states(self, STATES, STATES.unit)
	pass

func _ready() -> void:
	#set the unit mode as default moded
	$VBoxContainer/bt_unit.set_pressed(true)
	unit_move.get_node("VBoxContainer/bt_gray").set_pressed(true)
	

func is_unit_mode() -> bool: return state_machine.current_state_is(STATES.unit)
func is_edit_mode() -> bool: return state_machine.current_state_is(STATES.edit)


func _enter_unit() -> void:
	changed_to_unit.emit()
	pass

func _update_unit(delta:float) -> void:
	pass

func _exit_unit() -> void:
	pass

func _enter_edit() -> void:
	changed_to_edit.emit()
	pass

func _update_edit(delta:float) -> void:
	pass

func _exit_edit() -> void:
	pass


func _on_bt_place_toggled(toggled_on: bool) -> void:
	if not toggled_on: return
	state_machine.change_state(STATES.edit)
	
	

func _on_bt_unit_toggled(toggled_on: bool) -> void:
	unit_move.visible = toggled_on
	if not toggled_on: return
	
	state_machine.change_state(STATES.unit)

