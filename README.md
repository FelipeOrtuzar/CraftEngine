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
  
  
## Justificación de la arquitectura para GameObject
  La arquitectura para los GameObjects será de composición de componentes. Es decir, se espera que un objeto inicial no tenga mayor impacto en el juego, y a medida que se vayan requiriendo componentes, como gráficos, sonido, movimiento, IA, etc. se vayan integrando al modelo.
Se eligió esta arquitectura por distintas razones:
-	En primer lugar, para el uso correcto de recursos de memoria y procesamiento, es importante que los modelos en el videojuego sólo tengan las características que necesiten, ni más ni menos. No es el objetivo del GameObject que tenga todas las funcionalidades posibles si es que no las usan, y menos si usan innecesariamente recursos del sistema.
-	En segundo lugar, esta arquitectura ayuda a mantener el código más limpio y fácil de manejar, mientras el engine sea de un tamaño menor. Así, si aparece un problema en alguno de los componentes, es más fácil ir a ese componente a arreglarlo.
-	Otra característica interesante de este modelo es que permite la paralelización de manera más simple, puesto que se pueden correr los distintos componentes en threads diferentes de manera más directa en el código. (Esto no quiere decir que sea más fácil, pero los organismos están mejor separados unos de otros.)
-	Con respecto a los updates, es importante tratar de que el GameObject no “sepa” cómo se actualizan sus componentes y así se pueda preocuparse más de la lógica del videojuego en sí, que de cómo elementos más genéricos realizan labores rutinarias.
-	Por último, dada mi inexperiencia en el lenguaje cpp y desarrollo de arquitecturas, es importante tratar de generar una guía lo más fácil de seguir y desarrollar en el Game Engine, y en mi opinión personal el patrón de diseño de componentes ayuda a programar mejor si uno todavía no tiene completo conocimiento del desarrolló y sus por qués.

