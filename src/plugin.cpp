#include "plugin.hpp"


Plugin* pluginInstance;


void init(Plugin* p) {
	pluginInstance = p;

	// Add modules here
	 p->addModel(modelFKG3);
	 p->addModel(modelSMX3);
	 p->addModel(modelSUM_DIST);
	 p->addModel(modelESG3);
	 p->addModel(modelDWO3);
	 p->addModel(modelDSG3);
	 p->addModel(modelKEYCHAIN);
	 p->addModel(modelMATTE);
	 p->addModel(modelPROC);
	 p->addModel(modelSTAIRS);

	// Any other plugin initialization may go here.
	// As an alternative, consider lazy-loading assets and lookup tables when your module is created to reduce startup times of Rack.
}
