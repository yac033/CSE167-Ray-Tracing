# CSE167-Ray-Tracing

Partner 1: Chih-Lin Wang

Partner 2: Yaohui Chen

Topic: Raytracing

**Objective of the project:** Raytracing is a very impressive rendering technique with the goal to achieve photorealism. And the objective of this project is to implement a ray tracing framework so we can use that framework to render our object to achieve photorealism.

Steps:

1. Construct object with triangles
  1. We construct triangles by using the vertex of the geometric, for example a square with vertex A,B,C,D(four corners) containing 2 triangles. The first triangle has 3 corners(A,B and C) the second triangle has the corners(A C and D).
  2. By using this method we can use many triangles to create a complex shape like the teapot.
2. Build triangles soups (which contain all the triangles from all the objects in the scene)
  1. By multiplying the triangles with a corresponding transformation matrix we can transform the triangles into many different shapes. Like the table we transform the unit cube into a table top and table leg.
3. Construct a ray that traverse in the scene dimension
  1. The ray is made out of 2 parts the position where the ray starting from and the direction of the ray ![](RackMultipart20221208-1-zct379_html_70b11e7542c8eab9.png)
4. Check if the ray has any intersection with triangle in the triangle\_soup if there is any retreat to the closest intersection.
  1. The way we check if the ray intersects any triangle is to find the barycentric coordinate representation of the intersect position by using the triangle vertex (which means we need to run the pixel against all the triangle we have in the triangle soup) if barycentric coordinate coefficient (P1, P2 P3 and d) is all positive then intersection is inside the triangle.

![](RackMultipart20221208-1-zct379_html_cc4eb3db5dc6d5b9.png)

1. After retreating the intersection from the closest triangle (If there is any), create a new ray at the position of where the intersection occurs and shoot that ray toward the light position.
2. If the new ray intersects some triangle before it reaches the light that means we know that light is blocked by that triangle(object) and it will create a shadow on that position and we will assign the color of that pixel to the ambient of the object plus the reflection from the new ray multiple with the specular. That will create a more realistic shadow than just set the pixel to black.
3. If the ray is able to reach the light we assign the color of the light on the object. By using Ambient + Lambertian-diffuse + Blinn-Phong formula to calculate the color from the light. ![](RackMultipart20221208-1-zct379_html_c0f1aa83b27ab0c0.png)
4. After that we shoot another ray called reflect\_ray that is at the position where the original ray interests the triangle. That reflect\_ray is going to return another closest intersected triangle and we are going to pass the intersects to repeat step 4 to find the color and multiply with the original triangle's material specular. And add it to the color of the pixel. (Like displaying the reflection on the pixel)

![](RackMultipart20221208-1-zct379_html_f118b84ae1c70e91.png)

1. But If the initial ray didn't intersect any triangle which means that ray has not hit any object and we will set color to the background color.
2. Repeat the step 3 to step 9 for every pixel on the screen. (recursive steps until reach the max bounce MAX\_RECURSION\_DEPTH)
