# Discovery report

## Problem statement

Struggling with poorly documented in-house tools and costly third-party licenses, the Los Angeles animation studio needs a reliable, high-performance, and extensible open-source 3D rendering engine to manage internally, reducing costs, dependencies, and delivery delays.

## Client interview summary

### Raytraces

**Need:** The client requires an open-source visual rendering engine that is reliable, high-performance, and scalable. It must be capable of running on a CPU, producing artifact-free images, and integrating into the studio’s existing workflow. The codebase must be documented, tested, and maintainable by the in-house team, while also allowing partner studios to contribute.

> **Q (Tech-lead):** "Can you tell us about the last time you encountered an issue with your rendering system?"
>
> **A:** "Six months ago, a bug—manifesting as black dots and doubling the render time—could not be resolved internally. This forced the studio to purchase an expensive commercial solution, resulting in a three-week delay on a major production."

> **Q (Tech-lead):** "What essential features do you expect from your new software?"
>
> **A:** "The engine must be scalable to accommodate future productions, with an initial scope focused on rendering spheres and planes."

> **Q (Tech-lead):** "How do your teams currently prepare and launch a render?"
>
> **A:** "Designers create their scenes in third-party software and export files to the rendering engine; no graphical user interface (GUI) is required for the engine itself."

> **Q (Tech-lead):** "What hardware infrastructure do you use, and what are your performance constraints?"
>
> **A:** "Rendering is performed exclusively on CPUs (without a dedicated GPU)—using workstations for previewing and a render farm of up to 100 machines for final output"

> **Q (Tech-lead):** "On what hardware should the engine run (CPU, GPU, render farm)?"
>
> **A:** "CPU"

> **Q (Tech-lead):** "What are the most important criteria for determining whether our solution meets your expectations?"
>
> **A:** "The top priorities are reliability and image reproducibility (including the ability to easily diagnose and correct anomalies), followed by fast execution speeds to ensure designers’ workflows are not hindered.

> **Q (Tech-lead):** "How do you intend to maintain and evolve the software over the long term?
>
> **A:** "The codebase must be clean, well-documented, and maintainable—both internally and by external partners—and accompanied by a user guide designed for artists."

**My conclusion:** "The main challenge is not merely producing 3D images, but ensuring a rendering process that is reliable, reproducible, and fast enough for professional use. Priority must be given to rendering quality, ease of error diagnosis, and maintainability. Furthermore, an extensible, open-source architecture should be designed to accommodate new features without unnecessarily increasing the complexity of the initial version."

### Open questions

- Quel mécanisme est attendu pour permettre aux partenaires d'ajouter leurs propres fonctionnalités ?
- Quels sont les environnements et systèmes d'exploitation à prendre en charge ?
- Quels sont les critères techniques permettant de valider qu'une image est correcte ?
- Quel est le temps maximal acceptable pour une prévisualisation et un rendu final ?

## State of the art

| Solution       | Maker              | Licence                                              | Pricing (date checked)                                                     | Capabilities                                                                                                                              | Sources                                              |
| -------------- | ------------------ | ---------------------------------------------------- | -------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| Blender Cycles | Blender Foundation | Open source : Apache 2.0 for Cycles (Blender is GPL) | Free                                                                       | Path tracing, rendering CPU/GPU, realistic lighting, materials, and 3D object management                                                  | https://www.blender.org/features/rendering/          |
| Arnold         | Autodesk           | Owner, subscription                                  | €444/year (individual user)                                                | Ray tracing Monte-Carlo, rendering CPU/GPU, interactive preview, professional rendering for cinema and animation                          | https://www.autodesk.com/fr/products/arnold/overview |
| RenderMan      | Pixar              | Owner, business license                              | $595 per license + $250/year for maintenance. Free non-commercial version. | Professional-grade film rendering, lighting management, XPU rendering, multi-GPU support, and integration with Maya, Houdini, and Blender | https://www.autodesk.com/fr/products/arnold/overview |

## What is ray tracing?

Ray tracing is a graphical rendering technique that involves simulating the behavior of light within a 3D scene. The engine casts rays from the camera through each pixel of the image to detect any objects they encounter. It then calculates the interactions between light and surfaces—such as shadows, reflections, transparency, and refraction. These calculations determine the final color of each pixel, resulting in the production of realistic images.

**Sources:**

- https://technav.ieee.org/topic/ray-tracing/
- https://raytracing.github.io/

## What is C++?

C++ is a general-purpose, compiled programming language focused on performance. It enables the development of fast applications while offering significant control over memory and hardware resources. It is particularly well-suited for system software, graphics engines, video games, and applications that require intensive computation. It supports multiple programming paradigms and allows for the construction of complex, scalable architectures.

### Programming paradigms

the ways in which code design can be organized
**Procedural programming:** organizing a program into functions that execute instructions in a specific order.

**Object-oriented programming (OOP):** organizing code around classes and objects that group together data and behaviors.

**Functional programming:** using functions, lambda expressions, and algorithms to process data.

### What to watch out for

- Memory management
- Pointers and references
- Object lifetime
- Concurrency
- Numerical precision
- Code quality

### Shaping the domain model

- Contain the objects of the 3D scene.
- Define the viewpoint and generate rays.
- Represent a ray using an origin and a direction.
- Represent a plane and calculate its intersections with a ray.
- Define the visual properties of a surface.
- Contain information regarding a detected intersection.
- Perform scene rendering calculations.
- Store pixels and enable the generation of an image file.

**Sources:** YouTube videos presenting image modeling and ray tracing

- https://raytracing.github.io/
