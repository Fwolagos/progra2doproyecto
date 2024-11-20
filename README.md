# **Gestor de Rutas Turísticas**

Un programa interactivo que permite a los usuarios crear, visualizar y gestionar rutas turísticas utilizando una interfaz gráfica con SFML. Este proyecto combina estructuras de datos personalizadas con elementos gráficos para ofrecer una experiencia completa en la administración de puntos turísticos y rutas.

---

## **Tabla de Contenidos**
- [Descripción](#descripción)
- [Características](#características)
- [Instalación](#instalación)
- [Uso](#uso)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Tecnologías Utilizadas](#tecnologías-utilizadas)
- [Contribuciones](#contribuciones)
- [Licencia](#licencia)

---

## **Descripción**
El Gestor de Rutas Turísticas es una herramienta interactiva que utiliza gráficos para gestionar puntos y rutas en un mapa turístico. Con opciones para crear rutas, visualizar sus detalles, y almacenarlas en archivos, este proyecto ofrece una solución eficiente y visual para organizar destinos turísticos.

---

## **Características**
- **Crear Rutas**: Selecciona puntos en el mapa para definir una nueva ruta.
- **Visualizar Rutas**: Despliega rutas previamente creadas, mostrando puntos y coordenadas.
- **Guardar y Cargar Datos**: Persiste las rutas en un archivo para futuras sesiones.
- **Interfaz Gráfica con SFML**: Una experiencia visual intuitiva para los usuarios.
- **Gestión de Rutas**: Elimina rutas existentes o reinicia las selecciones actuales.

---

## **Instalación**
1. Clona el repositorio:
   ```bash
   git clone https://github.com/tuusuario/turismo.git
   cd turismo
Asegúrate de tener instalado un compilador compatible con C++17 o superior.
Instala la biblioteca SFML:
bash
Copy code
sudo apt-get install libsfml-dev # En Linux
Configura tu entorno de desarrollo (como Visual Studio o Code::Blocks) para incluir las rutas de las bibliotecas y cabeceras de SFML.
Compila y ejecuta el proyecto.
Uso
Ejecuta el programa.
Utiliza el menú para interactuar con las siguientes funciones:
Ctrl + C: Crear una nueva ruta.
Ctrl + V: Ver rutas guardadas.
Ctrl + R: Limpiar la selección actual.
Esc: Finalizar la creación de rutas.
Para salir, cierra la ventana o guarda las rutas al finalizar.
Estructura del Proyecto
makefile
Copy code
turismo/
│
├── sources/
│   ├── img/                # Recursos de imágenes (fondo del mapa)
│   ├── font/               # Fuentes utilizadas
│   ├── dates/              # Archivos persistentes para guardar datos
│   └── ...
├── include/
│   ├── routelist.h         # Definición de la lista de rutas
│   ├── route.h             # Definición de la clase Ruta
│   └── ...
├── src/
│   ├── main.cpp            # Punto de entrada del programa
│   ├── routemanager.cpp    # Lógica principal de gestión de rutas
│   └── ...
├── README.md               # Documentación del proyecto
└── ...
Tecnologías Utilizadas
Lenguaje: C++17
Biblioteca Gráfica: SFML
Entorno de Desarrollo: Configurable en Visual Studio, Code::Blocks o similares.
Contribuciones
¡Las contribuciones son bienvenidas! Si encuentras un error o tienes una idea para mejorar el proyecto:

Haz un fork del repositorio.
Crea una nueva rama:
bash
Copy code
git checkout -b feature/nueva-funcionalidad
Realiza tus cambios y realiza un pull request.
Licencia
Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más información.

Copy code

¡Listo para copiar y pegar directamente! 😊
