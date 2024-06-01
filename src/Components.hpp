#ifndef LZX_COMPONENTS_HPP
#define LZX_COMPONENTS_HPP

#include <rack.hpp>
using namespace rack;

#include "plugin.hpp"

struct Lzx_Knob_Filled : RoundKnob {

	Lzx_Knob_Filled() {
		this->SvgKnob::setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/LZX_KNOB_FILLED.svg")));
	}
};

struct Lzx_Knob_Outline : RoundKnob {

	Lzx_Knob_Outline() {
		this->SvgKnob::setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/LZX_KNOB_OUTLINE.svg")));
	}
};

struct Lzx_Switch_2 : app::SvgSwitch {
	Lzx_Switch_2() {
		shadow->opacity = 0.0;
		addFrame(Svg::load(asset::plugin(pluginInstance, "res/LZX_SWITCH_DOWN_BLK.svg")));
		addFrame(Svg::load(asset::plugin(pluginInstance, "res/LZX_SWITCH_UP_BLK.svg")));
	}
};

struct Lzx_Switch_3 : app::SvgSwitch {
	Lzx_Switch_3() {
		shadow->opacity = 0.0;
		addFrame(Svg::load(asset::plugin(pluginInstance, "res/LZX_SWITCH_DOWN_BLK.svg")));
		addFrame(Svg::load(asset::plugin(pluginInstance, "res/LZX_SWITCH_MID_BLK.svg")));
		addFrame(Svg::load(asset::plugin(pluginInstance, "res/LZX_SWITCH_UP_BLK.svg")));
	}
};
#endif // !LZX_COMPONENTS_HPP
