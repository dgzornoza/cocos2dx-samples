#include "MainMenuLayer.h"

using namespace cocos2d;

/** Constructor por defecto de la clase */
MainMenuLayer::MainMenuLayer(void)
{

}

/** Destructor por defecto de la clase */
MainMenuLayer::~MainMenuLayer(void)
{
}

/** 
* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase
* @return True si se puede ha inicializado correctamente, false en caso contrario
*/
bool MainMenuLayer::init()
{
	// Inicializar el padre
	if ( !Layer::init() ) return false;

	// obtener dimensiones de diseño
	Size size = Director::getInstance()->getWinSize();

	// cachear los spriteframes del menu
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gui.plist", "gui.png");

	// crear menu
	this->createMenu();




	// cargar menu
	//ui::Layout* m_mainLayout = dynamic_cast<ui::Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MainMenuUI/MainMenuUI.json"));//
	//if (m_mainLayout == nullptr) return false;
	
	//ui::Widget* widget = static_cast<ui::Widget*>(m_mainLayout->getChildByName("MenuList"));
	//ui::Widget* widget2 = static_cast<ui::Widget*>(m_mainLayout->getChildByName("MenuListItem"));
    //cocostudio::ComRender *render = static_cast<cocostudio::ComRender*>(mainMenuNode->getChildByTag(10025)->getComponent("GUIComponent"));
	//ui::Widget* widget = static_cast<ui::Widget*>(render->getNode());	
	//ui::Button* button = static_cast<ui::Button*>(widget->getChildByName("Button_156"));
//	button->addTouchEventListener(this, toucheventselector(UIComponentTest::touchEvent));
    //button->addTouchEventListener(CC_CALLBACK_2(MainMenuLayer::menuCloseCallback, this));

	// inicializacion correcta
	return true;
}	

/** Funcion para la creacion del menu principal */
void MainMenuLayer::createMenu()
{
	//ui::Layout* layout = ui::Layout::create();
	//this->addChild(layout);

	ui::ListView* lv = ui::ListView::create();
    ui::Button* item = ui::Button::create();	
	item->loadTextures("close_normal.png", "close_normal.png", "", ui::Widget::TextureResType::LOCAL);
    lv->setItemModel(item);

    for (int i=0; i<20; i++)
    {
        lv->pushBackDefaultItem();
    }
    lv->setItemsMargin(10);
	lv->setGravity(ui::ListView::Gravity::CENTER_HORIZONTAL);
    lv->setSize(Size(100, 100));
	//lv->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    //lv->setBackGroundColor(Color3B::GREEN);
    lv->setPosition(Point(100, 100));
	this->addChild(lv);
}

/** Funcion callback para cerrar la aplicacion */
void MainMenuLayer::menuCloseCallback(Ref* _sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}