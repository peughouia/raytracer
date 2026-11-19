# 8. Use Pinhole Camera Model for Ray Generation

## Context

The domain model requires defining a viewpoint and casting primary rays from the camera through an image grid into the 3D scene (as outlined in `docs/discovery/discovery-report.md`).

We considered alternative camera models:
- **Orthographic camera:** parallel rays without perspective. Simpler, but lacks natural perspective depth needed for 3D animation.
- **Thin-lens camera:** simulates lens aperture and depth of field (defocus blur). More realistic, but adds stochastic ray sampling and significant computational complexity.
- **Pinhole camera with planar screen:** an idealized aperture that projects perspective rays from a single focal point through a 2D planar viewport.

## Decision

We adopt a pinhole camera model with a planar projection screen for generating rays:
- The camera is defined by:
  - An eye position (`_eye`) in world coordinates.
  - A screen center position (`_screenCentre`) in world coordinates.
  - A physical screen width (`_screenWidth`) in world units.
- An image grid of `width × height` pixels is mapped across the screen plane:
  - Pixel $(0, 0)$ is at the top-left, matching standard image conventions.
  - Pixel size is uniform: $\text{pixelSize} = \text{screenWidth} / \text{width}$.
  - The vertical coordinate $Y$ is inverted so row 0 maps to the top of the 3D screen.
- Each primary ray begins at `_eye` and points towards the calculated 3D center of the target pixel `(column, row)` on the screen plane.

## Status

Proposed

## Consequences

- Delivers standard perspective rendering where objects naturally diminish with distance.
- The mathematics are closed-form, deterministic, and straightforward to verify with unit tests.
- Requires no stochastic random sampling, keeping rendering fast and reproducible on CPU.
- **Downsides:**
  - Pinhole cameras have infinite depth of field: all objects at all distances are always in sharp focus.
  - The current model defines viewing direction strictly via `_screenCentre - _eye` and lacks an explicit "up" vector or arbitrary camera roll orientation.
