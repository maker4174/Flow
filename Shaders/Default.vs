#version 330 core

layout (location = 0) in vec2 aPos;

uniform mat3 model;
uniform mat4 view;
uniform mat4 projection;

mat4 model4 =  mat4( vec4(model[0], 0.0), vec4(model[1], 0.0),
  vec4(0.0, 0.0, 1.0, 0.0), vec4(model[2], 1.0) );

void main() {


    gl_Position = projection * view * model4 * vec4(aPos, 0.0, 1.0);
}
