uniform float opacity;
uniform sampler2D texture;

void main(void)
{
    vec4 color = texture2D(texture, gl_TexCoord[0].xy);
    color.a += 0.1f;
    gl_FragColor = color;
}