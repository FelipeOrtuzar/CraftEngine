# CraftEngine
Repository for the RTS game engine



# Instalación

## Requisitos
- Visual Studio 2019
- Windows 10 
- CMake

# Proceso de instalación y replicabilidad
- Clonar el repositorio en su <path> elegido.
- Abrir Visual Studio 2019 en <path>.
- Seleccionar compilación en modo "release": x64-Release.
- Ir a <path>/source/gomaengine/aplication.cpp y modificar los path a los actuales (reemplazar el path obsoleto por <path>\\assets\\...).
Es es en la línea 15, 78.
- Abrir el archivo wg_test.cpp y hacer click en el boton "play" verde que dice: "Documento actual (wg_test.cpp)"
- Por mientras que se carga, ir a <path>\third_party\SFML\extlibs\bin\x64\ y copiar en el portapapeles el archivo openal32.dll
- Esperar a que Visual Studio 2019 haga Build y abra una pantalla negra, donde va a aparecer un error de sistema.
- Ir a la carpeta <path>\out\build\x64-Release\source\gomaengine_ex\ y pegar del portapapeles el archivo openal32.dll
- Abrir de nuevo el archivo wg_test.cpp y hacer click en el boton "play" verde que dice: "Documento actual (wg_test.cpp)"
- Ahora debería abrir el demo.
  
## User input:
  Teclado: 
    - O , P para alternar entre música de fondo.
    - A, S, D, W para mover la vista.
    - Escape para salir del juego.
  Mouse:
    - Se puede hacer click izquierdo sobre los objetos en pantalla para seleccionarlos y moverlos con el click derecho. 

## REVISAR DOCUMENTACION RESTANTE EN LA CARPETA documentacion/
  - También hay un ejemplo de uso en la carpeta source/gomaengine_ex
