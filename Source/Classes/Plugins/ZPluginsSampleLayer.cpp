#include "ZPluginsSampleLayer.h"

#include "ZPlugin/PluginFactory.h"
#include "ZPlugin/ZMedia/ZMediaPlugin.h"

using namespace cocos2d;

/** Constructor por defecto de la clase */
ZPluginsSampleLayer::ZPluginsSampleLayer(void)
{

}

/** Destructor por defecto de la clase */
ZPluginsSampleLayer::~ZPluginsSampleLayer(void)
{
}

/** 
* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase
* @return True si se puede ha inicializado correctamente, false en caso contrario
*/
bool ZPluginsSampleLayer::init()
{
	// Inicializar el padre primero
	if ( !Layer::init() ) return false;

	// Inicializar clase

	// .......

	zplugin::zmedia::ZMedia* zmediaPlugin = zplugin::PluginFactory::getInstance()->loadPlugin<zplugin::zmedia::ZMedia>("zmedia");
	zmediaPlugin->GetAlbumItems();

	// inicializacion correcta
	return true;
}	
