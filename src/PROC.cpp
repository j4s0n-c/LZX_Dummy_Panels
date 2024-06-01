#include "plugin.hpp"
#include "Components.hpp"

struct PROC : Module {
	enum ParamId {
		K_B1_PARAM,
		K_C1_PARAM,
		K_B2_PARAM,
		K_C2_PARAM,
		K_B3_PARAM,
		K_C3_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_A1_INPUT,
		IN_B1_INPUT,
		IN_A2_INPUT,
		IN_B2_INPUT,
		IN_A3_INPUT,
		IN_B3_INPUT,
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

	PROC() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(K_B1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_C1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_B2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_C2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_B3_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_C3_PARAM, 0.f, 1.f, 0.5f, "");
		configInput(IN_A1_INPUT, "");
		configInput(IN_B1_INPUT, "");
		configInput(IN_A2_INPUT, "");
		configInput(IN_B2_INPUT, "");
		configInput(IN_A3_INPUT, "");
		configInput(IN_B3_INPUT, "");
		configOutput(OUT_1_OUTPUT, "");
		configOutput(OUT_2_OUTPUT, "");
		configOutput(OUT_3_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct PROCWidget : ModuleWidget {
	PROCWidget(PROC* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/PROC.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 16.624)), module, PROC::K_B1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 16.624)), module, PROC::K_C1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 42.024)), module, PROC::K_B2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 42.024)), module, PROC::K_C2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 67.424)), module, PROC::K_B3_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 67.424)), module, PROC::K_C3_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, PROC::IN_A1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.32, 86.474)), module, PROC::IN_B1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, PROC::IN_A2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.32, 99.174)), module, PROC::IN_B2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, PROC::IN_A3_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.32, 111.874)), module, PROC::IN_B3_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 86.474)), module, PROC::OUT_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 99.174)), module, PROC::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 111.874)), module, PROC::OUT_3_OUTPUT));
	}
};


Model* modelPROC = createModel<PROC, PROCWidget>("PROC");