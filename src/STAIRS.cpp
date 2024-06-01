#include "plugin.hpp"
#include "Components.hpp"

struct STAIRS : Module {
	enum ParamId {
		K_STEPS_PARAM,
		K_PHASE_PARAM,
		K_STEPS_CV_PARAM,
		K_PHASE_CV_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_STEPS_CV_INPUT,
		IN_PHASE_CV_INPUT,
		IN_1_INPUT,
		IN_2_INPUT,
		IN_3_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUT_2_OUTPUT,
		OUT_4_OUTPUT,
		OUT_8_OUTPUT,
		OUT_16_OUTPUT,
		OUT_32_OUTPUT,
		OUT_64_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	STAIRS() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(K_STEPS_PARAM, 0.f, 1.f, 0.f, "");
		configParam(K_PHASE_PARAM, 0.f, 1.f, 0.f, "");
		configParam(K_STEPS_CV_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_PHASE_CV_PARAM, 0.f, 1.f, 0.5f, "");
		configInput(IN_STEPS_CV_INPUT, "");
		configInput(IN_PHASE_CV_INPUT, "");
		configInput(IN_1_INPUT, "");
		configInput(IN_2_INPUT, "");
		configInput(IN_3_INPUT, "");
		configOutput(OUT_2_OUTPUT, "");
		configOutput(OUT_4_OUTPUT, "");
		configOutput(OUT_8_OUTPUT, "");
		configOutput(OUT_16_OUTPUT, "");
		configOutput(OUT_32_OUTPUT, "");
		configOutput(OUT_64_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct STAIRSWidget : ModuleWidget {
	STAIRSWidget(STAIRS* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/STAIRS.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 16.624)), module, STAIRS::K_STEPS_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 16.624)), module, STAIRS::K_PHASE_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 42.024)), module, STAIRS::K_STEPS_CV_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(30.48, 42.024)), module, STAIRS::K_PHASE_CV_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(10.16, 67.424)), module, STAIRS::IN_STEPS_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(30.48, 67.424)), module, STAIRS::IN_PHASE_CV_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, STAIRS::IN_1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, STAIRS::IN_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, STAIRS::IN_3_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.32, 86.474)), module, STAIRS::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 86.474)), module, STAIRS::OUT_4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.32, 99.174)), module, STAIRS::OUT_8_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 99.174)), module, STAIRS::OUT_16_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.32, 111.874)), module, STAIRS::OUT_32_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 111.874)), module, STAIRS::OUT_64_OUTPUT));
	}
};


Model* modelSTAIRS = createModel<STAIRS, STAIRSWidget>("STAIRS");