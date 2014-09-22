#include "SpritesSampleLayer.h"

using namespace cocos2d;

/** Constructor por defecto de la clase */
SpritesSampleLayer::SpritesSampleLayer(void)
{

}

/** Destructor por defecto de la clase */
SpritesSampleLayer::~SpritesSampleLayer(void)
{
}

/** 
* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase
* @return True si se puede ha inicializado correctamente, false en caso contrario
*/
bool SpritesSampleLayer::init()
{
	// Inicializar el padre
	if ( !Layer::init() ) return false;

	// obtener dimensiones de diseño
	Size size = Director::getInstance()->getWinSize();

	// cachear los spriteframes del menu
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gui.plist", "gui.png");


	// inicializacion correcta
	return true;
}	

