#include "SceneBase.h"


using namespace cocos2d;

/** Constructor por defecto de la clase */
template<class Tlayer>
SceneBase<Tlayer>::SceneBase(void)
{
}

/** Destructor por defecto de la clase */
template<class Tlayer>
SceneBase<Tlayer>::~SceneBase(void)
{
}

/** 
* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase
* @return True si se puede ha inicializado correctamente, false en caso contrario
*/
template<class Tlayer>
bool SceneBase<Tlayer>::init()
{
	// 1.- Inicializar la escena padre
	if ( !Scene::init() ) return false;
	
	// 2.- inicializar capas
	this->m_mainlayer == Tlayer::create();

	// inicializacion correcta
	return true;
}	
