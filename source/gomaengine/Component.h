#pragma once
#include <iostream>


namespace gomaengine {


	class Component {
	public:

		Component get_parent_component();

		std::map<std::string, Component> get_children();
		virtual update(Component _component);

	private:
		std::string type_of_component;
		Component* parent;
		std::map<std::string, Component> children;



	};










};