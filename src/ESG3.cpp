#include "plugin.hpp"
#include "Components.hpp"

struct ESG3 : Module {
	enum ParamId {
		KNOB_CONT_RED_PARAM,
		KNOB_CONT_GREEN_PARAM,
		KNOB_CONT_BLUE_PARAM,
		KNOB_BRIGHT_RED_PARAM,
		KNOB_BRIGHT_GREEN_PARAM,
		KNOB_BRIGHT_BLUE_PARAM,
		SWITCH_LUMA_PARAM,
		SWITCH_RED_PARAM,
		SWITCH_GREEN_PARAM,
		SWITCH_BLUE_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_RED_INPUT,
		IN_GREEN_INPUT,
		IN_BLUE_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUT_LUMA_OUTPUT,
		OUT_GREEN_OUTPUT,
		OUT_BLUE_OUTPUT,
		OUT_RED_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	ESG3() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(KNOB_CONT_RED_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_CONT_GREEN_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_CONT_BLUE_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_BRIGHT_RED_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_BRIGHT_GREEN_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_BRIGHT_BLUE_PARAM, 0.f, 1.f, 0.5f, "");
		configSwitch(SWITCH_LUMA_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SWITCH_RED_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SWITCH_GREEN_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SWITCH_BLUE_PARAM, 0.f, 2.f, 1.f, "");
		configInput(IN_RED_INPUT, "");
		configInput(IN_GREEN_INPUT, "");
		configInput(IN_BLUE_INPUT, "");
		configOutput(OUT_LUMA_OUTPUT, "");
		configOutput(OUT_GREEN_OUTPUT, "");
		configOutput(OUT_BLUE_OUTPUT, "");
		configOutput(OUT_RED_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct ESG3Widget : ModuleWidget {
	ESG3Widget(ESG3* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/ESG3.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 16.624)), module, ESG3::KNOB_CONT_RED_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(30.48, 16.624)), module, ESG3::KNOB_CONT_GREEN_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(50.8, 16.624)), module, ESG3::KNOB_CONT_BLUE_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 42.024)), module, ESG3::KNOB_BRIGHT_RED_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 42.024)), module, ESG3::KNOB_BRIGHT_GREEN_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(50.8, 42.024)), module, ESG3::KNOB_BRIGHT_BLUE_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(7.62, 67.402)), module, ESG3::SWITCH_LUMA_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(22.86, 67.402)), module, ESG3::SWITCH_RED_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(38.1, 67.402)), module, ESG3::SWITCH_GREEN_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(53.34, 67.402)), module, ESG3::SWITCH_BLUE_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, ESG3::IN_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, ESG3::IN_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, ESG3::IN_BLUE_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 86.474)), module, ESG3::OUT_LUMA_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 111.874)), module, ESG3::OUT_GREEN_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 111.874)), module, ESG3::OUT_BLUE_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 111.874)), module, ESG3::OUT_RED_OUTPUT));
	}
};


Model* modelESG3 = createModel<ESG3, ESG3Widget>("ESG3");