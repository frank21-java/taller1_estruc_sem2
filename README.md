# Hospital Marmaja

## Integrantes

| Nombre | RUT | Usuario GitHub | Carrera |
|--------|-----|----------------|---------|
| [Francisco Castillo] | [21.717.293-9] | [@frank21-java) | [Ing. en Tecnologías de Información] |
## Compilación
## Árbol de Decisión Implementado
```text
¿Signos vitales críticos? (Temp >= 39.5 O PresiónArterial >= 160 O Dolor >= 9)
|-- Sí: Urgencias
|-- No:
    ¿Dolor en el pecho? (TipoDolor == "pecho")
    |-- Sí: Cardiología
    |-- No:
        ¿Síntomas Neurológicos? (SíntomasNeurologicos == 1)
        |-- Sí: Neurología
        |-- No:
            ¿Tiene Trauma? (Trauma == 1)
            |-- Sí:
            |   ¿Requiere Cirugía? (RequiereCirugia == 1)
            |   |-- Sí: Cirugía
            |   |-- No: Traumatología
            |-- No:
                ¿Es menor de 14 años? (Edad < 14)
                |-- Sí: Pediatría
                |-- No:
                    ¿Requiere hospitalización? (DiasHospitalizacion >= 3)
                    |-- Sí: Hospitalización
                    |-- No: Medicina General
----------------------------------
## Instrucciones de Compilación y Ejecución

El proyecto está modularizado en carpetas (`PACIENTE`, `NODOS`, `AVL`, `DATA`). Para compilarlo correctamente, debes ubicarte en la raíz del proyecto (donde está el archivo `main.cpp`) y ejecutar los comandos según tu sistema operativo.

*(Nota: Asegúrate de tener el archivo `ejemplo.txt` dentro de la carpeta `DATA`, ya que el programa busca la ruta relativa `DATA/ejemplo.txt`).*

###Para Windows (CMD / PowerShell)

1. Abre la consola (CMD) y navega hasta la carpeta del proyecto. Por ejemplo:
```cmd
cd C:\ruta\a\tu\proyecto
2 Compila usando el siguente comando:
g++ main.cpp PACIENTE/*.cpp NODOS/*.cpp AVL/*.cpp -o hospital.exe
3 Ejecutar el programa llamado "hostipal.exe

###Para Linux / GitHub Codespaces
1. Abre la terminal de Linux o inicia tu entorno de GitHub Codespaces. Si no estás en la carpeta raíz del proyecto, navega hasta ella con `cd`:
```bash
cd ruta/a/tu/proyecto
2 Compila usando el siguente comando:
g++ main.cpp PACIENTE/*.cpp NODOS/*.cpp AVL/*.cpp -o hospital
3 Otorgar permisos (para evitar errores)
chmod +x hospital
4 Ejecuta el programa
./hospital
