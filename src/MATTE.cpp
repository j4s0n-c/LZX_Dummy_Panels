#include "plugin.hpp"
#include "Components.hpp"

struct MATTE : Module {
	enum ParamId {
		K_A1_PARAM,
		K_B1_PARAM,
		K_A2_PARAM,
		K_B2_PARAM,
		K_A3_PARAM,
		K_B3_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		INPUTS_LEN
	};
	enum OutputId {
		OUT_A1_OUTPUT,
		OUT_AB1_OUTPUT,
		OUT_B1_OUTPUT,
		OUT_A2_OUTPUT,
		OUT_AB2_OUTPUT,
		OUT_B2_OUTPUT,
		OUT_A3_OUTPUT,
		OUT_AB3_OUTPUT,
		OUT_B3_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	MATTE() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(K_A1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_B1_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_A2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_B2_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_A3_PARAM, 0.f, 1.f, 0.5f, "");
		configParam(K_B3_PARAM, 0.f, 1.f, 0.5f, "");
		configOutput(OUT_A1_OUTPUT, "");
		configOutput(OUT_AB1_OUTPUT, "");
		configOutput(OUT_B1_OUTPUT, "");
		configOutput(OUT_A2_OUTPUT, "");
		configOutput(OUT_AB2_OUTPUT, "");
		configOutput(OUT_B2_OUTPUT, "");
		configOutput(OUT_A3_OUTPUT, "");
		configOutput(OUT_AB3_OUTPUT, "");
		configOutput(OUT_B3_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct MATTEWidget : ModuleWidget {
	MATTEWidget(MATTE* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/MATTE.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 16.624)), module, MATTE::K_A1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 16.624)), module, MATTE::K_B1_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 42.024)), module, MATTE::K_A2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 42.024)), module, MATTE::K_B2_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(10.16, 67.424)), module, MATTE::K_A3_PARAM));
		addParam(createParamCentered<Lzx_Knob_Filled>(mm2px(Vec(30.48, 67.424)), module, MATTE::K_B3_PARAM));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, MATTE::OUT_A1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.32, 86.474)), module, MATTE::OUT_AB1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 86.474)), module, MATTE::OUT_B1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, MATTE::OUT_A2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.32, 99.174)), module, MATTE::OUT_AB2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 99.174)), module, MATTE::OUT_B2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.874)), module, MATTE::OUT_A3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(20.32, 111.874)), module, MATTE::OUT_AB3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(33.02, 111.874)), module, MATTE::OUT_B3_OUTPUT));
	}
};


Model* modelMATTE = createModel<MATTE, MATTEWidget>("MATTE");