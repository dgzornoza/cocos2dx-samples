#include "MainMenuScene.h"

using namespace cocos2d;

/** Constructor por defecto de la clase */
MainMenuScene::MainMenuScene(void)
	: m_mainMenuLayer(nullptr)
{
}

/** Destructor por defecto de la clase */
MainMenuScene::~MainMenuScene(void)
{
}

/** 
* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase
* @return True si se puede ha inicializado correctamente, false en caso contrario
*/
bool MainMenuScene::init()
{
	// Inicializar el padre
	if ( !Scene::init() ) return false;

	// Inicializar la capa con el menu principal
	this->m_mainMenuLayer = MainMenuLayer::create();
	this->addChild(this->m_mainMenuLayer);

	// inicializacion correcta
	return true;
}	

