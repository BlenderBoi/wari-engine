extends EditorInspectorPlugin
class_name HPAInspector

func _can_handle(object: Object) -> bool:
	if (object is HPA):
		return true
	return false

func _parse_property(object: Object, type: Variant.Type, name: String, hint_type: PropertyHint, hint_string: String, usage_flags: int, wide: bool) -> bool:
	#print(name)
	return false

var ui_inspector = preload("res://addons/wari_hpa/ui/ui_inspector.tscn")
var ui:Control = null
func _parse_begin(object: Object) -> void:
	print("start parse")
	if ui == null:
		ui = ui_inspector.instantiate()
		add_custom_control(ui)
		print(ui.name)
