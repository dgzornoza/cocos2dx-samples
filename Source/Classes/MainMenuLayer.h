#ifndef __MAIN_MENU_LAYER_H__
#define __MAIN_MENU_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"

/** 
*@brief Clase con la capa del menu principal
*/
class MainMenuLayer : public cocos2d::Layer
{

public:

	/** Destructor por defecto de la clase */
	virtual ~MainMenuLayer(void);

	/** 
	* Macro que sera desplegada en un metodo estatico 'create' para crear e inicializar la instancia de la clase.
	* La instancia de la clase debe ser creada invocando el metodo 'MainMenuLayer::create()'
	*/
	CREATE_FUNC(MainMenuLayer);


	// se hace uso de la macro de cocos2dx para definir el acceso de metodos heredados
	// con la finalidad de no violar el principio de sustitucion de Liskov y usar el mismo modificador de las clases base)
CC_CONSTRUCTOR_ACCESS:

	/** 
	* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase.
	* @return True si se puede ha inicializado correctamente, false en caso contrario
	*/
	virtual bool init() override;

protected:

	/** Constructor por defecto de la clase (protegido para evitar que se creen instancias desde fuera de la clase, deben crearse mediante el metodo 'MainMenuLayer::create()')*/
	MainMenuLayer(void);



private:

	/** Funcion para la creacion del menu principal */
	void MainMenuLayer::createMenu();

	/** Funcion callback para cerrar la aplicacion
	* @param _sender objeto remitente de la funcion callback
	*/
    void menuCloseCallback(cocos2d::Ref* _sender);

};

#endif // __MAIN_MENU_LAYER_H__
