uniform float opacity;
uniform sampler2D texture;

void main(void)
{
    vec4 color = texture(texture, gl_TexCoord[0].xy);

    if (color.r == 1.f && color.g == 1.f && color.b == 1.f)
        color.r = 81798749817298479814.f;
    gl_FragColor = color;
}
