# PATRÓN ABSTRACT FACTORY — SIS457 - Grupo 4

Proyecto desarrollado en **Unreal Engine 4.27.2** utilizando **C++**, como parte de las prácticas de patrones de diseño de la materia **SIS457 — USFX**.

Este trabajo incorpora el patrón de creación **Abstract Factory (Fábrica Abstracta)** al proyecto **AventuraUSFX022026L4**. La práctica continúa la implementación anterior de **Factory Method**, ampliando la organización de las fábricas mediante las clases **FabricaAbstracta**, **FabricaAzul** y **FabricaRoja**. También se incorpora **PelotaPequena** como parte de los archivos nuevos.

El objetivo del patrón es trabajar con **familias de objetos relacionados** a través de una abstracción común, sin obligar al código cliente a depender directamente de cada clase concreta.

---

## 1. Objetivo

Aplicar el patrón **Abstract Factory** dentro del juego, organizando la creación de productos mediante fábricas especializadas.

La idea es que:

- Exista una abstracción común para las fábricas.
- Puedan definirse distintas fábricas concretas, en este caso identificadas como **Azul** y **Roja**.
- La responsabilidad de crear objetos se concentre en las fábricas.
- El resto del programa pueda trabajar con las clases base o con las abstracciones correspondientes.
- La implementación sea sencilla, compatible con **Unreal Engine 4.27.2** y fácil de explicar.

A diferencia de crear cada objeto desde cualquier parte del juego, el patrón propone **seleccionar una fábrica y solicitarle los productos que necesita el cliente**.

---

## 2. Implementación final

Los archivos incorporados para esta práctica son:

```text
FabricaAbstracta.h
FabricaAbstracta.cpp
FabricaAzul.h
FabricaAzul.cpp
FabricaRoja.h
FabricaRoja.cpp
PelotaPequena.h
PelotaPequena.cpp
```

También se modificó el archivo:

```text
FabricaPlataformas.cpp
```

La implementación conserva la continuidad del proyecto anterior, en el que ya existían:

- `APlataforma`, clase base de las plataformas.
- `APlataformaIndestructible` y `APlataformaDestructible`.
- `AFabricaPlataformas`, utilizada en la implementación de Factory Method.
- `AAventuraUSFX022026L4GameMode`, responsable de iniciar la lógica del juego.

**Cambio principal:** pasar de concentrar la creación en una sola fábrica a trabajar con una organización que incorpora una fábrica abstracta y fábricas concretas.

---

## 3. ¿Qué es Abstract Factory?

**Abstract Factory** es un patrón de diseño creacional que proporciona una interfaz común para crear familias de productos relacionados sin que el cliente tenga que especificar directamente sus clases concretas.

Sus participantes habituales son:

| Participante | Responsabilidad |
|---|---|
| Fábrica abstracta | Establece las operaciones de creación que las fábricas deben ofrecer. |
| Fábricas concretas | Implementan la creación de una familia determinada de productos. |
| Productos | Son los objetos que se obtienen a través de las fábricas. |
| Cliente | Solicita productos a la fábrica y utiliza los objetos recibidos. |

La diferencia esencial es que **una fábrica concreta representa una familia de productos**, no solamente una instrucción aislada para construir un objeto.

---

## 4. Fábrica abstracta

La práctica incorpora:

```text
FabricaAbstracta.h
FabricaAbstracta.cpp
```

Estos archivos representan la parte común del diseño que permite organizar las fábricas especializadas.

Conceptualmente, una fábrica abstracta establece **qué operaciones de creación deben estar disponibles**. Las fábricas concretas se encargan de dar a esas operaciones el comportamiento correspondiente a su familia.

Esta separación permite explicar dos responsabilidades distintas:

```text
Fábrica abstracta
    → define el contrato común de creación.

Fábrica concreta
    → proporciona la creación de su familia.
```

No se debe confundir la **fábrica** con el **producto**: la primera crea objetos; el segundo es el objeto obtenido.

---

## 5. Fábrica Azul

La primera fábrica concreta añadida se encuentra en:

```text
FabricaAzul.h
FabricaAzul.cpp
```

Su nombre identifica la variante **Azul** dentro de la organización de las fábricas.

En el patrón Abstract Factory, una fábrica concreta tiene la responsabilidad de suministrar productos de su familia según las operaciones definidas por la abstracción común.

El punto importante para la defensa es:

**No es el cliente quien necesita conocer todos los detalles de creación de la familia Azul; esa responsabilidad corresponde a la fábrica.**

---

## 6. Fábrica Roja

La segunda fábrica concreta añadida se encuentra en:

```text
FabricaRoja.h
FabricaRoja.cpp
```

Su nombre identifica la variante **Roja**.

La existencia de dos fábricas concretas permite estudiar cómo se organiza una misma operación de creación para distintas familias de objetos.

Conceptualmente:

```text
Fábrica Abstracta
       |
       +---- Fábrica Azul
       |
       +---- Fábrica Roja
```

La ventaja buscada es poder elegir una familia sin duplicar la lógica de creación en todas las clases que solicitan productos.

---

## 7. Clase PelotaPequena

La práctica también agrega:

```text
PelotaPequena.h
PelotaPequena.cpp
```

Este es uno de los elementos nuevos respecto de la versión anterior de Factory Method.

La separación entre archivos `.h` y `.cpp` mantiene la estructura habitual de C++ en Unreal Engine:

- **`.h`**: declaraciones de clase, atributos y funciones.
- **`.cpp`**: implementación de constructor y funciones.

En la documentación del patrón, es importante distinguir **los archivos de las fábricas** de **los archivos de los productos**. `PelotaPequena` forma parte de los nuevos elementos de producto del proyecto; su relación concreta con cada fábrica depende de las funciones implementadas en el código.

---

## 8. Relación con las plataformas existentes

El proyecto ya utilizaba la clase base:

```cpp
APlataforma
```

y tipos concretos como:

```cpp
APlataformaIndestructible
APlataformaDestructible
```

Estas clases pertenecen al trabajo desarrollado anteriormente sobre plataformas y Factory Method.

La clase base `APlataforma` permite tratar diferentes clases de plataforma mediante un mismo tipo de puntero:

```cpp
APlataforma* PlataformaActual;
```

Esto se relaciona con la **herencia y el polimorfismo** de C++.

La introducción de fábricas concretas no elimina la utilidad de las clases base: al contrario, las abstracciones ayudan a trabajar con productos sin que todas las partes del programa dependan de sus tipos concretos.

---

## 9. Evolución desde Factory Method

### Implementación anterior

En Factory Method se creó una clase específica:

```cpp
AFabricaPlataformas
```

Su método de creación recibía un tipo, una posición y una rotación, y devolvía un puntero a la clase base:

```cpp
APlataforma* CrearPlataforma(
    int Tipo,
    const FVector& Posicion,
    const FRotator& Rotacion
);
```

La implementación anterior decidía entre las plataformas destructibles e indestructibles con una condición sobre `Tipo`.

### Nueva práctica

En Abstract Factory aparecen estas piezas adicionales:

```text
FabricaAbstracta
FabricaAzul
FabricaRoja
PelotaPequena
```

Así, el ejercicio ya no se limita a explicar **un método que decide qué plataforma crear**, sino que introduce el concepto de **fábricas concretas asociadas a diferentes familias**.

**Factory Method** se centra en delegar la creación de un producto.

**Abstract Factory** organiza la creación de familias de productos relacionados mediante una interfaz común.

---

## 10. Flujo conceptual de Abstract Factory

El flujo general del patrón puede representarse de esta forma:

```text
               INICIO DEL JUEGO
                       |
                       v
              CÓDIGO CLIENTE
                       |
                       v
              Selecciona fábrica
                       |
                       v
               FÁBRICA ABSTRACTA
                       |
          +------------+------------+
          |                         |
          v                         v
     FÁBRICA AZUL              FÁBRICA ROJA
          |                         |
          v                         v
  Productos de su familia   Productos de su familia
          |                         |
          +------------+------------+
                       |
                       v
             OBJETOS DEL JUEGO
```

**Nota:** este diagrama describe el diseño del patrón y sus participantes. Las llamadas específicas del proyecto se encuentran en las clases C++ de la implementación.

---

## 11. Integración con GameMode

El proyecto utiliza:

```cpp
AAventuraUSFX022026L4GameMode
```

como punto de entrada de buena parte de la lógica del nivel.

En la implementación anterior de Factory Method, su `BeginPlay()` obtenía el mundo mediante:

```cpp
UWorld* World = GetWorld();
```

y utilizaba `SpawnActor()` para crear la fábrica que gestionaba las plataformas.

El cambio que introduce Abstract Factory debe entenderse dentro de esa misma organización del juego:

```text
GameMode
    → coordina cuándo hacen falta objetos.

Fábricas
    → concentran la responsabilidad de crearlos.

Productos
    → son los objetos utilizados en el nivel.
```

De esta manera se conserva la separación entre **coordinar la partida** y **crear los distintos productos**.

---

## 12. Archivos principales

La estructura de archivos relevantes es:

```text
Source/AventuraUSFX022026L4/
│
├── AventuraUSFX022026L4GameMode.h
├── AventuraUSFX022026L4GameMode.cpp
│
├── FabricaAbstracta.h
├── FabricaAbstracta.cpp
│
├── FabricaAzul.h
├── FabricaAzul.cpp
│
├── FabricaRoja.h
├── FabricaRoja.cpp
│
├── PelotaPequena.h
├── PelotaPequena.cpp
│
├── FabricaPlataformas.h
├── FabricaPlataformas.cpp
│
├── Plataforma.h
├── Plataforma.cpp
│
├── PlataformaIndestructible.h
├── PlataformaIndestructible.cpp
│
├── PlataformaDestructible.h
└── PlataformaDestructible.cpp
```

**Funciones de los grupos de archivos:**

- **`FabricaAbstracta`**: abstracción común del sistema de fábricas.
- **`FabricaAzul` y `FabricaRoja`**: variantes concretas de la fábrica.
- **`PelotaPequena`**: nuevo tipo de objeto incorporado a la práctica.
- **`FabricaPlataformas`**: clase de creación que ya existía en el laboratorio anterior y fue modificada.
- **`Plataforma` y clases hijas**: objetos relacionados con el sistema de plataformas.
- **`GameMode`**: coordinación general del juego.

---

## 13. Comprobación de la implementación

Para verificar el trabajo en Unreal Engine 4.27.2:

1. Abrir `AventuraUSFX022026L4.uproject`.
2. Compilar el proyecto C++ y confirmar que no existan errores.
3. Abrir el nivel configurado para el juego.
4. Presionar **Play**.
5. Comprobar que se crean los objetos esperados mediante la lógica de las fábricas.
6. Revisar el **World Outliner** para identificar los actores generados.
7. Probar la variante **Azul** y la variante **Roja** de acuerdo con las llamadas presentes en el código.
8. Comprobar que los productos corresponden a la fábrica seleccionada y que las clases originales siguen funcionando.

La prueba debe demostrar **la relación entre la fábrica elegida y los productos creados**, no solamente que el proyecto compila.

---

## 14. Conceptos utilizados y relación con los libros

### C++ y Programación Orientada a Objetos

- Clases y objetos.
- Herencia.
- Abstracción.
- Encapsulamiento.
- Polimorfismo.
- Clases base y derivadas.
- Métodos.
- Constructores.
- Punteros.
- Declaraciones en `.h` e implementaciones en `.cpp`.
- Patrones de diseño creacionales.

### Unreal Engine 4.27.2

- `AActor`.
- `AGameModeBase`.
- `UWorld`.
- `GetWorld()`.
- `BeginPlay()`.
- `SpawnActor()`.
- Actores y componentes.
- Clases C++ dentro de un proyecto Unreal.

### Relación con los libros

El patrón **Abstract Factory** pertenece al grupo de **patrones de creación** descrito por Erich Gamma, Richard Helm, Ralph Johnson y John Vlissides en *Patrones de diseño: elementos de software orientado a objetos reutilizable*.

El libro *Sumérgete en los patrones de diseño*, de Alexander Shvets, también explica **Fábrica Abstracta** y su función en la creación de familias de objetos relacionados.

La adaptación a **AventuraUSFX022026L4** traslada estos conceptos teóricos al entorno de C++ y Unreal Engine 4.27.2.

---

## 15. Resultado, tecnologías y repositorio

La práctica amplía la implementación anterior de **Factory Method** mediante una estructura de **Abstract Factory**, incorporando:

```text
FabricaAbstracta
FabricaAzul
FabricaRoja
PelotaPequena
```

Esto permite estudiar la creación de objetos desde el punto de vista de una **abstracción común** y de **fábricas concretas**.

**Tecnologías utilizadas:**

- Unreal Engine 4.27.2.
- C++.
- Visual Studio.
- Git.
- GitHub.

**Repositorio del Grupo 4:**

https://github.com/sebaslopezhurtado15/Lab-G4-PATRONES-Abstract-Factory
