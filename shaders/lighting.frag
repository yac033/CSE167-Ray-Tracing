#version 330 core
in vec4 position; // raw position in the model coord
in vec3 normal;   // raw normal in the model coord

uniform mat4 modelview; // from model coord to eye coord
uniform mat4 view;      // from world coord to eye coord

// Material parameters
uniform vec4 ambient;
uniform vec4 diffuse;
uniform vec4 specular;
uniform vec4 emision;
uniform float shininess;

// Light source parameters
const int maximal_allowed_lights = 10;
uniform bool enablelighting;
uniform int nlights;
uniform vec4 lightpositions[ maximal_allowed_lights ];
uniform vec4 lightcolors[ maximal_allowed_lights ];

// Output the frag color
out vec4 fragColor;


void main (void){
    if (!enablelighting){
        // Default normal coloring (you don't need to modify anything here)
        vec3 N = normalize(normal);
        fragColor = vec4(0.5f*N + 0.5f , 1.0f);
    } else {
        // HW3: You will compute the lighting here.
        vec4 PositionIneye = modelview * position;
        mat3 Top3M;
        Top3M[0][0] = modelview[0][0]; Top3M[1][0] = modelview[1][0]; Top3M[2][0] = modelview[2][0]; Top3M[0][1] = modelview[0][1]; Top3M[1][1] = modelview[1][1]; Top3M[2][1] = modelview[2][1]; Top3M[0][2] = modelview[0][2]; Top3M[1][2] = modelview[1][2]; Top3M[2][2] = modelview[2][2];
        Top3M = inverse(Top3M);
        Top3M = transpose(Top3M);
        vec3 NormalIneye = normalize(Top3M*normal);
        vec3 eye = vec3(0,0,0);
        vec3 v = normalize(eye - vec3(PositionIneye));
        vec4 lp;
        vec3 l_j;
        vec3 h_j;
        vec4 R = vec4(0.0f,0.0f,0.0f,0.0f);
        for(int i = 0; i < nlights; i++){
            vec4 lightPos = view * lightpositions[i];
            vec4 copy_PositionIneye = PositionIneye;
            copy_PositionIneye.x = lightPos.w * copy_PositionIneye.x;
            copy_PositionIneye.y = lightPos.w * copy_PositionIneye.y;
            copy_PositionIneye.z = lightPos.w * copy_PositionIneye.z;
            lightPos.x = copy_PositionIneye.w * lightPos.x;
            lightPos.y = copy_PositionIneye.w * lightPos.y;
            lightPos.z = copy_PositionIneye.w * lightPos.z;
            l_j = normalize(vec3(lightPos - copy_PositionIneye));
            h_j = normalize(v + l_j);

            R = R + (lightcolors[i] * (ambient + (diffuse * max(dot(NormalIneye,l_j),0)) + (specular * pow(max(dot(NormalIneye,h_j),0),shininess))));
        }
        fragColor = emision + R;
    }   
}
