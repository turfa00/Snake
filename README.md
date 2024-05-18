# Raylib C++ Snake Game
Ceci est un implementation du jeu classique d'arcade "Snake". Il consiste à guider un serpent en pleine croissance pour qu'il consomme de la nourriture
tout en évitant les collisions avec les murs ou avec lui-même.
 
### Exécution
le code est écrit en C++ et peut donc être exécuté par n'importe quel compilateur prenant en charge C++.\
Le fichier étant écrit dans le flux de sortie standard, vous devrez le rediriger vers un fichier image. Le programme doit donc être construit avec cmake.

Sous Windows, pour obtenir la version de débogage de CMake, il faut exécuter cette commande :

*cmake -B build* \
*cmake --build build* 

Ensuite, exécutez le programme comme ceci : \
*build\Debug\main.exe > image_name.ppm* 

Cette version contient déjà le fichier le fichier CMakeLists.txt avec l'ensemble d'instructions pour l'exécutable.

### Résultat
![image](https://github.com/turfa00/Ray_Tracer/assets/80334127/0205ad9e-3958-4608-904a-9193d29c3681)

### Références
Ray Tracing in One Weekend par Peter Shirley \
https://raytracing.github.io/books/RayTracingInOneWeekend.html

