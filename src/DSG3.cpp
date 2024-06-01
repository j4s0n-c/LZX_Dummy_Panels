#include "plugin.hpp"
#include "Components.hpp"

struct DSG3 : Module {
	enum ParamId {
		SW_1_PARAM,
		SW_2_PARAM,
		SW_3_PARAM,
		SW_4_PARAM,
		SW_5_PARAM,
		SW_6_PARAM,
		SW_7_PARAM,
		SW_8_PARAM,
		SW_9_PARAM,
		SW_10_PARAM,
		SW_11_PARAM,
		SW_12_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_1_INPUT,
		IN_2_INPUT,
		IN_3_INPUT,
		IN_4_INPUT,
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

	DSG3() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configSwitch(SW_1_PARAM, 0.f, 1.f, 1.f, "");
		configSwitch(SW_2_PARAM, 0.f, 1.f, 1.f, "");
		configSwitch(SW_3_PARAM, 0.f, 1.f, 1.f, "");
		configSwitch(SW_4_PARAM, 0.f, 1.f, 1.f, "");
		configSwitch(SW_5_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_6_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_7_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_8_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_9_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_10_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_11_PARAM, 0.f, 2.f, 1.f, "");
		configSwitch(SW_12_PARAM, 0.f, 2.f, 1.f, "");
		configInput(IN_1_INPUT, "");
		configInput(IN_2_INPUT, "");
		configInput(IN_3_INPUT, "");
		configInput(IN_4_INPUT, "");
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


struct DSG3Widget : ModuleWidget {
	DSG3Widget(DSG3* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/DSG3.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Switch_2>(mm2px(Vec(7.62, 16.602)), module, DSG3::SW_1_PARAM));
		addParam(createParamCentered<Lzx_Switch_2>(mm2px(Vec(22.86, 16.602)), module, DSG3::SW_2_PARAM));
		addParam(createParamCentered<Lzx_Switch_2>(mm2px(Vec(38.1, 16.602)), module, DSG3::SW_3_PARAM));
		addParam(createParamCentered<Lzx_Switch_2>(mm2px(Vec(53.34, 16.602)), module, DSG3::SW_4_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(7.62, 42.002)), module, DSG3::SW_5_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(22.86, 42.002)), module, DSG3::SW_6_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(38.1, 42.002)), module, DSG3::SW_7_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(53.34, 42.002)), module, DSG3::SW_8_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(7.62, 67.402)), module, DSG3::SW_9_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(22.86, 67.402)), module, DSG3::SW_10_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(38.1, 67.402)), module, DSG3::SW_11_PARAM));
		addParam(createParamCentered<Lzx_Switch_3>(mm2px(Vec(53.34, 67.402)), module, DSG3::SW_12_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, DSG3::IN_1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 86.474)), module, DSG3::IN_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 86.474)), module, DSG3::IN_3_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(53.34, 86.474)), module, DSG3::IN_4_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, DSG3::OUT_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 99.174)), module, DSG3::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 99.174)), module, DSG3::OUT_3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 99.174)), module, DSG3::OUT_4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, DSG3::OUT_5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 111.874)), module, DSG3::OUT_6_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 111.874)), module, DSG3::OUT_7_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 111.874)), module, DSG3::OUT_8_OUTPUT));
	}
};


Model* modelDSG3 = createModel<DSG3, DSG3Widget>("DSG3");