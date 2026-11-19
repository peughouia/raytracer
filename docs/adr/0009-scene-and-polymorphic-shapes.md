# 9. Scene, Polymorphic Shapes, and Material Shading

## Context

Following the client requirements in `docs/discovery/discovery-report.md`, the rendering engine must support multi-object 3D environments containing spheres and planes, illuminated by a directional light source, rendered reliably and deterministically on CPU.

Previously, the prototype rendered a single hardcoded sphere directly within `trace`, tightly coupling ray intersection, geometry, surface appearance, and lighting. To accommodate multiple shapes, floors, and future geometric primitives (such as cylinders or meshes) without rewriting rendering loops, the system requires a clean, extensible domain model adhering to SOLID and Clean Code principles.

We considered alternative designs:
- **Monolithic Shape with Type Tag (Enum/Union):** Storing all shape variants in a single struct or `std::variant` with a type tag and `switch` statements for intersection. *Rejected:* Violates the Open/Closed Principle (OCP); adding a new shape requires modifying existing switch statements and structs.
- **Direct Shading within Shape Intersection:** Having each shape compute its own final pixel color upon hit. *Rejected:* Violates the Single Responsibility Principle (SRP); shapes should only compute geometric intersections, not optical shading or scene lighting.
- **Complex Scene Graph with Acceleration Trees (BVH/KD-tree):** Introducing bounding volume hierarchies or spatial partitioning immediately. *Rejected:* Adds premature complexity before profiling justifies it, violating our simplicity and TDD guidelines.

## Decision

We establish a polymorphic geometry, hit record, material, and scene aggregate architecture:

1. **Abstract Shape Interface (`Shape`):**
   - An abstract base class `Shape` defines a pure virtual method `std::optional<Hit> hit(const Ray& ray) const`.
   - **Contract:** Every shape guarantees returning its nearest intersection in front of the ray origin ($t > 0$) with an outward unit normal vector, or `std::nullopt`.
   - Concrete primitives implement this contract independently:
     - `Sphere`: Solves the quadratic ray-sphere equation, handling rays originating both outside and inside the volume.
     - `Plane`: Solves the linear ray-plane dot product, normalising its normal on construction and rejecting parallel or backward rays.

2. **Hit Record (`Hit`):**
   - A value struct encapsulating intersection details: ray parameter `t` ($t > 0$), 3D intersection point `point`, unit surface normal `normal`, and the surface `Material`.
   - Decouples geometric intersection calculation from scene traversal and shading.

3. **Material and Lambertian Reflection (`Material`):**
   - Each shape owns a `Material`, which is attached to its `Hit`.
   - `Material` encapsulates surface base color and a `shade(normal, toLight)` method implementing Lambert's cosine law: $I = \max(0, \mathbf{n} \cdot \mathbf{l})$.
   - Both `normal` and `toLight` are enforced as normalized unit vectors.

4. **Scene Container (`Scene`):**
   - `Scene` acts as the aggregate root for rendering, owning:
     - A collection of polymorphic shapes via `std::vector<std::unique_ptr<Shape>>`.
     - A normalized directional light vector pointing toward the light source (`_toLight`).
   - Provides `nearestHit(const Ray& ray) const`, which performs a linear search over all shapes and returns the hit with the smallest $t > 0$, or `std::nullopt`.

5. **Decoupled Render Pipeline:**
   - `trace(const Ray& ray, const Scene& scene)` queries `scene.nearestHit(ray)` and shades with `scene.toLight()`, returning black if no object is hit.
   - `Camera::render(const Scene& scene, int width, int height)` generates rays for all image pixels and evaluates `trace()`, fully decoupled from concrete shape types.

## Status

Proposed

## Consequences

- **Open/Closed Principle (OCP):** New geometric shapes (e.g. cylinders, discs) can be added by creating a new `Shape` subclass without modifying `Scene`, `Camera`, `trace`, or existing shapes.
- **Single Responsibility Principle (SRP):** Shapes compute geometry, `Material` computes surface reflectance, `Scene` aggregates objects and lighting, `Camera` generates viewport rays, and `trace` orchestrates ray evaluation.
- **Liskov Substitution Principle (LSP):** `Scene` treats all `Shape` instances uniformly through the virtual `hit()` interface, relying on the common contract ($t > 0$, unit normal).
- **Simple, Deterministic C++:** Memory is cleanly managed via standard smart pointers (`std::unique_ptr`), and missing intersections use `std::optional`.
- **Downsides:**
  - Dynamic dispatch via virtual method calls introduces small vtable overhead per ray test compared to monomorphic calls.
  - Linear $O(N)$ intersection search scales linearly with the number of shapes, which may require spatial acceleration (e.g. BVH) when scenes grow to thousands of primitives.

## What We Deliberately Left Out For Now

1. **Multiple Light Sources & Shadows:**
   - *Why left out:* The studio's current milestone focuses on basic sphere and plane rendering under directional sunlight.
   - *When it becomes worth it:* When shadow rays, point lights, or ambient occlusion are required.
2. **Spatial Acceleration Structures (BVH, KD-Tree):**
   - *Why left out:* Linear search is simple, bug-free, and sufficiently fast for scenes with small numbers of primitives (tens to hundreds).
   - *When it becomes worth it:* When complex polygon meshes or thousands of objects degrade frame render times.
3. **Advanced Optical Materials (Specular, Transparent, Rough):**
   - *Why left out:* Lambertian diffuse reflection meets the client's current visual baseline.
   - *When it becomes worth it:* When reflection, refraction (Fresnel), or PBR microfacet models are introduced.
