#include "plugin.hpp"
#include "Components.hpp"

struct DWO3 : Module {
	enum ParamId {
		KNOB_FREQ1_PARAM,
		KNOB_FREQ2_PARAM,
		KNOB_FREQ1_CV_PARAM,
		KNOB_RANGE1_PARAM,
		KNOB_FREQ2_CV_PARAM,
		KNOB_RANGE_2_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_1_INPUT,
		IN_2_INPUT,
		IN_3_INPUT,
		IN_4_INPUT,
		IN_5_INPUT,
		IN_6_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		OUT_1_OUTPUT,
		OUT_2_OUTPUT,
		OUT_3_OUTPUT,
		OUT_4_OUTPUT,
		OUT_5_OUTPUT,
		OUT_6_OUTPUT,
		OUT_7_OUTPUT,
		OUT_8_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	DWO3() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(KNOB_FREQ1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_FREQ2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_FREQ1_CV_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_RANGE1_PARAM, 0.f, 1.f, 0.f, "");
		configParam(KNOB_FREQ2_CV_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(KNOB_RANGE_2_PARAM, 0.f, 1.f, 0.f, "");
		configInput(IN_1_INPUT, "");
		configInput(IN_2_INPUT, "");
		configInput(IN_3_INPUT, "");
		configInput(IN_4_INPUT, "");
		configInput(IN_5_INPUT, "");
		configInput(IN_6_INPUT, "");
		configOutput(OUT_1_OUTPUT, "");
		configOutput(OUT_2_OUTPUT, "");
		configOutput(OUT_3_OUTPUT, "");
		configOutput(OUT_4_OUTPUT, "");
		configOutput(OUT_5_OUTPUT, "");
		configOutput(OUT_6_OUTPUT, "");
		configOutput(OUT_7_OUTPUT, "");
		configOutput(OUT_8_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct DWO3Widget : ModuleWidget {
	DWO3Widget(DWO3* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/DWO3.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 16.624)), module, DWO3::KNOB_FREQ1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(50.8, 16.624)), module, DWO3::KNOB_FREQ2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 42.024)), module, DWO3::KNOB_FREQ1_CV_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 42.024)), module, DWO3::KNOB_RANGE1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(50.8, 42.024)), module, DWO3::KNOB_FREQ2_CV_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 67.424)), module, DWO3::KNOB_RANGE_2_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(10.16, 67.424)), module, DWO3::IN_1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(50.8, 67.424)), module, DWO3::IN_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, DWO3::IN_3_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 86.474)), module, DWO3::IN_4_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 86.474)), module, DWO3::IN_5_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(53.34, 86.474)), module, DWO3::IN_6_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, DWO3::OUT_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 99.174)), module, DWO3::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 99.174)), module, DWO3::OUT_3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 99.174)), module, DWO3::OUT_4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, DWO3::OUT_5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 111.874)), module, DWO3::OUT_6_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 111.874)), module, DWO3::OUT_7_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 111.874)), module, DWO3::OUT_8_OUTPUT));
	}
};


Model* modelDWO3 = createModel<DWO3, DWO3Widget>("DWO3");