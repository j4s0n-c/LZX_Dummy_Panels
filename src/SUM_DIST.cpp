#include "plugin.hpp"


struct SUM_DIST : Module {
	enum ParamId {
		PARAMS_LEN
	};
	enum InputId {
		PATH139_INPUT,
		PATH139_2_INPUT,
		PATH139_27_INPUT,
		PATH139_9_INPUT,
		PATH139_9_7_INPUT,
		PATH139_9_4_INPUT,
		PATH139_97_INPUT,
		PATH139_97_8_INPUT,
		PATH139_97_7_INPUT,
		PATH139_96_INPUT,
		PATH139_96_9_INPUT,
		PATH139_96_3_INPUT,
		PATH139_6_INPUT,
		PATH139_9_2_INPUT,
		PATH139_97_4_INPUT,
		PATH139_96_5_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		PATH139_62_OUTPUT,
		PATH139_9_29_OUTPUT,
		PATH139_97_46_OUTPUT,
		PATH139_96_32_OUTPUT,
		PATH139_2_9_OUTPUT,
		PATH139_27_6_OUTPUT,
		PATH139_62_4_OUTPUT,
		PATH139_9_7_8_OUTPUT,
		PATH139_9_4_3_OUTPUT,
		PATH139_9_29_0_OUTPUT,
		PATH139_97_8_3_OUTPUT,
		PATH139_97_7_4_OUTPUT,
		PATH139_97_46_5_OUTPUT,
		PATH139_96_9_7_OUTPUT,
		PATH139_96_3_8_OUTPUT,
		PATH139_96_32_5_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	SUM_DIST() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configInput(PATH139_INPUT, "");
		configInput(PATH139_2_INPUT, "");
		configInput(PATH139_27_INPUT, "");
		configInput(PATH139_9_INPUT, "");
		configInput(PATH139_9_7_INPUT, "");
		configInput(PATH139_9_4_INPUT, "");
		configInput(PATH139_97_INPUT, "");
		configInput(PATH139_97_8_INPUT, "");
		configInput(PATH139_97_7_INPUT, "");
		configInput(PATH139_96_INPUT, "");
		configInput(PATH139_96_9_INPUT, "");
		configInput(PATH139_96_3_INPUT, "");
		configInput(PATH139_6_INPUT, "");
		configInput(PATH139_9_2_INPUT, "");
		configInput(PATH139_97_4_INPUT, "");
		configInput(PATH139_96_5_INPUT, "");
		configOutput(PATH139_62_OUTPUT, "");
		configOutput(PATH139_9_29_OUTPUT, "");
		configOutput(PATH139_97_46_OUTPUT, "");
		configOutput(PATH139_96_32_OUTPUT, "");
		configOutput(PATH139_2_9_OUTPUT, "");
		configOutput(PATH139_27_6_OUTPUT, "");
		configOutput(PATH139_62_4_OUTPUT, "");
		configOutput(PATH139_9_7_8_OUTPUT, "");
		configOutput(PATH139_9_4_3_OUTPUT, "");
		configOutput(PATH139_9_29_0_OUTPUT, "");
		configOutput(PATH139_97_8_3_OUTPUT, "");
		configOutput(PATH139_97_7_4_OUTPUT, "");
		configOutput(PATH139_97_46_5_OUTPUT, "");
		configOutput(PATH139_96_9_7_OUTPUT, "");
		configOutput(PATH139_96_3_8_OUTPUT, "");
		configOutput(PATH139_96_32_5_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct SUM_DISTWidget : ModuleWidget {
	SUM_DISTWidget(SUM_DIST* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/SUM_DIST.svg")));

		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 16.624)), module, SUM_DIST::PATH139_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 16.624)), module, SUM_DIST::PATH139_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 16.624)), module, SUM_DIST::PATH139_27_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 29.324)), module, SUM_DIST::PATH139_9_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 29.324)), module, SUM_DIST::PATH139_9_7_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 29.324)), module, SUM_DIST::PATH139_9_4_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 42.024)), module, SUM_DIST::PATH139_97_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.86, 42.024)), module, SUM_DIST::PATH139_97_8_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.1, 42.024)), module, SUM_DIST::PATH139_97_7_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.619, 54.803)), module, SUM_DIST::PATH139_96_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.859, 54.803)), module, SUM_DIST::PATH139_96_9_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(38.099, 54.802)), module, SUM_DIST::PATH139_96_3_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 73.774)), module, SUM_DIST::PATH139_6_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 86.474)), module, SUM_DIST::PATH139_9_2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 99.174)), module, SUM_DIST::PATH139_97_4_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.62, 111.953)), module, SUM_DIST::PATH139_96_5_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 16.655)), module, SUM_DIST::PATH139_62_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 29.355)), module, SUM_DIST::PATH139_9_29_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 42.055)), module, SUM_DIST::PATH139_97_46_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.339, 54.834)), module, SUM_DIST::PATH139_96_32_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 73.774)), module, SUM_DIST::PATH139_2_9_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 73.774)), module, SUM_DIST::PATH139_27_6_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 73.805)), module, SUM_DIST::PATH139_62_4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 86.474)), module, SUM_DIST::PATH139_9_7_8_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 86.474)), module, SUM_DIST::PATH139_9_4_3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 86.505)), module, SUM_DIST::PATH139_9_29_0_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.86, 99.174)), module, SUM_DIST::PATH139_97_8_3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.1, 99.174)), module, SUM_DIST::PATH139_97_7_4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.34, 99.205)), module, SUM_DIST::PATH139_97_46_5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.859, 111.952)), module, SUM_DIST::PATH139_96_9_7_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(38.099, 111.952)), module, SUM_DIST::PATH139_96_3_8_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(53.339, 111.983)), module, SUM_DIST::PATH139_96_32_5_OUTPUT));
	}
};


Model* modelSUM_DIST = createModel<SUM_DIST, SUM_DISTWidget>("SUM_DIST");