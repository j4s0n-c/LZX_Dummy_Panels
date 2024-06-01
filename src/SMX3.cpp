#include "plugin.hpp"
#include "Components.hpp"

struct SMX3 : Module {
	enum ParamId {
		KNOB_A1_PARAM,
		KNOB_B1_PARAM,
		KNOB_C1_PARAM,
		KNOB_A2_PARAM,
		KNOB_B2_PARAM,
		KNOB_C2_PARAM,
		KNOB_A3_PARAM,
		KNOB_B3_PARAM,
		KNOB_C3_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_A_RED_INPUT,
		IN_B_RED_INPUT,
		IN_C_RED_INPUT,
		IN_A_GREEN_INPUT,
		IN_B_GREEN_INPUT,
		IN_C_GREEN_INPUT,
		IN_A_BLUE_INPUT,
		IN_B_BLUE_INPUT,
		IN_C_BLUE_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUT_RED_OUTPUT,
		OUT_GREEN_OUTPUT,
		OUT_BLUE_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	SMX3() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(KNOB_A1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_B1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_C1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_A2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_B2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_C2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_A3_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_B3_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_C3_PARAM, 0.f, 1.f, 0.5f, "");
		configInput(IN_A_RED_INPUT, "");
		configInput(IN_B_RED_INPUT, "");
		configInput(IN_C_RED_INPUT, "");
		configInput(IN_A_GREEN_INPUT, "");
		configInput(IN_B_GREEN_INPUT, "");
		configInput(IN_C_GREEN_INPUT, "");
		configInput(IN_A_BLUE_INPUT, "");
		configInput(IN_B_BLUE_INPUT, "");
		configInput(IN_C_BLUE_INPUT, "");
		configOutput(OUT_RED_OUTPUT, "");
		configOutput(OUT_GREEN_OUTPUT, "");
		configOutput(OUT_BLUE_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct SMX3Widget : ModuleWidget {
	SMX3Widget(SMX3* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/SMX3.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 16.624)), module, SMX3::KNOB_A1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(30.48, 16.624)), module, SMX3::KNOB_B1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(50.8, 16.624)), module, SMX3::KNOB_C1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 42.024)), module, SMX3::KNOB_A2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(30.48, 42.024)), module, SMX3::KNOB_B2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(50.8, 42.024)), module, SMX3::KNOB_C2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 67.424)), module, SMX3::KNOB_A3_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(30.48, 67.424)), module, SMX3::KNOB_B3_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(50.8, 67.424)), module, SMX3::KNOB_C3_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.475)), module, SMX3::IN_A_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 86.474)), module, SMX3::IN_B_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 86.475)), module, SMX3::IN_C_RED_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, SMX3::IN_A_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 99.174)), module, SMX3::IN_B_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 99.175)), module, SMX3::IN_C_GREEN_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.953)), module, SMX3::IN_A_BLUE_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 111.953)), module, SMX3::IN_B_BLUE_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 111.954)), module, SMX3::IN_C_BLUE_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 86.474)), module, SMX3::OUT_RED_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 99.174)), module, SMX3::OUT_GREEN_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 111.953)), module, SMX3::OUT_BLUE_OUTPUT));
	}
};


Model* modelSMX3 = createModel<SMX3, SMX3Widget>("SMX3");