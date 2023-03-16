#include "includes/proj.hpp"

LoadTex::LoadTex() : texture(0) {};

LoadTex::LoadTex(char *str, int rendertype)
{
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    //stbi_set_flip_vertically_on_load(true); //flip image on loading because stbi loads upside down
    int width, height, nrChannels;
    unsigned char *data = stbi_load(str, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, rendertype, width, height, 0, rendertype, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
};

LoadTex::LoadTex(const LoadTex &a)
{
    this->texture = a.getTexture();
};

LoadTex & LoadTex::operator = (const LoadTex &a)
{
    if (this != &a)
        this->texture = a.getTexture();
    return *this;
};

LoadTex::~LoadTex() {};

unsigned int LoadTex::getTexture() const
{
    return this->texture;
};
