#include "plugin.hpp"
#include "Components.hpp"

struct FKG3 : Module {
	enum ParamId {
		SWITCH_INVERT_PARAM,
		KNOB_THRESH_PARAM,
		KNOB_SOFT_PARAM,
		KNOB_SOURCE_PARAM,
		KNOB_THRESH_CV_PARAM,
		KNOB_SOFT_CV_PARAM,
		KNOB_MODE_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_THRESH_INPUT,
		IN_SOFT_INPUT,
		IN_BG_RED_INPUT,
		IN_FG_RED_INPUT,
		IN_KEY_RED_INPUT,
		IN_BG_GREEN_INPUT,
		IN_FG_GREEN_INPUT,
		IN_KEY_GREEN_INPUT,
		IN_BG_BLUE_INPUT,
		IN_FG_BLUE_INPUT,
		IN_KEY_BLUE_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUT_1_OUTPUT,
		OUT_2_OUTPUT,
		OUT_3_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	FKG3() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configSwitch(SWITCH_INVERT_PARAM, 0.f, 2.f, 1.f, "");
		configParam(KNOB_THRESH_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_SOFT_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_SOURCE_PARAM, 0.f, 1.f, 0.f, "");
		configParam(KNOB_THRESH_CV_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_SOFT_CV_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_MODE_PARAM, 0.f, 1.f, 0.f, "");
		configInput(IN_THRESH_INPUT, "");
		configInput(IN_SOFT_INPUT, "");
		configInput(IN_BG_RED_INPUT, "");
		configInput(IN_FG_RED_INPUT, "");
		configInput(IN_KEY_RED_INPUT, "");
		configInput(IN_BG_GREEN_INPUT, "");
		configInput(IN_FG_GREEN_INPUT, "");
		configInput(IN_KEY_GREEN_INPUT, "");
		configInput(IN_BG_BLUE_INPUT, "");
		configInput(IN_FG_BLUE_INPUT, "");
		configInput(IN_KEY_BLUE_INPUT, "");
		configOutput(OUT_1_OUTPUT, "");
		configOutput(OUT_2_OUTPUT, "");
		configOutput(OUT_3_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct FKG3Widget : ModuleWidget {
	FKG3Widget(FKG3* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/FKG3.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(10.16, 16.602)), module, FKG3::SWITCH_INVERT_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 16.624)), module, FKG3::KNOB_THRESH_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(50.8, 16.624)), module, FKG3::KNOB_SOFT_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 42.024)), module, FKG3::KNOB_SOURCE_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(30.48, 42.024)), module, FKG3::KNOB_THRESH_CV_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(50.8, 42.024)), module, FKG3::KNOB_SOFT_CV_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 67.424)), module, FKG3::KNOB_MODE_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(30.48, 67.424)), module, FKG3::IN_THRESH_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(50.8, 67.424)), module, FKG3::IN_SOFT_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, FKG3::IN_BG_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 86.474)), module, FKG3::IN_FG_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 86.474)), module, FKG3::IN_KEY_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, FKG3::IN_BG_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 99.174)), module, FKG3::IN_FG_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 99.174)), module, FKG3::IN_KEY_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, FKG3::IN_BG_BLUE_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 111.874)), module, FKG3::IN_FG_BLUE_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 111.874)), module, FKG3::IN_KEY_BLUE_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 86.474)), module, FKG3::OUT_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 99.174)), module, FKG3::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 111.874)), module, FKG3::OUT_3_OUTPUT));
	}
};


Model* modelFKG3 = createModel<FKG3, FKG3Widget>("FKG3");