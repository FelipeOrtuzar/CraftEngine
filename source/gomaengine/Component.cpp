#include "Component.h"




namespace gomaengine {
	Component Component::get_parent_component()
	{
		return Component();
	}


	std::map<std::string, Component> Component::get_children()
	{
		return std::map<std::string, Component>();
	}


	Component::update(Component _component)
	{
		for (auto const& ent : children) {
			ent.update
		}
	}
};