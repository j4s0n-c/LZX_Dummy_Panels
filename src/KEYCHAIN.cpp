#include "plugin.hpp"
#include "Components.hpp"

struct KEYCHAIN : Module {
	enum ParamId {
		K_CV_1_PARAM,
		K_THRESH_1_PARAM,
		K_CV_2_PARAM,
		K_THRESH_2_PARAM,
		K_CV_3_PARAM,
		K_THRESH_3_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		IN_CV_1_INPUT,
		IN_KEY_1_INPUT,
		IN_CV_2_INPUT,
		IN_KEY_2_INPUT,
		IN_CV_3_INPUT,
		IN_KEY_3_INPUT,
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

	KEYCHAIN() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(K_CV_1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_THRESH_1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_CV_2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_THRESH_2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_CV_3_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_THRESH_3_PARAM, 0.f, 1.f, 0.5f, "");
		configInput(IN_CV_1_INPUT, "");
		configInput(IN_KEY_1_INPUT, "");
		configInput(IN_CV_2_INPUT, "");
		configInput(IN_KEY_2_INPUT, "");
		configInput(IN_CV_3_INPUT, "");
		configInput(IN_KEY_3_INPUT, "");
		configOutput(OUT_1_OUTPUT, "");
		configOutput(OUT_2_OUTPUT, "");
		configOutput(OUT_3_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct KEYCHAINWidget : ModuleWidget {
	KEYCHAINWidget(KEYCHAIN* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/KEYCHAIN.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 16.624)), module, KEYCHAIN::K_CV_1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 16.624)), module, KEYCHAIN::K_THRESH_1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 42.024)), module, KEYCHAIN::K_CV_2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 42.024)), module, KEYCHAIN::K_THRESH_2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Outline>(mm2px(Vec(10.16, 67.424)), module, KEYCHAIN::K_CV_3_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 67.424)), module, KEYCHAIN::K_THRESH_3_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, KEYCHAIN::IN_CV_1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.32, 86.474)), module, KEYCHAIN::IN_KEY_1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, KEYCHAIN::IN_CV_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.32, 99.174)), module, KEYCHAIN::IN_KEY_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, KEYCHAIN::IN_CV_3_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(20.32, 111.874)), module, KEYCHAIN::IN_KEY_3_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 86.474)), module, KEYCHAIN::OUT_1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 99.174)), module, KEYCHAIN::OUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 111.874)), module, KEYCHAIN::OUT_3_OUTPUT));
	}
};


Model* modelKEYCHAIN = createModel<KEYCHAIN, KEYCHAINWidget>("KEYCHAIN");