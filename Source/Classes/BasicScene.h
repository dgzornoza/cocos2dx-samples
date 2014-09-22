#ifndef __SCENE_BASE_H__
#define __SCENE_BASE_H__

#include "cocos2d.h"

/** 
* @brief Clase con una plantilla para crear una escena basica para usar por los ejemplos
*/
template<class Tlayer>
class BasicScene : public cocos2d::Scene
{

public:

	/** Destructor por defecto de la clase */
	virtual ~BasicScene(void) { };

	/** 
	* Macro que sera desplegada en un metodo estatico 'create' para crear e inicializar la instancia de la clase.
	* La instancia de la clase debe ser creada invocando el metodo 'MainMenuLayer::create()'
	*/
	CREATE_FUNC(BasicScene<Tlayer>);

	// se hace uso de la macro de cocos2dx para definir el acceso de metodos heredados
	// con la finalidad de no violar el principio de sustitucion de Liskov y usar el mismo modificador de las clases base)
CC_CONSTRUCTOR_ACCESS:

	/** 
	* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase.
	* @return True si se ha inicializado correctamente, false en caso contrario
	*/
	virtual bool init() override
	{
		// 1.- Inicializar la escena padre
		if ( !Scene::init() ) return false;
	
		// 2.- inicializar capas
		this->m_mainlayer = Tlayer::create();

		// 3.- añadir capas a la escena
		this->addChild(this->m_mainlayer);

		// inicializacion correcta
		return true;
	}

protected:

	/** Constructor por defecto de la clase (protegido para evitar que se creen instancias desde fuera de la clase, deben crearse mediante el metodo 'BasicScene<Tlayer>::create()')*/
	BasicScene(void) { };

private:

	/** Capa principal que contiene la escena */
	Tlayer* m_mainlayer;

};


#endif // __SCENE_BASE_H__

