cocos2dx-samples
================

Ejemplos para los artículos dedicados a cocos2dx:
http://www.dgzornoza.com/



Los ejemplos estan desarrollados para la version cocos2dx 3.7

No se incluye el código fuente de la librería cocos2dx para reducir el tamaño del proyecto, de modo que para la compilación se debera crear un proyecto nuevo de cocos2dx en el directorio raiz, luego solo hace falta copiar el contenido de la carpeta 'Source' en el proyecto creado.

Compilacion Win32:

1.- Tiene que añadirse los siguientes directorios de inclusion adicionales:

$(EngineRoot)..\..\External\Toolkit.Helpers\include
$(EngineRoot)..\Classes

2.- En el linker añadir la siguiente dependencia:

Toolkit.Helpers.lib

2.- Añadir el siguiente comando en el evento Pre-Link:

if not exist "$(OutDir)" mkdir "$(OutDir)"
xcopy /Y /Q "$(EngineRoot)..\..\External\Toolkit.Helpers\prebuilt\win32\*.*" "$(OutDir)"



