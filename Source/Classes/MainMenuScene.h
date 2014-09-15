#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "MainMenuLayer.h"
#include "cocos2d.h"

/** 
*@brief Clase con el elemento 'MainMenuScene' conteniendo la escena principal
*/
class MainMenuScene : public cocos2d::Scene
{

public:

	/** Destructor por defecto de la clase */
	virtual ~MainMenuScene(void);

	/** 
	* Macro que sera desplegada en un metodo estatico 'create' para crear e inicializar la instancia de la clase.
	* La instancia de la clase debe ser creada invocando el metodo 'MainMenuScene::create()'
	*/
	CREATE_FUNC(MainMenuScene);


	// se hace uso de la macro de cocos2dx para definir el acceso de metodos heredados
	// con la finalidad de no violar el principio de sustitucion de Liskov y usar el mismo modificador de las clases base)
CC_CONSTRUCTOR_ACCESS:

	/** 
	* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase.
	* @return True si se puede ha inicializado correctamente, false en caso contrario
	*/
	virtual bool init() override;

protected:

	/** Constructor por defecto de la clase (protegido para evitar que se creen instancias desde fuera de la clase, deben crearse mediante el metodo 'MainMenuScene::create()')*/
	MainMenuScene(void);

private:

	/** Capa con el menu principal de la escena */
	cocos2d::Layer* m_mainMenuLayer;
};

#endif // __MAIN_MENU_SCENE_H__

