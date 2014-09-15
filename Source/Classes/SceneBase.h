#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

/** 
*@brief Clase con la escena base para heredar por los ejemplos
*/
class SceneBase : public cocos2d::Scene
{

public:

	/** Destructor por defecto de la clase */
	virtual ~SceneBase(void);

	/** Metodo virtual para ejecutar la escena especifico que herede de esta escena */
    virtual void executeSample() = 0;


	// se hace uso de la macro de cocos2dx para definir el acceso de metodos heredados
	// con la finalidad de no violar el principio de sustitucion de Liskov y usar el mismo modificador de las clases base)
CC_CONSTRUCTOR_ACCESS:

	/** 
	* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase.
	* @return True si se ha inicializado correctamente, false en caso contrario
	*/
	virtual bool init() override;

protected:

	/** Constructor por defecto de la clase (protegido para evitar que se creen instancias desde fuera de la clase, deben crearse mediante el metodo 'SceneBase::create()')*/
	SceneBase(void);


private:

	/** Funcion callback para volver al menu principal 
	* @param _sender referencia al objeto remitente
	*/
    void mainMenuCallback(cocos2d::Ref* _sender);

};

#endif // __MAIN_MENU_SCENE_H__

